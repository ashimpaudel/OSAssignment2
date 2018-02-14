#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
/* This function is called when the module is loaded. */
int simple_init(void)
{

	struct task_struct *task;
	struct task_struct *paren;
	int pos_ancestor;
	for_each_process(task)
	{
	/* on each iteration task points to the next task */
	//for each task we have to print the task name, parent task info and grand parent info and so on
	// we obtain this by looping over the current process, going each level up of the tree till we hit null
	// the main task to figure out here is which process to halt when
	// each task_struct has struct *next_task, *prev_task;

		printk("parent process: name-> %s, pid->  %d, state-> %ld\n", task->comm, task->pid, task->state);
		
		paren = task->real_parent;
		pos_ancestor = 1;
		while(paren->pid != 0){
			if (pos_ancestor == 1){
				printk("Father process: name-> %s, pid->  %d, state-> %ld\n", paren->comm, paren->pid, paren->state);
				paren = paren->real_parent;
				pos_ancestor++;
			}
			else if (pos_ancestor ==2){
				printk("Grand father process: name-> %s, pid->  %d, state-> %ld\n", paren->comm, paren->pid, paren->state);
                                paren = paren->real_parent;
                                pos_ancestor++;
                        }
			else{
				printk("Ancestor process: name-> %s, pid->  %d, state-> %ld\n", paren->comm, paren->pid, paren->state);
                                paren = paren->real_parent;
                                pos_ancestor++;
                        }


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
MODULE_DESCRIPTION("");
MODULE_AUTHOR("Ashim");

