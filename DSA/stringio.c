#include<stdio.h>
#include<stdlib.h>

void main()
{
	system("clear");
	char *c;
	int size = 15;

	c = (char*)malloc(size*sizeof(char));

	printf("Enter the string: ");
	scanf("%[^\n]s", c);

	printf("Ths string is: %s\n", c);
	free(c);
}
