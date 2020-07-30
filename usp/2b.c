#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 200809L
#include<stdio.h>
#include<unistd.h>
int main()
{
	#ifdef _POSIX_JOB_CONTROL
	printf("System supports job control\n");
	#else
	printf("System does not support job control\n");
	#endif

	#ifdef _POSIX_SAVED_IDS
	printf("Supports user ID's and group id\n");
	#else
	printf("DOes not support user id's and group id's\n");
	#endif

	#ifdef _POSIX_CHOWN_RESTRICTED
	printf("chown_restricted option is %d\n",_POSIX_CHOWN_RESTRICTED);
	#else
	printf("System doesn't support chown_restricted option\n");
	#endif

	#ifdef _POSIX_NO_TRUNC
	printf("pathname trunc option is %d\n",_POSIX_NO_TRUNC);
	#else
	printf("path trunc option is not supported\n");
	#endif

	#ifdef _POSIX_VDISABLE
	printf("disbale char for terminal file is %d\n",_POSIX_VDISABLE);
	#else
	printf("system doesn't support _POSIX_VDISABLE feature\n");
	#endif
	return 0;
}