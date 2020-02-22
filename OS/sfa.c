#include<stdio.h>
#include<stdlib.h>

int main(){
	int f[50], i, st, len, j, c, k, count=0;

	for(i=0; i<50; i++) f[i] = 0;

	do{
		count=0;
		printf("Enter starting block and length of file:\n");
		scanf("%d%d", &st, &len);

		for(k=st; k<(st+len); k++)
			if(f[k] == 0)
				count++;

		if(count == len)
		{
			printf("f[]\tstatus\n");
			for(k=st; k<(st+len); k++)
			{
				f[k] = 1;
				printf("%d\t%d\n", k, f[k]);
			}
			printf("The file is allocated to disk\n");
		}
		else 
			printf("The file is not allocated\n");

		printf("Do you want to enter more files (1/0): ");
		scanf("%d", &c);
	}while(c==1);
}