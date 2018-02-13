#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
/* This function is called when the module is loaded. */
int simple_init(void)
{

	struct task_struct *task;
	for_each_process(task)
	{
	/* on each iteration task points to the next task */
	//for each task we have to print the task name, parent task info and grand parent info and so on
	// we obtain this by looping over the current process, going each level up of the tree till we hit null
	// the main task to figure out here is which process to halt when
	// each task_struct has struct *next_task, *prev_task;

		printk("parent process: %s, %d\n", task->comm, task->pid);
		struct task_struct *paren;
		paren = task->real_parent;
		while(paren->pid != 1){
			printk("Ancestor process: %s, %d\n", paren->comm, paren->pid);
			paren = paren->real_parent;
		}
		printk("\n\n");
         }
	return 0;
}
/* This function is called when the module is removed. */
void simple_exit(void)
{
	printk(KERN_INFO "Removing Module\n");
}
/* Macros for registering module entry and exit points. */
module_init(simple_init);
module_exit(simple_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

