#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199302L
#include<stdio.h>
#include<unistd.h>
int main()
{
	int result;
	#ifdef _POSIX_VERSION
	printf("System confirms to POSIX %ld\n",_POSIX_VERSION);
	#endif
	if((result = pathconf("/", _PC_PATH_MAX))==-1)
		perror("pathconf");
	else
		printf("Maximum character in pathname %d\n",result);

	if((result = sysconf(_SC_CHILD_MAX))==-1)
		perror("sysconf");
	else
		printf("Maximum number of child processes allowed %d\n",result);

	if((result = pathconf("/",_PC_NAME_MAX))==-1)
		perror("pathconf");
	else
		printf("Maximum no of charcaters in name: %d\n",result);
	
	if((result = sysconf(_SC_OPEN_MAX))==-1)
		perror("sysconf");
	else
		printf("Maximum no of files can be opened simlutaneously %d\n",result);

	if((result = sysconf(_SC_CLK_TCK))==-1)
		perror("sysconf");
	else
		printf("Maximum no of clocks to be used simultaneously %d\n",result);
	return 0;
}