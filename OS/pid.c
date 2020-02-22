#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdlib.h>
void main()
{
	int pid,parent_ppid,child_id,grandchild_id;
	pid = fork();
	if(!pid){
		printf("child process %d\n",pid);
		printf("Child_ID = %d\n",getpid());
		printf("Parent_ID = %d\n",getppid());
	}
	else{
		wait(0);
		printf("Parent %d\n",pid);
		printf("Parent_ID =%d\n",getpid());
		printf("Child_ID = %d\n",pid);
	}
}


