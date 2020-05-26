#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/module.h>

SYSCALL_DEFINE1(print_other, int, processId)
{

	struct task_struct *pointer1;
	struct task_struct *pointer2;
	
	pointer1 = pid_task(find_vpid(processId), PIDTYPE_PID);
	
	if(pointer1 == NULL)
	{
		printk(KERN_EMERG "PROCESS ID NOT FOUND FROM THE INPUT");
	}
	
	else
	{
		printk(KERN_EMERG "PROCESS ID %d running state is ", processId);
		
		switch(pointer1->state)
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
		
		printk(KERN_ALERT "PROCESS NAME: %s\n", pointer1->comm);
		printk(KERN_EMERG "START TIME: %llu\n", (unsigned long long)current->se.exec_start);
		printk(KERN_EMERG "VIRTUAL TIME: %llu\n", (unsigned long long)current->se.vruntime);
		
		printk(KERN_EMERG "PROCESS ID %d , PARENT PROCESSES UNTIL INIT : \n", processId);
		for(pointer2 = pointer1; pointer2 != &init_task; pointer2 = pointer2->parent)
		{
			printk(KERN_EMERG "%s [%d]\n", pointer2->comm, pointer2->pid);
		}	
		
		return 1;
	}
	
}	
	


