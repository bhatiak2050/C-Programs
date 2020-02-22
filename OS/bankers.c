#include<stdio.h>
#include<stdbool.h>

int main() 
{
  int i, j, process, resource, instance, k = 0, count1 = 0, count2 = 0 ;

  printf("Enter no. of process: ");
  scanf("%d", & process);

  printf("Enter the no. of resources: ");
  scanf("%d", & resource);

  int max[process][resource], allot[process][resource], need[process][resource];
  int avail[resource];
  bool completed[process];

  for (int i = 0; i < process; i++)
    completed[i] = false;

  printf("Enter the no. of instances already allocated to process of a resource:\n");
  for (int i = 0; i < process; i++) 
    for (int j = 0; j < resource; j++) 
      scanf("%d", &allot[i][j]);

  printf("Enter the max no of instances of resource that a process needed:\n");
  for (int i = 0; i < process; i++) 
    for (int j = 0; j < resource; j++) 
    {
      scanf("%d", &max[i][j]);
      need[i][j] = max[i][j] - allot[i][j];
    }

  printf("Enter the no. of available instances: ");
  for (int i = 0; i < resource; i++) 
    scanf("%d", &avail[i]);


  printf("The safe sequence is \n");
  while (count1 != process) 
  {
    count2 = count1;
    for (int i = 0; i < process; i++) 
    {
      for (int j = 0; j < resource; j++) 
        if (need[i][j] <= avail[j]) 
          k++;

      if ((k == resource) && completed[i] == false) 
      {
        printf("p[%d]\t", i);
        completed[i] = true;
        count1++;
        for (int j = 0; j < resource; j++) 
          avail[j] += allot[i][j];
      }
      k = 0;
    }
    
    if (count1 == count2) 
    {
      printf("stop... afterthis....deadlock");
      break;
    }
  }
  return 0;
}