#include<stdio.h>
#define and &&

struct  
{
	char dname[10];
	char fname[10][10];
	int fcnt;
}dir;

int main()
{
	int c;
	dir.fcnt = 0;
	printf("Enter the name of the directory: \n");
	scanf("%s", dir.dname);
	do
	{
		printf("Enter name of file: ");
		scanf("%s", dir.fname[dir.fcnt]);
		dir.fcnt++;
		if(dir.fcnt == 10) break;
		printf("Do you want to enter more? (1/0): \n");
		scanf("%d", &c);
	} while(c==1);
	
	printf("The files are \n%s\n", dir.dname);
	for(int i=0; i<dir.fcnt; i++)
		printf("\t%s\n", dir.fname[i]);
}