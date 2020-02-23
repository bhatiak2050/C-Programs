#include <stdio.h>
#include<string.h>

int compare (char b[], char a[])
{
  int i, length = (strlen(a)>strlen(b))?strlen(a):strlen(b);
  for(i=0; i<length; i++)
  if(b[i] > a[i]) return 1;
  else if(b[i] < a[i]) return -1;
  return 0;
}

int main() {
  char a[50], b[50], dummy;
  printf("Enter A (Max size 50)\n");
  scanf("%[^\n]s", a);

  scanf("%c", &dummy);

  printf("Enter B (Max size 50)\n");
  scanf("%[^\n]s", b);

  char choice;
  printf("Compare with strcmp() (y/n): ");
  scanf("%c%c", &choice, &choice);

  int c = (choice=='y')?strcmp(b, a):compare(b, a);
  if(!c) printf("Strings are equal");
  else if(c>0) printf("%s is greater", b);
  else if(c<0) printf("%s is greater", a);
  return 0;
}