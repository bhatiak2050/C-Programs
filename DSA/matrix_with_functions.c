#include<stdio.h>
#include<stdlib.h>

void add(int *a, int *b, int *c, int r, int s){
	for(int i=0; i<r; i++)
	for(int j=0; j<s; j++)
	*(c + i*s + j) = *(a + i*s + j) + *(b + i*s + j);
}

void subtract(int *a, int *b, int *c, int r, int s){
	for(int i=0; i<r; i++)
	for(int j=0; j<s; j++)
	*(c + i*s + j) = *(a + i*s + j) - *(b + i*s + j);
}

void multiply(int *a, int *b, int *c, int m, int n, int p, int q, int r, int s){
	for(int i=0; i<r; i++)
	for(int j=0; j<s; j++)
	for(int k=0; k<p; k++)
	*(c + i*s + j) += *(a + i*n + k) * *(b + k*q + j);
}

void transpose(int *a, int *c, int n, int r, int s){
	for(int i=0; i<r; i++)
	for(int j=0; j<s; j++)
	*(c + i*s + j) = *(a + j*r + i);
}

int main(){
	int choice, m, n, p=0, q=0, r, s, i, j;
	char ch='y';

	while(ch=='y')	{
		system("cls");
	do{
		//Display the menu
		printf("2 Matrix Calculator\n");
		printf("Menu:\n1)Add\n2)Subtract\n3)Multiply\n4)Transpose\n5)Exit\nEnter your choice: ");
		scanf("%d", &choice);

		if(choice==5) exit(0);

		printf("Enter the size of matrix A (r x c): \n");
		scanf("%d", &m);
		scanf("%d", &n);

		if(choice != 4){
			printf("Enter the size of matrix B (r x c): \n");
	                scanf("%d", &p);
        	        scanf("%d", &q);
			if(choice==3){
				if(n==p) break;
				else printf("Invalid. Try again\n\n");
			}
			else{
				if(m==p && n==q) break;
				else printf("Invalid. Try again\n\n");
			}
		}
		else break;

	}while(1);

	//Instantiate the matrices
	int *a = (int *)malloc(m * n * sizeof(int));
	int *b = (int *)malloc(p * q * sizeof(int));

        printf("Enter the elements of the matrix A\n");
        for(i=0; i<m; i++)
        for(j=0; j<n; j++)
                scanf("%d", (a + i*n + j));

	if(choice!=4){
		printf("Enter the elements of the matrix B\n");
	        for(i=0; i<p; i++)
        	for(j=0; j<q; j++)
	                scanf("%d", (b + i*q + j));
	}
	     if(choice == 4){ r=n; s=m; }
	else if(choice == 3){ r=m; s=q; }
	else                { r=m; s=n; }

	int *c = (int *)malloc(r * s * sizeof(int));
       	for(i=0; i<r; i++)
        for(j=0; j<s; j++)
               	*(c + i*s + j) = 0;

	//Perform operation
	switch(choice){
		case 1:	add(a, b, c, r, s);
			break;

		case 2: subtract(a, b, c, r, s);
                        break;

		case 3: multiply(a, b, c, m, n, p, q, r, s);
                        break;

		case 4: transpose(a, c, n, r, s);
                        break;
	}

	//Display result
	     if(choice == 1) printf("The sum is\n");
        else if(choice == 2) printf("The difference is\n");
        else if(choice == 3) printf("The product is\n");
	else                 printf("The transpose is\n");

	for(i=0; i<r; i++){
		for(j=0; j<s; j++)
	        	printf("%2.d ", *(c + i*s + j));
		printf("\n");
	}

	printf("\nWant to enter again? (y/n): ");
	scanf("%c%c", &ch, &ch);
	}
}
