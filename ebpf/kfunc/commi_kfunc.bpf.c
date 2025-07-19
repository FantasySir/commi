/*
 * commi_kfunc.bpf.c - eBPF program hooking kernel functions
 */
#include <linux/bpf.h>

SEC("kprobe/slab_alloc_node")
int BPF_KPROBE(commi_slab_alloc) {
    /* Stub implementation */
    return 0;
}

char _license[] SEC("license") = "GPL";
