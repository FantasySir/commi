BPF_CLANG ?= clang
BPF_CFLAGS := -O2 -target bpf

all: lsm kfunc

lsm: lsm/commi_lsm.bpf.o
kfunc: kfunc/commi_kfunc.bpf.o

%.bpf.o: %.bpf.c
$(BPF_CLANG) $(BPF_CFLAGS) -c $< -o $@

clean:
rm -f lsm/*.o kfunc/*.o
