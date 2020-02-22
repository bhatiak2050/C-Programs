#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdlib.h>
void main()
{
	int pid;
	pid = fork();
	if(!pid){
		printf("I am child\n");

		sleep(5);
		printf("child process %d\n",pid);
		printf("Child_ID = %d\n",getpid());
		printf("Parent_ID = %d\n",getppid());
	}
	else{
		wait(NULL);
		printf("I am parent\n");
		sleep(5);
		printf("Parent process %d\n",pid);
		printf("Parent_ID =%d\n",getpid());
		printf("Child_ID = %d\n",pid);
		printf("Shell ID = %d\n", getppid());
	}
}


