#include<stdio.h>

int fact(int n){
	if(n==0) return 1;
	else return n*fact(n-1);
}

float perm(int n, int r){
	return fact(n)/fact(n-r);
}

float comb(int n, int r){
	return fact(n)/(fact(r)*fact(n-r));
}

int main(){
	int n, r, c=0;
	while(c!=3){
		printf("\n1. Permutation\n2. Combination\n3. Exit\nEnter your choice: ");
		scanf("%d", &c);
		switch(c){
		case 1:{
			printf("Enter the equation: ");
			scanf("%dP%d", &n, &r);
			printf("%dP%d = %g\n", n, r, perm(n, r));
			break;
		}
		case 2: {
			printf("Enter the equation: ");
			scanf("%dC%d", &n, &r);
			printf("%dC%d = %g\n", n, r, comb(n, r));
			break;
		}}
	}
}
