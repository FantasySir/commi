/*
 * commi_kfunc.bpf.c - eBPF program hooking kernel functions
 */
#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 1024);
    __type(key, u32);
    __type(value, u64);
} alloc_size SEC(".maps");

SEC("kprobe/slab_alloc_node")
int BPF_KPROBE(commi_slab_alloc, struct kmem_cache *s, gfp_t flags,
               int node, size_t size)
{
    u32 pid = bpf_get_current_pid_tgid() >> 32;
    u64 sz = size;

    bpf_map_update_elem(&alloc_size, &pid, &sz, BPF_ANY);
    bpf_printk("slab_alloc_node pid=%d size=%llu\n", pid, sz);

    return 0;
}

char _license[] SEC("license") = "GPL";
