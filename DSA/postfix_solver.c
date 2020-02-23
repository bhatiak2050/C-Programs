
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

char c[50];
  int stack[15];
	int top = -1, i;

int push(int stack[], int top, int size, int item)
{
	if(top!=size-1) 
  {
    top++;
    stack[top] = item;
  }
  else printf("Overflow\n");
	return top;
}
int pop(int top, int size)
{
	if(top!=-1) top--;
  else printf("Underflow\n");
	return top;
}

int main()
{
	

  printf("Enter the postfix expression: ");
  scanf("%[^\n]s", c);

  for(int i=0; c[i] != '\0'; i++)
  {
    if(isdigit(c[i])) 
    {
      top = push(stack, top, 15, (c[i]-48));
      //printf("%d is a digit\n", (int)(stack[i] - 48));
    }
    else 
    {
      switch(c[i])
      {
        case '+':{
           int temp = stack[top-1] + stack[top];
           top = pop(top, 15);
           top = pop(top, 15);
           top = push(stack, top, 15, temp);
           break;
        }
        case '-':{
           int temp = stack[top-1] - stack[top];
           top = pop(top, 15);
           top = pop(top, 15);
           top = push(stack, top, 15, temp);
           break;
        }
        case '*':{
           int temp = stack[top-1] * stack[top];
           top = pop(top, 15);
           top = pop(top, 15);
           top = push(stack, top, 15, temp);
           break;
        }
        case '/':{
           int temp = stack[top-1] / stack[top];
           top = pop(top, 15);
           top = pop(top, 15);
           top = push(stack, top, 15, temp);
           break;
        }
        case '^':{
           int temp = pow(stack[top-1], stack[top]);
           top = pop(top, 15);
           top = pop(top, 15);
           top = push(stack, top, 15, temp);
           break;
        }
      }
    }
    //for(int k=0; k<=top; k++) printf("%d ", stack[k]);
   // printf("\n");
  }
    printf("The result is %d\n", stack[top]);
  return 0;
}