using System;
using System.Collections.Generic;
using System.IO;
using System.Security.Cryptography;
using System.Text;
using Fuel.Singleton;
using UnityEngine;

namespace Fuel.LocalData
{
    public enum LocalDataStorageType
    {
        PlayerPrefs,
        JsonFile,
        BinaryFile
    }

    public interface ILocalDataStorage
    {
        void SaveString(string key, string value);
        bool TryLoadString(string key, out string value);
        void Delete(string key);
        bool HasKey(string key);
    }

    public sealed class LocalDataManager : Singleton<LocalDataManager>
    {
        private readonly PlayerPrefsLocalDataStorage _playerPrefsStorage = new PlayerPrefsLocalDataStorage();
        private readonly JsonFileLocalDataStorage _jsonFileStorage = new JsonFileLocalDataStorage();
        private readonly BinaryFileLocalDataStorage _binaryFileStorage = new BinaryFileLocalDataStorage();

        public LocalDataStorageType StorageType { get; private set; } = LocalDataStorageType.JsonFile;
        public bool EncryptionEnabled { get; private set; }
        public string EncryptionKey { get; private set; } = "FuelLocalData";

        // 脏标记批量保存机制：减少高频 Save 时的序列化/加密/IO 开销
        private readonly Dictionary<string, string> _pendingSaves = new Dictionary<string, string>();
        private bool _hasPendingSaves;

        public void SetStorageType(LocalDataStorageType storageType)
        {
            StorageType = storageType;
        }

        public void SetEncryption(bool enabled, string key = null)
        {
            EncryptionEnabled = enabled;
            if (!string.IsNullOrEmpty(key))
            {
                EncryptionKey = key;
            }
        }

        public void Save<T>(string key, T data)
        {
            // JsonUtility 要求包装类型（裸 T 不行）。为了避免每次 Save 都 box 一个 LocalDataWrapper<T>，
            // 按 T 类型缓存一份 boxed wrapper 实例，反复写入 data 字段。
            var wrapper = LocalDataWrapperCache<T>.Acquire(data);
            SaveString(key, JsonUtility.ToJson(wrapper));
        }

        public bool TryLoad<T>(string key, out T data)
        {
            if (TryLoadString(key, out var json))
            {
                var wrapper = JsonUtility.FromJson<LocalDataWrapper<T>>(json);
                data = wrapper.data;
                return true;
            }

            data = default;
            return false;
        }

        public void SaveString(string key, string value)
        {
            GetStorage(StorageType).SaveString(key, EncodeValue(value));
        }

        /// <summary>
        /// 延迟保存 — 将数据标记为待保存，不立即执行 IO
        /// 调用 FlushPendingSaves() 批量写入
        /// </summary>
        public void SaveDeferred<T>(string key, T data)
        {
            var wrapper = LocalDataWrapperCache<T>.Acquire(data);
            string json = JsonUtility.ToJson(wrapper);
            string encoded = EncodeValue(json);
            _pendingSaves[key] = encoded;
            _hasPendingSaves = true;
        }

        /// <summary>
        /// 延迟保存字符串
        /// </summary>
        public void SaveStringDeferred(string key, string value)
        {
            _pendingSaves[key] = EncodeValue(value);
            _hasPendingSaves = true;
        }

        /// <summary>
        /// 批量刷新所有待保存的数据到存储
        /// 适合在帧末尾、场景切换、应用暂停时调用
        /// </summary>
        public void FlushPendingSaves()
        {
            if (!_hasPendingSaves) return;

            var storage = GetStorage(StorageType);
            foreach (var kvp in _pendingSaves)
            {
                storage.SaveString(kvp.Key, kvp.Value);
            }
            _pendingSaves.Clear();
            _hasPendingSaves = false;
        }

        /// <summary>
        /// 是否有待刷新的延迟保存数据
        /// </summary>
        public bool HasPendingSaves => _hasPendingSaves;

        public bool TryLoadString(string key, out string value)
        {
            if (GetStorage(StorageType).TryLoadString(key, out var storedValue))
            {
                value = DecodeValue(storedValue);
                return true;
            }

            value = null;
            return false;
        }

        public void Delete(string key)
        {
            _pendingSaves.Remove(key);
            GetStorage(StorageType).Delete(key);
        }

        public bool HasKey(string key)
        {
            return GetStorage(StorageType).HasKey(key);
        }

        public ILocalDataStorage GetStorage(LocalDataStorageType storageType)
        {
            switch (storageType)
            {
                case LocalDataStorageType.PlayerPrefs:
                    return _playerPrefsStorage;
                case LocalDataStorageType.JsonFile:
                    return _jsonFileStorage;
                case LocalDataStorageType.BinaryFile:
                    return _binaryFileStorage;
                default:
                    return _jsonFileStorage;
            }
        }

        private string EncodeValue(string value)
        {
            return EncryptionEnabled ? XorObfuscator.Encode(value, EncryptionKey) : value;
        }

        private string DecodeValue(string value)
        {
            return EncryptionEnabled ? XorObfuscator.Decode(value, EncryptionKey) : value;
        }

        protected override void Init()
        {
            Application.quitting += FlushPendingSaves;
        }

        [Serializable]
        private class LocalDataWrapper<T>
        {
            public T data;
        }

        /// <summary>
        /// 按 T 类型缓存一份 wrapper 实例 + 强类型字段，避免每次 Save 都 new + box。
        /// 主线程单例使用，无需锁。
        /// </summary>
        private static class LocalDataWrapperCache<T>
        {
            private static readonly LocalDataWrapper<T> _instance = new LocalDataWrapper<T>();

            public static LocalDataWrapper<T> Acquire(T data)
            {
                _instance.data = data;
                return _instance;
            }
        }
    }

    public static class XorObfuscator
    {
        // 缓存上次使用的 key 和对应字节，避免每次 Encode/Decode 都 GetBytes
        private static string _cachedKey;
        private static byte[] _cachedKeyBytes;

        public static string Encode(string value, string key)
        {
            if (string.IsNullOrEmpty(value))
            {
                return value;
            }

            var bytes = Encoding.UTF8.GetBytes(value);
            Apply(bytes, key);
            return Convert.ToBase64String(bytes);
        }

        public static string Decode(string value, string key)
        {
            if (string.IsNullOrEmpty(value))
            {
                return value;
            }

            var bytes = Convert.FromBase64String(value);
            Apply(bytes, key);
            return Encoding.UTF8.GetString(bytes);
        }

        private static void Apply(byte[] bytes, string key)
        {
            byte[] keyBytes = GetKeyBytes(key);
            for (int i = 0; i < bytes.Length; i++)
            {
                bytes[i] = (byte)(bytes[i] ^ keyBytes[i % keyBytes.Length]);
            }
        }

        private static byte[] GetKeyBytes(string key)
        {
            string effectiveKey = string.IsNullOrEmpty(key) ? "FuelLocalData" : key;
            if (_cachedKey != effectiveKey)
            {
                _cachedKey = effectiveKey;
                _cachedKeyBytes = Encoding.UTF8.GetBytes(effectiveKey);
            }
            return _cachedKeyBytes;
        }
    }

    public sealed class PlayerPrefsLocalDataStorage : ILocalDataStorage
    {
        public void SaveString(string key, string value)
        {
            PlayerPrefs.SetString(key, value);
            PlayerPrefs.Save();
        }

        public bool TryLoadString(string key, out string value)
        {
            if (PlayerPrefs.HasKey(key))
            {
                value = PlayerPrefs.GetString(key);
                return true;
            }

            value = null;
            return false;
        }

        public void Delete(string key)
        {
            PlayerPrefs.DeleteKey(key);
            PlayerPrefs.Save();
        }

        public bool HasKey(string key)
        {
            return PlayerPrefs.HasKey(key);
        }
    }

    public abstract class FileLocalDataStorage : ILocalDataStorage
    {
        private readonly string _extension;
        private readonly string _directory;

        protected FileLocalDataStorage(string extension)
        {
            _extension = extension;
            _directory = Path.Combine(Application.persistentDataPath, "LocalData");
        }

        public void SaveString(string key, string value)
        {
            if (!Directory.Exists(_directory))
            {
                Directory.CreateDirectory(_directory);
            }

            File.WriteAllBytes(GetFilePath(key), Encode(value));
        }

        public bool TryLoadString(string key, out string value)
        {
            var path = GetFilePath(key);
            if (File.Exists(path))
            {
                value = Decode(File.ReadAllBytes(path));
                return true;
            }

            value = null;
            return false;
        }

        public void Delete(string key)
        {
            var path = GetFilePath(key);
            if (File.Exists(path))
            {
                File.Delete(path);
            }
        }

        public bool HasKey(string key)
        {
            return File.Exists(GetFilePath(key));
        }

        protected abstract byte[] Encode(string value);
        protected abstract string Decode(byte[] bytes);

        private string GetFilePath(string key)
        {
            return Path.Combine(_directory, GetSafeFileName(key) + _extension);
        }

        private static string GetSafeFileName(string key)
        {
            using var sha256 = SHA256.Create();
            byte[] hash = sha256.ComputeHash(Encoding.UTF8.GetBytes(key));
            return Convert.ToBase64String(hash).Replace('/', '_').Replace('+', '-').TrimEnd('=');
        }
    }

    public sealed class JsonFileLocalDataStorage : FileLocalDataStorage
    {
        public JsonFileLocalDataStorage() : base(".json")
        {
        }

        protected override byte[] Encode(string value)
        {
            return Encoding.UTF8.GetBytes(value);
        }

        protected override string Decode(byte[] bytes)
        {
            return Encoding.UTF8.GetString(bytes);
        }
    }

    public sealed class BinaryFileLocalDataStorage : FileLocalDataStorage
    {
        public BinaryFileLocalDataStorage() : base(".bytes")
        {
        }

        protected override byte[] Encode(string value)
        {
            return Encoding.UTF8.GetBytes(value);
        }

        protected override string Decode(byte[] bytes)
        {
            return Encoding.UTF8.GetString(bytes);
        }
    }
}
