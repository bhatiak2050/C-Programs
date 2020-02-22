#include<stdio.h>

void fcfs(int n, int bt[n]) 
{
    int i, j, wt[n], tat[n];
   
    wt[0] = 0;
    for(i=1; i<n; i++)
    {
        wt[i] = 0;
        for(j=0; j<i; j++)
            wt[i] += bt[j];
    }

    float avwt = 0.0, avtat = 0.0;
    printf("Process \tBurst Time \tWaiting Time \tTurnaround Time\n");
    for(i=0; i<n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];

        printf("P[%d]\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }
    
    printf("Average wait time: %g\n", avwt/n);
    printf("Average turn around time: %g\n", avtat/n);
}

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int i, bt[n];

    printf("Enter the burst times:\n");
    for(i=0; i<n; i++) 
        scanf("%d", &bt[i]);

    fcfs(n, bt);
    return 0;
}