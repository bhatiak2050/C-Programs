#include <stdio.h>
#include<stdlib.h>

int isSparse (int *a, int r, int c)
{
  int v=0, i, j;
  for(i=0; i<r; i++)
  for(j=0; j<c; j++)
  if(*(a + i*c + j) == 0) v++;

  if(v > (r*c)/2) return 1;
  else return 0;
}

int main() {
  int i, j, m, n;
  printf("Enter the order of the matrix\n");
  scanf("%d%d", &m, &n);

  int *a = (int*)malloc(m*n*sizeof(int));

  printf("Enter the elements\n");
  for(i=0; i<m; i++)
  for(j=0; j<n; j++)
    scanf("%d", (a + i*n + j));

   if(isSparse(a, m, n)) printf("The matrix is a sparse matrix\n");
   else printf("The matrix is NOT a sparse matrix\n");
  return 0;
}