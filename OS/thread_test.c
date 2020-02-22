#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdlib.h>
void *mythreadfun()
{
	sleep(1);
	printf(" printing DSU from thread\n");
	return NULL;
}
int main()
{
	
	pthread_t thread_id;
	printf("Before thread\n");
	pthread_create(&thread_id,NULL,mythreadfun,NULL);
	pthread_join(thread_id,NULL);	
	//wait(NULL);
	printf("After thread\n");
}

