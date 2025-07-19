.PHONY: all clean ebpf kernel user

all: ebpf kernel user

ebpf:
$(MAKE) -C ebpf

kernel:
$(MAKE) -C kernel

user:
$(MAKE) -C user

clean:
$(MAKE) -C ebpf clean
$(MAKE) -C kernel clean
$(MAKE) -C user clean
