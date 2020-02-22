#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void *myfunction(){
	sleep(2);
	printf("Hello from a thread!\n");
}

int main(){
	pthread_t thread_id;
	printf("Before thread\n");
	pthread_create(&thread_id, NULL, myfunction, NULL);
	pthread_join(thread_id, NULL);
	printf("After thread\n");
	return 0;
}
