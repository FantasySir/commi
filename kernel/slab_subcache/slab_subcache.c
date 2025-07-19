/*
 * slab_subcache.c - Stub kernel module for slab subcaches
 */
#include "slab_subcache.h"
#include <linux/module.h>

int init_module(void)
{
    pr_info("slab_subcache loaded\n");
    return 0;
}

void cleanup_module(void)
{
    pr_info("slab_subcache unloaded\n");
}

MODULE_LICENSE("GPL");
