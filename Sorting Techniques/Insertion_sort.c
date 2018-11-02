#include <stdio.h>

void insertionSort(int arr[], int n) {
   int i, key, j;
   for (i = 1; i < n; i++) {
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key) {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

int main(void) {
    int i, size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int A[size];
    printf("Enter the elements of the array: ");
    for(i=0; i<size; i++) scanf("%d", &A[i]);

    insertionSort(A, size);

    printf("\nThe sorted list is:\n");
    for(i=0; i<size; i++)
    printf("%d ",A[i]);

    return 0;
}
