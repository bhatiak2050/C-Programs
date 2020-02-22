#include<stdio.h>
#include<stdbool.h>
#define and &&
#define pf ;printf
#define sf ;scanf

int main()
{
	pf("Enter the no of processes: ");
	int processes; sf("%d", &processes);

	pf("Enter the no of resources: ");
	int resources; sf("%d", &resources);

	int allocation[processes][resources], max[processes][resources], need[processes][resources];
	int available[resources];
	bool completed[processes];

	for (int i = 0; i < processes; ++i)
		completed[i] = false;

	pf("Enter the allocation matrix: \n");
	for (int i = 0; i < processes; ++i)
		for (int j = 0; j < resources; ++j)
			sf("%d", &allocation[i][j]);

	pf("Enter the max matrix: \n");
	for (int i = 0; i < processes; ++i)
		for (int j = 0; j < resources; ++j)
		{
			sf("%d", &max[i][j]);
			need[i][j] = max[i][j] - allocation[i][j];
		}

	pf("Enter the available vector: ");
	for (int i = 0; i < resources; ++i)
		sf("%d", &available[i]);

	int count1=0, count2=0, k=0;

	pf("The safe sequence is: \n");
	while(count1!= processes)
	{
		for (int i = 0; i < processes; ++i)
		{
			for (int j = 0; j < resources; ++j)
				if(need[i][j] <= available[j])
					k++;

			if(k==resources and completed[i] == false)
			{
				count1++;
				completed[i] = true;
				pf("p[%d]\n", i);
				for (int j = 0; j < resources; ++j)
					available[j] += allocation[i][j];
			}
			k=0;
		}
		if(count2 == count1)
		{
			pf("stop... afterthis...deadlock\n");
			break;
		}
	}
	return 0;
}