CC ?= gcc
CFLAGS := -O2

all: commictl

commictl: commictl.c
$(CC) $(CFLAGS) -o $@ $<

clean:
rm -f commictl
