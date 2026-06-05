// PythonRunner.cs
// Synchronously invoke the Python `psd_to_json.py` script from Unity
// Editor and capture stdout/stderr/exit code.
//
// Why sync: the importer needs the JSON file on disk before it can run.
// An async coroutine would force the window to track multiple in-flight
// imports, which is overkill for the v1 workflow (one PSD at a time).

using System;
using System.Diagnostics;
using System.IO;
using System.Text;
using Debug = UnityEngine.Debug;

namespace PSDImporter.Editor
{
    public static class PythonRunner
    {
        public class RunResult
        {
            public int    exitCode;
            public string stdout;
            public string stderr;
            public TimeSpan duration;

            public bool ok => exitCode == 0;
        }

        /// <summary>
        /// Run `python scriptPath arg1 arg2 ...` synchronously.
        /// Pass an empty `scriptPath` to run the python executable directly
        /// (e.g. for `python --version`).
        /// </summary>
        /// <param name="pythonExe">Path to python.exe (or just "python").</param>
        /// <param name="scriptPath">Absolute path to the .py file, or empty.</param>
        /// <param name="args">Command-line args (each is passed as a single token, with quoting).</param>
        /// <param name="workDir">Working directory for the subprocess (default: script's dir, or project root if no script).</param>
        public static RunResult Run(
            string pythonExe,
            string scriptPath,
            string[] args,
            string workDir = null)
        {
            var result = new RunResult();
            var sw = Stopwatch.StartNew();

            if (string.IsNullOrEmpty(pythonExe))
                pythonExe = "python";
            if (!string.IsNullOrEmpty(scriptPath) && !File.Exists(scriptPath))
            {
                result.exitCode = -1;
                result.stderr   = $"Script not found: {scriptPath}";
                return result;
            }

            var psi = new ProcessStartInfo
            {
                FileName               = pythonExe,
                UseShellExecute        = false,
                CreateNoWindow         = true,
                RedirectStandardOutput = true,
                RedirectStandardError  = true,
                RedirectStandardInput  = true,           // avoid Python waiting for stdin
                WorkingDirectory       = workDir
                                         ?? (string.IsNullOrEmpty(scriptPath)
                                             ? ""
                                             : Path.GetDirectoryName(scriptPath) ?? ""),
                StandardOutputEncoding = Encoding.UTF8,
                StandardErrorEncoding  = Encoding.UTF8,
            };

            // Manually compose the command line. .NET's ArgumentList builder
            // would also work, but is .NET 5+ only. Unity 2022 uses .NET
            // Standard 2.1, so we still need to quote ourselves.
            //
            // IMPORTANT: psi.Arguments is the args for the executable
            // (psi.FileName). The executable name itself goes in FileName.
            // We must NOT put pythonExe in Arguments — that would mean
            // we're asking Python to run a file called "python".
            var cmd = "";
            if (!string.IsNullOrEmpty(scriptPath))
                cmd += QuoteArg(scriptPath);
            if (args != null)
                foreach (var a in args)
                    cmd += (cmd.Length == 0 ? "" : " ") + QuoteArg(a);
            psi.Arguments = cmd;

            // Mark the assembly version so we can verify the new code is loaded.
            Debug.Log($"[PSDImporter/PythonRunner] v=FIXED-2026-06-05 cmd=`<{psi.FileName}> {cmd}` workdir=`{psi.WorkingDirectory}`");

            var stdout = new StringBuilder();
            var stderr = new StringBuilder();

            try
            {
                using (var p = Process.Start(psi))
                {
                    p.OutputDataReceived += (s, e) => { if (e.Data != null) stdout.AppendLine(e.Data); };
                    p.ErrorDataReceived  += (s, e) => { if (e.Data != null) stderr.AppendLine(e.Data); };
                    p.BeginOutputReadLine();
                    p.BeginErrorReadLine();
                    p.WaitForExit();
                    result.exitCode = p.ExitCode;
                }
            }
            catch (Exception e)
            {
                result.exitCode = -1;
                result.stderr   = $"Failed to start Python: {e.Message}\n\n" +
                                  "Is the python executable path correct?\n" +
                                  "Settings → pythonExecutable\n" +
                                  $"(looked for: {pythonExe})";
            }
            sw.Stop();
            result.duration = sw.Elapsed;
            result.stdout   = stdout.ToString();
            result.stderr   = stderr.ToString();

            if (!result.ok && string.IsNullOrEmpty(result.stderr))
            {
                // Sometimes the error message ends up on stdout. Surface both.
                result.stderr = result.stdout;
            }
            return result;
        }

        // Quote a single command-line argument. Wraps in double quotes if
        // the arg contains spaces or quotes; escapes embedded quotes.
        private static string QuoteArg(string s)
        {
            if (s == null) return "\"\"";
            if (s.Length == 0) return "\"\"";
            if (s.IndexOfAny(new[] { ' ', '\t', '"', '\\' }) < 0)
                return s;
            var sb = new StringBuilder("\"");
            int backslashes = 0;
            foreach (var c in s)
            {
                if (c == '\\')
                {
                    backslashes++;
                    sb.Append('\\');
                }
                else if (c == '"')
                {
                    sb.Append('\\', backslashes * 2 + 1);
                    sb.Append('"');
                    backslashes = 0;
                }
                else
                {
                    sb.Append(c);
                    backslashes = 0;
                }
            }
            sb.Append('\\', backslashes * 2);
            sb.Append('"');
            return sb.ToString();
        }
    }
}
