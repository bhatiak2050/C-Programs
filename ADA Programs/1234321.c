
#include<stdio.h>

void display(int n){
	if(n==4){
		printf("%d ", n);
		return;
	}
	else{
		printf("%d ", n);
		display(n+1);
		printf("%d ", n);
	}
}

int main(){
	display(1);
	return 0;
}
