#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void priority(int n, int bt[], int pr[])
{
    int i,wt[n],tat[n],j,pos,p[n];

    for(i=0; i<n; i++) p[i]=i+1;

    //bubble sort code
    for(i=0; i<n; i++)
    {
        pos = i;
        for(j=i+1; j<n; j++)
            if(pr[j]>pr[pos])
                pos=j;

        swap(&bt[i], &bt[pos]);
        swap(&pr[i], &pr[pos]);
        swap(&p[i], &p[pos]);
    }
        
    //adjusting the wait times
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i] += bt[j];
    }

    //performing scheduling
    float avwt = 0.0, avtat = 0.0;
    printf("Process \tBurst Time \tWaiting Time \tTurnaround Time\n");
    for(i=0;i<n;i++)
    {

        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
    
        printf("P[%d]\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }

    avwt/= n;
    avtat/=n;
    
    printf("Average wait time: %g\n",avwt);
    printf("Average turn around time: %g\n", avtat);
}
int main()
{
    int n;
    printf("Enter the number of processes: \n");
    scanf("%d", &n);

    int i, bt[n], pr[n];
    printf("Enter the Burst times and priorities\n");
    
    for(i=0;i<n;i++) 
    {
        scanf("%d",&bt[i]);
        scanf("%d",&pr[i]);
    }
    
    priority(n, bt, pr);
    
    return 0;
}