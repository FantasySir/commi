/*
 * slab_subcache.c - Stub kernel module for slab subcaches
 */
#include "slab_subcache.h"
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>

static struct proc_dir_entry *commi_dir;
static struct proc_dir_entry *new_container_file;
static char last_container[32];

static ssize_t new_container_write(struct file *file, const char __user *buf,
                                   size_t count, loff_t *ppos)
{
    size_t len = min(count, sizeof(last_container) - 1);

    if (copy_from_user(last_container, buf, len))
        return -EFAULT;

    last_container[len] = '\0';
    pr_info("slab_subcache: new container %s\n", last_container);
    return count;
}

static const struct file_operations new_container_fops = {
    .owner = THIS_MODULE,
    .write = new_container_write,
};

int init_module(void)
{
    commi_dir = proc_mkdir("commi", NULL);
    if (!commi_dir)
        return -ENOMEM;

    new_container_file = proc_create("new_container", 0222, commi_dir,
                                     &new_container_fops);
    if (!new_container_file) {
        remove_proc_entry("commi", NULL);
        return -ENOMEM;
    }

    pr_info("slab_subcache loaded\n");
    return 0;
}

void cleanup_module(void)
{
    if (new_container_file)
        remove_proc_entry("new_container", commi_dir);
    if (commi_dir)
        remove_proc_entry("commi", NULL);
    pr_info("slab_subcache unloaded\n");
}

MODULE_LICENSE("GPL");
