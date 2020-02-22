#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
void main()
{
    int pid;
    pid = fork();
  	if(pid<0)
	{
		printf("Fork failed\n");
		exit(1);
	}
 	else if (pid==0)
	{
		execlp("whoami","whoami", (char*)NULL);
		exit(0);
	}
 	else 
	{
	 	printf("Process id is %d\n", getpid());
		printf("Parent Process id is %d\n\n", getppid());
		wait(NULL);
		exit(0);
	}
}