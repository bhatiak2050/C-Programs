#include<stdio.h>
#include<stdlib.h>

int main(){
	int i, c, ind, n, f[50], index[50], count=0;

	for(i=0; i<50; i++) f[i] = 0;

	do
	{
		printf("Enter the index block: \n");
		scanf("%d", &ind);
		if(f[ind] == 0)
		{
			f[ind] = 1;
			printf("Enter the no of blocks needed for the index %d on the disk:\n", ind);
			scanf("%d", &n);
		}
		else 
		{
			printf("%d is already allocated\n", ind);
			continue;
		}

		while(1)
		{
			count=0;
			printf("Enter the indices\n");
			for(i=0; i<n; i++)
			{
				scanf("%d", &index[i]);
				if(f[index[i]] == 0) count++;
			}
			if(count == n)
			{
				for(i=0; i<n; i++)
				{
					f[index[i]] = 1;
					printf("%d ---> %d, %d\n", ind, index[i], f[index[i]]);
				}
				printf("allocated file indices\n");
				break;
			}
			else 
				printf("The file in the index is already allocated. Enter another file index\n");
		}
		printf("Do you want to continue (1/0): \n");
		scanf("%d", &c);
 	} while(c==1);
}