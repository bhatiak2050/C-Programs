#include <stdio.h>

void heapify(int arr[], int n ,int i){
    int t, largest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n && arr[l] > arr[largest]) largest = l;
    if(r<n && arr[r] > arr[largest]) largest = r;

    if(largest != i){
        t=arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n){
    int i, t;
    for(i=n/2; i>=0; i--) heapify(arr, n, i);
    for(i=n-1; i>=0; i--){
        t=arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heapify(arr, i, 0);
    }
}

int main(){
    int n, i;
    printf("Enter the size: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the array elements: ");
    for(i=0; i<n; i++) scanf("%d", &a[i]);

    heapsort(a, n);

    printf("The sorted array is:\n");
    for(i=0; i<n; i++) printf("%d ", a[i]);
}
