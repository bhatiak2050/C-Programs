#include<stdio.h>
#include<time.h>

double fact(double n){
	if(n==0 || n==1) return 1;
	else return n*fact(n-1);
}

double perm(int n, int r){
	return fact(n)/fact(n-r);
}

double comb(int n, int r){
	return fact(n)/(fact(r)*fact(n-r));
}

int main(){
	int n, r, c=0, st, et;
	printf("\n1. Permutation\n2. Combination\n3. Exit\nEnter your choice: ");
	scanf("%d", &c);
	switch(c){
	case 1:{
		printf("Enter the equation (xPy): ");
		scanf("%dP%d", &n, &r);
		st = clock();
		printf("%dP%d = %g\n", n, r, perm(n, r));
		et = clock();
		printf("Start time = %d\nEnd time = %d\n", st, et);
		break;
	}
	case 2: {
		printf("Enter the equation (xCy): ");
		scanf("%dC%d", &n, &r);
		st = clock();
		printf("%dC%d = %g\n", n, r, comb(n, r));
		et = clock();
		printf("Start time = %d\nEnd time = %d\n", st, et);
		break;
	}}
}
