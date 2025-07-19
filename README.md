# COMMI

COMMI is a sample framework demonstrating container isolation mechanisms using eBPF and
optional kernel modules. The project is structured to build eBPF programs,
loadable kernel modules, and user-space control utilities.

## 目录结构 (Directory Layout)

- `ebpf/` - eBPF programs for security hooks and kernel tracing.
- `kernel/` - Optional kernel modules used by the project.
- `user/` - User-space controller for loading eBPF programs and managing modules.
- `tests/` - Example exploits and runtime test scripts.

本仓库目前仅提供代码框架，具体实现留待完善。
