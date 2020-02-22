//Compile this program in bash shell

#include <stdio.h>

int full=0, empty=3, mutex=1, x=0;

int Wait(int s){
	return --s;
}

int Signal(int s){
	return ++s;
}

void producer(){
	mutex = Wait(mutex);
	full = Signal(full);
	empty = Wait(empty);

	x++;

	printf("Producer produces the item %d\n", x);
	mutex = Signal(mutex);
}

void consumer(){
	mutex = Wait(mutex);
	full = Wait(full);
	empty = Signal(empty);

	printf("Consumer consumes the item %d\n", x);
	x--;
	mutex = Signal(mutex);
}

int main(){
	int c;
	printf("\nMenu:\n1)Produce\n2)Consume\n3)Exit\nEnter your choice: \n");
	scanf("%d", &c);
	while(c!=3){
		switch(c){
			case 1: if((mutex==1) && (empty!=0))
						producer();
					else
						printf("Buffer is full\n");
					break;
			case 2: if((mutex==1) && (full!=0))
						consumer();
					else
						printf("Buffer empty\n");
					break;
		}
		scanf("%d", &c);
	}
}