#include<stdio.h>

int main(){
	int memsize=0, pagesize, no_of_page, p[100], frame_no, offset, logadd, phyadd;
	
	printf("Enter the memory size: ");
	scanf("%d", &memsize);

	printf("Enter the page size: ");
	scanf("%d", &pagesize);

	no_of_page = memsize/pagesize;

	for(int i=0; i<no_of_page; i++){
		printf("Enter the frame of page %d\n", i);
		scanf("%d", &p[i]);
	}

	int choice;
	do{
		printf("\n1. Compute physical address\n2. Exit\nEnter the choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: printf("Enter the logical address: ");
					scanf("%d", &logadd);
					frame_no = logadd/pagesize;
					offset = logadd%pagesize;
					phyadd = (p[frame_no] * pagesize + offset);
					printf("Physical Address = %d\n", phyadd);
					break;
		}
	}while(choice != 2);
}