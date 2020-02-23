#include<stdio.h>
#include<stdlib.h>

int main()
{
	int choice, m, n, p, q, r, s, i, j;
	system("clear");
	char ch='y';

	while(ch=='y')
	{

	do
	{
		printf("2 Matrix Calculator\n");
		printf("Menu:\n1)Add\n2)Subtract\n3)Multiply\n4)Transpose\n5)Exit\nEnter your choice: ");
		scanf("%d", &choice);

		if(choice==5) exit(0);

		printf("Enter the size of matrix A (r X c): \n");
		scanf("%d", &m);
		scanf("%d", &n);

		if(choice != 4)
		{
			printf("Enter the size of matrix B (r X c): \n");
	                scanf("%d", &p);
        	        scanf("%d", &q);
			if(choice==3)
			{
				if(n==p) break;
				else printf("Invalid. Try again\n\n");
			}
			else
			{
				if(m==p && n==q) break;
				else printf("Invalid. Try again\n\n");
			}
		}
		else break;

	}while(1);

	int *a = (int *)malloc(m * n * sizeof(int));
	int *b = (int *)malloc(p * q * sizeof(int)), *c;

        printf("Enter the elements of the matrix A\n");
        for(i=0; i<m; i++)
        for(j=0; j<n; j++)
                scanf("%d", (a + i*n + j));

	if(choice!=4)
	{

		printf("Enter the elements of the matrix B\n");
	        for(i=0; i<p; i++)
        	for(j=0; j<q; j++)
	                scanf("%d", (b + i*q + j));
	}

	     if(choice == 4){ r=n; s=m; }
	else if(choice == 3){ r=m; s=q; }
	else                { r=m; s=n; }

	c = (int *)malloc(n * m * sizeof(int));
       	for(i=0; i<r; i++)
        for(j=0; j<s; j++)
               	*(c + i*s + j) = 0;

	switch(choice)
	{
		case 1:	for(i=0; i<m; i++)
			for(j=0; j<n; j++)
			*(c + i*n + j) = *(a + i*n + j) + *(b + i*n + j);
			break;

		case 2: for(i=0; i<m; i++)
                        for(j=0; j<n; j++)
                        *(c + i*n + j) = *(a + i*n + j) - *(b + i*n + j);
                        break;

		case 3: for(i=0; i<m; i++)
                        for(j=0; j<n; j++)
			for(int k=0; k<q; k++)
                        *(c + i*n + j) += *(a + i*n + k) * *(b + k*q + j);
                        break;

		case 4: for(i=0; i<r; i++)
                        for(j=0; j<s; j++)
                        *(c + i*n + j) = *(a + j*n + i);
                        break;
	}

	     if(choice == 1) printf("The sum is\n");
        else if(choice == 2) printf("The difference is\n");
        else if(choice == 3) printf("The product is\n");
	else                 printf("The transpose is\n");

	for(i=0; i<r; i++)
        {
		for(j=0; j<s; j++)
	        	printf("%d ", *(c + i*n + j));
		printf("\n");
	}

	printf("\nWant to enter again? (y/n): ");
	scanf("%c", &ch);
	}
}
