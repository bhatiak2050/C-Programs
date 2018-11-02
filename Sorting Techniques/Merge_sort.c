#include<stdio.h>
#include<stdlib.h>

void Merge(int A[], int beg,int mid,int end, int size) {
 int B[size];
 int i=beg,j=mid+1,k=beg,p;
 while(i<=mid && j<=end) {
  if(A[i]<=A[j]) {
   B[k]=A[i];
   i=i+1;
   k=k+1;
  }
else {
   B[k]=A[j];
   j=j+1;
   k=k+1;
   }
 }
 if(i>mid) {
   for(p=j;p<=end;p++) {
    B[k]=A[p];
    k=k+1;
   }
  }
 else if(j>end) {
   for(p=i;p<=mid;p++) {
    B[k]=A[p];
    k=k+1;
   }
  }
 for(p=beg;p<=end;p++)
  A[p]=B[p];
}

void MergeSort(int A[], int Beg,int End, int size) {
 if(Beg<End) {
 int mid=(int)((Beg+End)/2);
 MergeSort(A, Beg,mid, size);
 MergeSort(A, mid+1,End, size);
 Merge(A, Beg,mid,End, size);
 }
}

int main() {
 int i, size;
 printf("Enter the size of the array: ");
 scanf("%d", &size);

 int A[size];
 printf("Enter the elements of the array: ");
 for(i=0; i<size; i++) scanf("%d", &A[i]);

  MergeSort(A, 0,size-1, size);

 printf("\nThe sorted list is:\n");
 for(i=0; i<size; i++)
  printf("%d  ",A[i]);

 return 0;
}
