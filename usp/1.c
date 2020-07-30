#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
char buffer[2048];

void copy(int old, int new)
{
	int count;
	while((count = read(old, buffer, sizeof(buffer)))>0)
		write(new, buffer, count);
}

int main(int argc, char*argv[])
{
	int fdold, fdnew;
	if(argc!=3)
	{
		printf("Enter 2 arguments\n");
		exit(1);
	}
	fdold = open(argv[1], O_RDONLY);
	if(fdold==-1)
	{
		printf("Can't open the file\n");
		exit(1);
	}
	fdnew = creat(argv[2], 0666);
	if(fdnew==-1)
	{
		printf("Can't create file\n");
		exit(1);
	}
	copy(fdold, fdnew);
	return(0);
}
