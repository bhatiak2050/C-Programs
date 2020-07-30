#include<stdio.h>

void merge(int left[], int nl, int right[], int nr, int a[]){
	int i=0, j=0, k=0;

	while(i<nl && j<nr)
	if (left[i] <= right[j]) a[k++] = left[i++];
	else a[k++] = right[j++];

	while(i<nl) a[k++] = left[i++];
	while(j<nr) a[k++] = right[j++];
}

void mergesort(int a[], int size){
	if(size<2) return;
	int mid = size/2, i;
	int lsize = mid, rsize=size-mid;
	int left[mid], right[size-mid];

	for(i=0; i<mid;  i++) left[i]      = a[i];
	for(   ; i<size; i++) right[i-mid] = a[i];

	mergesort(left , lsize);
	mergesort(right, rsize);
	merge(left, lsize, right, rsize, a);
}

int main(){
        int i, n;
        printf("Enter the size: ");
        scanf("%d", &n);

        int a[n];
        printf("Enter the elements\n");
        for(i=0; i<n; i++)
                scanf("%d", &a[i]);

        mergesort(a, n);

	for(i=0; i<n; i++) printf("%d ", a[i]);
        return 0;
}




