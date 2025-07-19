/*
 * commi_lsm.bpf.c - eBPF LSM hooks for credential checks
 */
#include <linux/bpf.h>

SEC("lsm")
int BPF_PROG(commi_task_create, struct task_struct *task) {
    /* Stub implementation */
    return 0;
}

char _license[] SEC("license") = "GPL";
