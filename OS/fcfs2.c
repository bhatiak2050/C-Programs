#include<stdio.h>

void main()
{
    int bt[20],p[20],at[20],wt[20],tat[20],ct[20],p_no,atat,awt,i;
    printf("Enter the number of process\n");
    scanf("%d",&p_no);
    printf("Enter the Brust time and arrival time in sequence\n");
    wt[0],ct[0],tat[20],tat[19],wt[19],wt[20],atat,awt=0;
    int tat_s,wt_s=0;
    for(int i=1;i<=p_no;i++)
    {
        scanf("%d",&bt[i]);
        scanf("%d",&at[i]);
    }
    for(int j=1;j<=p_no;j++)
    {
        
        ct[j] = bt[j]+ct[j-1];
        tat[j]= ct[j]-at[j];
        wt[j]=tat[j]-bt[j];
        
        //tat[19]=tat[19]+at[j]+tat[j-1];
        //wt[19]= wt[19]+wt[j]+wt[j-1];
    }
     for(int j=1;j<=p_no;j++)
    {
        tat_s=tat_s+tat[j];
        wt_s=wt_s+wt[j];
    }
    atat=(tat_s/p_no);
    awt=(wt_s/p_no);
    printf("ATAT is %d \n",atat);
    printf("AWT is %d\n",awt);

//test
    for(i=1;i<=p_no;i++)
{   
    printf("at[i] %d %d\n",i,at[i]);
    printf("bt[i] %d %d\n",i,bt[i]);
    printf("ct[i] %d %d\n",i,ct[i]);
    printf("tat[i] %d %d\n",i,tat[i]);
    printf("wt[i] %d %d\n",i,wt[i]);
    printf("tat_s %d %d\n",i,tat_s);
    printf("wt_s %d %d\n",i,wt_s);
    printf("ATAT is %d %d \n",i,atat);
    printf("AWT is %d %d\n",i,awt);

}
}
