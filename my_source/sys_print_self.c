#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/module.h>


SYSCALL_DEFINE0(print_self)
{
	struct task_struct *Pointer;
	
	printk(KERN_ALERT "PROCESS NAME: %s\n", current->comm);
	printk(KERN_EMERG "PROCESS ID/PID: %d\n", current->pid);
	printk(KERN_EMERG "RUNNING STATE: ");
	
	switch(current->state)
	{
		case -1:
			printk("unrunnable\n");
			break;
			
		case 0:
			printk("runnable\n");
			break;
			
		default:
			printk("stopped\n");
			break;	
	}
	
	printk(KERN_EMERG "START TIME: %llu\n", (unsigned long long)current->se.exec_start);
	printk(KERN_EMERG "VIRTUAL TIME: %llu\n", (unsigned long long)current->se.vruntime);
	
	printk(KERN_EMERG "PARENT PROCESSES UNTIL INIT : \n");
	for(Pointer = current; Pointer!=&init_task; Pointer=Pointer->parent)
	{
		printk(KERN_EMERG "%s [%d]\n", Pointer->comm, Pointer->pid);
	}
	
	return 1;
}

	

	
