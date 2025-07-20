/*
 * label_cache.c - Stub kernel module for label cache
 */
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

static struct proc_dir_entry *commi_dir;
static struct proc_dir_entry *last_label_file;
static char last_label[32] = "none";

static int last_label_show(struct seq_file *m, void *v)
{
    seq_printf(m, "%s\n", last_label);
    return 0;
}

static int last_label_open(struct inode *inode, struct file *file)
{
    return single_open(file, last_label_show, NULL);
}

static const struct file_operations last_label_fops = {
    .owner = THIS_MODULE,
    .open = last_label_open,
    .read = seq_read,
    .llseek = seq_lseek,
    .release = single_release,
};

int init_module(void)
{
    commi_dir = proc_mkdir("commi", NULL);
    if (!commi_dir)
        return -ENOMEM;

    last_label_file = proc_create("last_label", 0444, commi_dir,
                                  &last_label_fops);
    if (!last_label_file) {
        remove_proc_entry("commi", NULL);
        return -ENOMEM;
    }

    pr_info("label_cache loaded\n");
    return 0;
}

void cleanup_module(void)
{
    if (last_label_file)
        remove_proc_entry("last_label", commi_dir);
    if (commi_dir)
        remove_proc_entry("commi", NULL);
    pr_info("label_cache unloaded\n");
}

MODULE_LICENSE("GPL");
