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

	printf("Enter the equation: ");
	if(scanf("%dP%d", &n, &r) != 1) printf("%dP%d = %g\n", n, r, perm(n, r));
	else{
		scanf("%d", &r);
		printf("%dC%d = %g\n", n, r, comb(n, r));
	}
}
