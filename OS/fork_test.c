#include<stdio.h>
#include<unistd.h>
//#include <sys/types.h>
#include <sys/wait.h>
void main()
{
fork();
wait(2);
printf("DSU\n");
fork();
wait(2);
printf("DSU\n");
fork();
wait(2);
printf("DSU\n");
fork();
wait(2);
printf("DSU\n");
//printf("The PPID of the process is = %d \n",getppid());
} 

