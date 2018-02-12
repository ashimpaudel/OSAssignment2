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
		
		printk("%s[%d]\n", task->comm, task->pid);
        printAnecstors(task
		struct task_struct *my_parent = task->parent;
		printk("Parent task of main Task %s (pid = %d)\n",my_parent->comm, my_parent->pid);
	
	}
	printk(KERN_INFO "Loading Module\n");
	return 0;
}


bool printAncestors(struct task_struct *root, int target)
{
  /* base cases */
  if (root == NULL)
     return false;
 
  if (root->pid == target)
     return true;
 
  /* If target is present in either l*/
  for_eah_process(task)
  {
    if(printAncestors(task->children, int(pid)){
        printk("ancestor process %s[%d]\n", task->comm, task->pid);;
        return true;
    }
  }
 
  /* Else return false */
  return false;
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

