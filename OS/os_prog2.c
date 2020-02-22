#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdlib.h>
void main()
{
   int pid,parent_ppid,child_id,grandchild_id;
   pid = fork();
	
  	printf("pid %d\n",getpid());
	printf("ppid %d\n",getppid());
	wait(NULL);
}


