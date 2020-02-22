#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<pthread.h>
#include<errno.h>
#include<unistd.h>
#define num 10

void *printhello(void *threadid){
	long tid = (long)threadid;
	printf("Hello! I am thread %ld\n", tid);
	pthread_exit(NULL);
}

int main()
{
	int rc = 0;
	pthread_t thread_id[num];
	for (int i = 0; i < num; ++i)
	{
		rc = pthread_create(&thread_id[i], NULL, printhello, (void*)i);
		pthread_join(thread_id[i], NULL);
		if(rc)
		{
			printf("Error1\n");
			exit(1);
		}
	}
}