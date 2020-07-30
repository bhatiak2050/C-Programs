#include <stdio.h>
#include <limits.h>

void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int l, int h, int a[]){
    int pivot = a[l];
    int i=l, j=h;
    while(i<j){
        do i++; while(a[i] <= pivot);
        do j--; while(a[j] >  pivot);
        if(i<j) swap(&a[i], &a[j]);
    }
    swap(&a[l], &a[j]);
    return j;
}

void quicksort(int l, int h, int a[]){
    if(l<h){
        int j=partition(l, h, a);
        quicksort(l,   j, a);
        quicksort(j+1, h, a);
    }
}

int main(void) {
    int i, n;
    printf("Enter the size: ");
    scanf("%d", &n);
    
    int a[n];
    printf("Enter the elements: ");
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    
    quicksort(0, n, a);

    printf("The sorted array is:\n");
    for(i=0; i<n; i++) printf("%d ", a[i]);
    return 0;
}