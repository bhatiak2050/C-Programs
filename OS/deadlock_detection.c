#include <stdio.h>
#include <stdbool.h>

int main(){
	int i, j, k, processes, resources, flag=0;

	printf("Enter the number of processes: \n");
	scanf("%d", &processes);
	printf("Enter the number of resources: \n");
	scanf("%d", &resources);

	int allocation[processes][resources], request[processes][resources], available[resources];
	bool finish[processes];

	for(i=0; i<processes; i++) finish[i] = false;

	printf("Enter the allocation matrix\n");
	for(i=0; i<processes; i++)
		for(j=0; j<resources; j++)
			scanf("%d", &allocation[i][j]);

	printf("Enter the request matrix\n");
	for(i=0; i<processes; i++)
		for(j=0; j<resources; j++)
			scanf("%d", &request[i][j]);

	printf("Enter the available vector\n");
	for(i=0; i<resources; i++)
		scanf("%d", &available[i]);

	for(j=0; j<processes; j++)
		for(i=0; i<processes; i++)
		{
			flag=0;
			for(k=0; k<resources; k++)
				if(finish[i] == false && request[i][k] > available[k])
						flag=1;
				
			if(flag==0)
			{
				for(k=0; k<resources; k++)
					available[k] += allocation[i][k];
				finish[i] = true;
			}
		}

	for(i=0; i<processes; i++)
		if(finish[i] == false)
		{
			printf("Deadlock detected\n");
			break;
		}
	if(i==processes) printf("No Deadlock\n");
	return 0;
}