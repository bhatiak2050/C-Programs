#include<stdio.h>

int find_min(int count[], int size)
{
  int pos = 0;
  for (int i = 1; i < size; i++)    //NOTE that i=1 not 0;
    if (count[i] < count[pos])
      pos = i;
  return pos;
}

int main() 
{
  int i, j, k, pf = 0, n, nof, min, t = 1, status = 0;  //Note that t=1 not 0;

  printf("Enter length of reference string:");
  scanf("%d", & n);

  int rs[n];
  printf("Enter reference string\n");
  for (i = 0; i < n; i++)
    scanf("%d", & rs[i]);

  printf("Enter frame size (MAX 10):");
  scanf("%d", & nof);

  int frame[nof], count[nof];

  for (i = 0; i < nof; i++) 
  {
    frame[i] = -1;
    count[i] = 0;
  }

  for (i = 0; i < n; i++) 
  {
    status = 0;
    for (k = 0; k < nof; k++)
      if (frame[k] == rs[i]) 
      {
        count[k] = t++;
        status = 1;
      }
    
    if (status == 1) goto A;

    min = find_min(count, nof);
    count[min] = t++;
    frame[min] = rs[i];
    pf++;

    A: for (j = 0; j < nof; j++)
      printf("%d\t", frame[j]);
    printf("\n");
  }
  printf("\nPAGE FAULT is %d\n", pf);
  return 0;
}