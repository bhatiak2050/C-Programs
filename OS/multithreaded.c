#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#define num 10

void *printhello(void *thread_id){
	long tid = (long)thread_id;
	printf("Hello! I am thread #%ld\n", tid);
	pthread_exit(NULL);
}

int main(){
	pthread_t thread_id[num];
	int rc;
	printf("Before thread\n");
	for(long i=0; i<num; i++)
	{
		rc = pthread_create(&thread_id[i], NULL, printhello, (void*)i);
        pthread_join(thread_id[i], NULL);
		if(rc){
			printf("Error\n");
			exit(1);
		}
	}
	printf("After thread\n");
	return 0;
}
