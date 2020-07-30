#include <limits.h> 
#include <stdio.h> 

int MatrixChainOrder(int p[], int i, int j) 
{ 
    if (i == j) 
        return 0; 
    int k, min = INT_MAX, count; 
    for (k = i; k < j; k++) { 
        count = MatrixChainOrder(p, i, k) +  
                MatrixChainOrder(p, k + 1, j) +  
                p[i - 1] * p[k] * p[j]; 
        if (count < min) min = count; 
	} 
    return min; 
} 
int main() { 
    int arr[] = { 1, 2, 5, 3 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    printf("Minimum number of multiplications is %d ", 
           MatrixChainOrder(arr, 1, n - 1)); 
    return 0; 
} 