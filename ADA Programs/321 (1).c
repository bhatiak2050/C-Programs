#include<stdio.h>

void display(int n){
	if(n==0) return;
	else{
		printf("%d, ", n);
		display(n-1);
	}
}

int main(){
	display(3);
	return 0;
}
