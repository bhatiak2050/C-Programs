#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
	if(argc<3 || argc>4 || (argc==4 && strcmp(argv[1], "-s")))
	{
		printf("USAGE: ./a.out [-s] <org.file><new-link>");
		return 1;
	}
	if(argc==4)
	{
		if(symlink(argv[2], argv[3])==-1)
			printf("can't create symbolic link");
		else
			printf("symbolic link created");
	}
	else
	{
		if(link(argv[1], argv[2])==-1)
			printf("Hard link cannot be created");
		else
			printf("Hard link created \n");
	}
	return 0;
}