/*
 * commi_lsm.bpf.c - eBPF LSM hooks for credential checks
 */
#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

struct task_info {
    u32 pid;
    char comm[16];
};

struct {
    __uint(type, BPF_MAP_TYPE_PERF_EVENT_ARRAY);
} task_events SEC(".maps");

SEC("lsm/task_alloc")
int BPF_PROG(commi_task_create, struct task_struct *task, unsigned long clone_flags)
{
    struct task_info event = {};

    event.pid = bpf_get_current_pid_tgid() >> 32;
    bpf_get_current_comm(&event.comm, sizeof(event.comm));

    bpf_perf_event_output(task, &task_events, BPF_F_CURRENT_CPU,
                          &event, sizeof(event));
    bpf_printk("task_alloc pid=%d comm=%s\n", event.pid, event.comm);

    return 0;
}

char _license[] SEC("license") = "GPL";
