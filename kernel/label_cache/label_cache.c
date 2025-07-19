/*
 * label_cache.c - Stub kernel module for label cache
 */
#include <linux/module.h>

int init_module(void)
{
    pr_info("label_cache loaded\n");
    return 0;
}

void cleanup_module(void)
{
    pr_info("label_cache unloaded\n");
}

MODULE_LICENSE("GPL");
