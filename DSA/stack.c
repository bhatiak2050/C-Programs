#include<stdio.h>
#include<stdlib.h>

int push(int data[], int top, int size)
{
	if(top!=size-1)
	{
		top++;
                printf("Enter the data\n");
                scanf("%d", &data[top]);
		printf("\n%d entered successfully\n", data[top]);
        }
        else
             	printf("Overflow\n");
	return top;
}
int pop(int data[], int top, int size)
{
	if(top!=-1)
	{
		printf("%d deleted\n", data[top]);
		top--;
        }
        else
                printf("Underflow\n");
	return top;
}
void display(int data[], int top, int size)
{
        int t=0;
        while(t<=top)
        {
                printf((t==top)?"%d\n":"%d->", data[t]);
                t++;
        }
	if(top == -1) printf("No elements\n");
}

int isFull(int top, int size)
{
	if(top == size-1) return 1;
	else return 0;
}

int isEmpty(int top)
{
	if(top == -1) return 1;
	else return 0;
}

void main()
{
	int data[4];
	int top = -1;

        system("cls");

        int ch;
        printf("Stack menu:\n");
        printf("1)Push\n2)Pop\n3)Check full\n4)Check empty\n5)Display\n6)Exit");
        do
        {
                printf("\nEnter your choice: ");
                scanf("%d", &ch);
                switch(ch)
                {
                	case 1: top = push(data, top, 4);    break;
                        case 2: top = pop(data, top, 4);     break;
			case 3: if(isFull(top, 4)) printf("Stack is Full!\n"); 
				else printf("Stack is NOT full\n");
				break;
			case 4: if(isEmpty(top)) printf("Stack is Empty\n"); 
				else printf("Stack is NOT empty\n");
				break;
                        case 5: display(data, top, 4); break;
                }
        }while(ch!=6);
}