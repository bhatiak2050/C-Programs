#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
}*start=NULL;

struct node * newNode(int x){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next=NULL;
    return temp;
}

void insert_at_beg(int x){
    struct node * temp = newNode(x);
    temp->next=start;
    start=temp;
}

void insert_at_end(int x){
    if(start==NULL) insert_at_beg(x);
    else{
        struct node * temp = newNode(x), *ptr=start;
        while(ptr->next != NULL) ptr=ptr->next;
        ptr->next = temp;
        temp->next=NULL;
    }
}

void insert_at_pos(int x, int pos){
    if(start == NULL) insert_at_beg(x);
    else{
        struct node * temp = newNode(x), *ptr=start;
        for(int i=0; i<pos-2; i++){
            ptr=ptr->next;
            if(ptr==NULL) {
                insert_at_end(x);
                return;
            }
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

int search(int item){
    if(start==NULL) printf("List Empty\n");
    else{
        int i=0;
        struct node * t=start;
        while(t != NULL){
            if(t->data == item) return i+1;   
            t=t->next;
            i++;
        }
    }
    return -1;
}

void traverse(){
     if(start==NULL) printf("List Empty\n");
    else{
        struct node *t=start;
        while(t != NULL){
            printf((t->next==NULL)?"%d\n":"%d->", t->data);
            t=t->next;
        }
    }
}

void Delete(int ele){
    if(start==NULL) printf("List Empty\n");
    else if(start->data == ele) {
        struct node * temp = start;
        free(start);
        start=temp->next;
    }
    else{
        struct node * ptr=start, *ptr_next;
        while(ptr->next->data != ele) {
           ptr=ptr->next;
           if(ptr->next==NULL) {
               printf("Element not found\n");
               return;
           }
        }
        ptr_next = ptr->next;
        ptr->next = ptr->next->next;
        free(ptr_next);
    }
}

//Free up all the nodes in the LL
void delete_all_nodes(){
  struct node *ptr, *ptr1;
  ptr = start;
  while(ptr != NULL)
  {
    ptr1 = ptr->next;
    free(ptr);
    ptr =  ptr1;
  }
  free(start);
  start = NULL;
}


//Main function
int main(){
	int c, x,pos;
	printf("\n1.Insert in the begining\n2.Insert in the end\n3.Insert in a given position\n4.Traverse\n5.Delete\n6.Search\n7.exit");
    while(c!=7){
		printf("\nEnter your choice: ");
		scanf("%d",&c);

        if(c == 1 || c == 2 || c == 3){
            printf("Enter the data: ");
            scanf("%d", &x);
            if(c==3){
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
            }
        }

		switch(c){
			case 1: insert_at_beg(x);      break;
			case 2: insert_at_end(x);      break;
			case 3: insert_at_pos(x, pos); break; 
			case 4: traverse();            break;
			case 5: printf("Enter the data to delete: ");
                    scanf("%d", &x);
                    Delete(x);     
                    break;
			case 6: printf("Enter the data to search: ");
                    scanf("%d", &x);
                    if((pos=search(x)) != -1) printf("%d found at pos %d\n", x, pos);
                    else printf("Element not found\n");     
                    break;
            
            case 7: delete_all_nodes(); break;
            case 8: delete_all_nodes(); break;
			default:printf("\nInvaild Choice");
		}
	}
	return 0;
}
