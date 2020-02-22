#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void sjf(int n, int bt[])
{
    int i,wt[n],tat[n],j,pos,p[n];

    for(i=0; i<n; i++) p[i]=i+1;

    //Bubble sort
    for(i=0; i<n; i++)
    {
        pos = i;
        for(j=i+1; j<n; j++)
            if(bt[j]<bt[pos])
                pos=j;

        swap(&bt[i], &bt[pos]);
        swap(&p[i], &p[pos]);
    }
        
    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i] = wt[i]+bt[j];
    }

    float avwt = 0.0, avtat = 0.0;
    for(i=0;i<n;i++) {

        tat[i] = bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
    
        printf("P[%d]\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }

    avwt/= n;
    avtat/=n;
    
    printf("Average wait time: %g\n", avwt);
    printf("Average turn around time: %g\n", avtat);
}
int main()
{
    int i,n;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    printf("Enter the Burst times\n");
    int bt[n];
    for(i=0;i<n;i++) scanf("%d",&bt[i]);
    
    sjf(n,bt);
    
    return 0;
}