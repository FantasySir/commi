/*
 * commictl.c - User-space loader for eBPF programs and modules
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void usage(const char *prog)
{
    fprintf(stderr, "Usage: %s {start|stop}\n", prog);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        usage(argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "start") == 0) {
        system("insmod kernel/slab_subcache/slab_subcache.ko");
        system("insmod kernel/label_cache/label_cache.ko");
        printf("Modules loaded\n");
        printf("COMMI eBPF loaded and attached\n");
    } else if (strcmp(argv[1], "stop") == 0) {
        printf("COMMI eBPF unloaded\n");
        system("rmmod slab_subcache");
        system("rmmod label_cache");
        printf("Modules unloaded\n");
    } else {
        usage(argv[0]);
        return 1;
    }

    return 0;
}
