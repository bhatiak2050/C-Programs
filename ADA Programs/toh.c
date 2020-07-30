#include<stdio.h>
#include<time.h>
void toh(int n, char beg, char aux, char end){
	if(n==1){
		printf("Disc 1: %c->%c\n", beg, end);
		return;
	}
	toh(n-1, beg, end, aux);
	printf("Disc %d: %c->%c\n",n, beg, end);
	toh(n-1, aux, beg, end);
}

int main(){
	int n, st, et;
	printf("Enter the number of disks: ");
	scanf("%d", &n);

	st=clock();
	toh(n, 'A', 'B', 'C');
	et=clock();
	printf("Start time: %d\nEnd time = %d\n", st, et);
	return 0;
}
