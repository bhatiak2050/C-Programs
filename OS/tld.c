#include<stdio.h>

struct
{
	char dname[10];
	char fname[10][10];
	int fcnt;
}dir[10];

int main()
{
	int c, dcnt, i, j;

	printf("Enter the number of directories: ");
	scanf("%d", &dcnt);

	for(i=0; i<dcnt; i++)
	{
		dir[i].fcnt = 0;
		printf("Enter the name of the directory: ");
		scanf("%s", dir[i].dname);
		do
		{
			printf("Enter the name of the file: ");
			scanf("%s", dir[i].fname[dir[i].fcnt]);
			dir[i].fcnt++;
			if(dir[i].fcnt == 10) break;
			printf("Do you want to continue (1/0): ");
			scanf("%d", &c);
		}while(c==1);
	}
	printf("The directories & files are: \n");
	for(i=0; i<dcnt; i++)
	{
		printf("%s\n", dir[i].dname);
		for(j=0; j<dir[i].fcnt; j++)
			printf("\t%s\n", dir[i].fname[j]);
	}
}