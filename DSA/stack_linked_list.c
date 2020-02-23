#include<stdio.h>
#include<stdlib.h>

struct node
{
  int info;
  struct node *next;
}*start;

void traverse()
{
  struct node * ptr;
  ptr = start;
  if(ptr == NULL) printf("No elements\n");
  else
  while(ptr != NULL)
  {
    printf((ptr->next == NULL)?"%d\n":"%d->", ptr->info);
    ptr = ptr->next;
  }
}

struct node * traverse_return_last()
{
  struct node * ptr;
  ptr = start;
  if(start == NULL) return NULL;
  while(ptr->next != NULL) ptr = ptr->next;
  return ptr;
}

struct node * traverse_return_last_2()
{
  struct node * ptr;
  ptr = start;
  if(start == NULL) return NULL;
  while(ptr->next->next != NULL) ptr = ptr->next;
  return ptr;
}

void insert()
{
  struct node * newptr = (struct node *)malloc(sizeof(struct node));
  printf("Enter the element: ");
  scanf("%d", &newptr->info);
  
 
    int choice;
    printf("Where to insert?\n1)Start\n2)End\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
      case 1: newptr->next = start;
              start = newptr;
              break;
      case 2: {
        struct node * last_node = traverse_return_last();
        if(last_node == NULL) start = last_node = newptr;
        else last_node->next = newptr;
        newptr->next = NULL;
      }
    }
  }

void delete_all_nodes()
{
  struct node *ptr, *ptr1;
  ptr = start;
  while(ptr != NULL)
  {
    ptr1 = ptr->next;
    free(ptr);
    ptr =  ptr1;
  }
}

void Delete()
{
   if(start == NULL) {
      printf("Underflow\n");
      return;
  }
  int choice;
    printf("Where to delete?\n1)Start\n2)End\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
      case 1: 
      {
        struct node * save = start->next;
               free(start);
               start = save;
               break;
      }
      case 2:
      {
        struct node * _2nd_last_node = traverse_return_last_2();
        free(_2nd_last_node->next);
        _2nd_last_node->next = NULL;
        break;
      }
    }
}

int main()
{
  int ch=0;
  printf("Linked List Menu\n");
  printf("1)Insert\n2)Delete\n3)Traverse\n4)Exit\nEnter your choice: ");
  scanf("%d", &ch);

  while(ch != 4)
  {
    switch(ch)
    {
      case 1: insert(); break;
      case 2: Delete(); break;
      case 3: traverse(); break;
      case 4: delete_all_nodes();
    }
     printf("\n1)Insert\n2)Delete\n3)Traverse\n4)Exit\nEnter your choice: ");
     scanf("%d", &ch);
  }
  return 0;
}