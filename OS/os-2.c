#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){
	int child, grandchildid;

	child = fork();
	if(child < 0){
		printf("Error\n");
		exit(1);
	
	else if(child != 0){
		wait(NULL);
		printf("\nI am Parent and my process id is: %d\n", getpid());
		exit(0);
	}
	else{
		wait(NULL);
		grandchildid = fork();
		if(grandchildid < 0){
			printf("Error in grandchild\n");
			exit(2);
		}
		else if(grandchildid != 0){
			wait(NULL);
			printf("\nI am Child\n");
			printf("and my process id is: %d\n", getpid());
			printf("and my Parent process id is %d\n", getppid());
			exit(0);
		}
		else{
			wait(NULL);
			printf("\nI am grandchild\n");
			printf("and my process id is %d\n", getpid());
			printf("and my Parent process id is %d\n", getppid());
			exit(0);
		}
	}
}