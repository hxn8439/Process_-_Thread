
#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <linux/unistd.h>
#include <sys/types.h>
#include <signal.h>

#define __NR_helloworld 335
#define __NR_print_self 336
#define __NR_print_other 337


int main(int argc, char *argv[])
{
	syscall(__NR_helloworld);
	syscall(__NR_print_self);
	
	int processId;
	

	printf("ENTER PROCESS ID: ");
	scanf("%d", &processId);
	
	if(kill(processId, 0) == 0)
	{
		syscall(__NR_print_other);
		printf("Process Id %d found, its executing, run command dmesg to view\n\n", processId);
	}
	
	else
	{
		printf("Process Id %d is not executing\n\n", processId);	
	}	


	return 0;
}	



