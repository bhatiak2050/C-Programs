#include <stdio.h>

int partition (int arr[], int low, int high)  {
    int pivot = arr[high];
    int i = (low - 1), t;

    for (int j = low; j <= high- 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }
    }
    
    t=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=t;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(void) {
  int n, i;
    printf("Enter the size: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the array elements: ");
    for(i=0; i<n; i++) scanf("%d", &a[i]);

    quickSort(a, 0, n-1);

    printf("The sorted array is:\n");
    for(i=0; i<n; i++) printf("%d ", a[i]);
  return 0;
}
