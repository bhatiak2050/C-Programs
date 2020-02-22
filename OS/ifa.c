#include<stdio.h>
#include<stdlib.h>

int main(){
	int i, j, k, c, ind, n, f[50], index[50], count=0;
	for(i=0; i<50; i++) f[i] = 0;

	x: printf("Enter the index block: \n");
	scanf("%d", &ind);
	if(f[ind] != 1){
		printf("Enter the no of blocks needed for the index %d on the disk:\n", ind);
		scanf("%d", &n);
	}
	else{
		printf("%d is already allocated\n", ind);
		goto x;
	}
	y: count=0;
	for(i=0; i<n; i++){
		scanf("%d", &index[i]);
		if(f[index[i]] == 0) count++;
	}
	if(count == n){
		for(j=0; j<n; j++){
			f[index[j]] = 1;
			printf("allocated\n");
			printf("file indexed\n");
			for(k=0; k<n; k++)
				printf("%d ---> %d%d\n", ind, index[k], f[index[k]]);
		}
	}
	else{
		printf("The file in the index is already allocated\n");
		printf("Enter another file index\n");
		goto y;
	}
	printf("Do you want to continue (1/0): \n");
	scanf("%d", &c);
	if(c==1) goto x;
	else exit(0);
}