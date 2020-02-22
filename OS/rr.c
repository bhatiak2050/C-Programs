#include<stdio.h>
#include<stdbool.h>
#define and &&

int main()
{
	int count, i, n, time, remain, time_quantum, at[10];
	int wt=0, tat=0, bt[10], rt[10];
	bool finished = false;

	printf("Enter no of processes: ");
	scanf("%d", &n);

	remain=n;

	for(i=0; i<n; i++)
	{
		printf("BT for process no %d: ", i+1);
		scanf("%d", &bt[i]);
		rt[i] = bt[i];
		at[i] = 0;
	}

	printf("Enter the time_quantum: ");
	scanf("%d", &time_quantum);

	printf("\nProcess\tTAT\tWT\t\n");
	for(i=0, time=0; remain!=0; )
	{
		if(rt[i] <= time_quantum and rt[i] > 0)
		{
			time += rt[i];
			rt[i] = 0;
			finished = true;
		}
		else if(rt[i] > 0)
		{
			rt[i] -= time_quantum;
			time += time_quantum;
		}
		if(rt[i] == 0 and finished == true)
		{
			remain--;
			printf("P[%d]\t%d\t%d\n", i+1, time-at[i], time-at[i]-bt[i]);
			tat += time - at[i];
			wt += time - at[i] - bt[i];
			finished = false;
		}
		
		if(i == n-1) i=0;
		else if(at[i+1] <= time) i++;
		else i=0;

		// if(i == n-1) i=0;
		// else i++;
	}
	printf("Average wait time = %g\n", wt * 1.0/n);
	printf("Average turnaround time = %g\n", tat * 1.0/n);
	return 0;
}