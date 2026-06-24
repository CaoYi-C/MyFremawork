using System;
using System.Collections.Generic;

namespace Game.Character.Skills
{
    /// <summary>
    /// 技能容器：管理一组 ISkill，对外提供注册/查询/激活/Tick。
    /// 由 CharacterController2D 持有，每帧由控制器驱动 Tick。
    /// </summary>
    public sealed class SkillSystem
    {
        private readonly Dictionary<string, ISkill> _skills = new Dictionary<string, ISkill>();
        private SkillContext _context;

        /// <summary>当某个技能冷却状态发生变化时触发（用于 UI 监听）</summary>
        public event Action<ISkill> OnSkillChanged;

        /// <summary>所有技能列表</summary>
        public IReadOnlyCollection<ISkill> Skills => _skills.Values;

        public void Bind(SkillContext context)
        {
            _context = context;
            foreach (var kv in _skills)
            {
                kv.Value.Initialize(context);
            }
        }

        public void Unbind()
        {
            _context = null;
            // 保留注册，切换角色时不需要重新注册
        }

        public void RegisterSkill(ISkill skill)
        {
            if (skill == null) throw new ArgumentNullException(nameof(skill));
            if (_skills.ContainsKey(skill.Id))
                throw new InvalidOperationException($"Skill id '{skill.Id}' already registered.");

            _skills.Add(skill.Id, skill);
            if (_context != null) skill.Initialize(_context);
            OnSkillChanged?.Invoke(skill);
        }

        public void UnregisterSkill(string id)
        {
            if (_skills.TryGetValue(id, out var skill))
            {
                _skills.Remove(id);
                OnSkillChanged?.Invoke(skill);
            }
        }

        public ISkill GetSkill(string id)
        {
            _skills.TryGetValue(id, out var s);
            return s;
        }

        public bool TryActivate(string id)
        {
            var skill = GetSkill(id);
            if (skill == null) return false;

            bool triggered = skill.TryActivate();
            if (triggered) OnSkillChanged?.Invoke(skill);
            return triggered;
        }

        public void Tick(float fixedDeltaTime)
        {
            // 复制 KeyValuePair 防止遍历中修改
            foreach (var kv in _skills)
            {
                kv.Value.Tick(fixedDeltaTime);
            }
        }

        /// <summary>强制通知 UI 刷新全部技能状态（首次注册后调用）</summary>
        public void RaiseAllChanged()
        {
            foreach (var skill in _skills.Values)
            {
                OnSkillChanged?.Invoke(skill);
            }
        }
    }
}