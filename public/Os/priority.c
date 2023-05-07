#include<stdio.h> 

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
        int bt[20],p[20],wt[20],tat[20],pr[20];
        int i,j,n,total=0,pos,temp,avg_wt,avg_tat;

        printf("Enter Total Number of Process:");
        scanf("%d",&n);
        printf("\nEnter Burst Time and Priority\n"); 
        for(i=0;i<n;i++)
        {
            printf("\nP[%d]\n",i+1); 
            printf("Burst Time:"); 
            scanf("%d",&bt[i]);
            printf("Priority:"); 
            scanf("%d",&pr[i]);
            p[i]=i+1;	//contains process number
        }
//sorting burst time, priority and process number in ascending order using selection sort 
    for(i=0;i<n;i++)
    {
        pos=i; 
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos]) 
                pos=j;
        }
        swap(&pr[i],&pr[pos]);

        swap(&bt[i],&bt[pos]);

        swap(&p[i],&p[pos]);
    }

wt[0]=0; //waiting time for first process is zero
//calculate waiting time 
    for(i=1;i<n;i++)
    {
        wt[i]=0; 
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        total+=wt[i];
    }

    avg_wt=total/n;	//average waiting time total=0;

    printf("\nProcess\t	Burst Time	\tWaiting Time\tTurnaround Time"); 
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];	//calculate turnaround time total+=tat[i];
        printf("\nP[%d]\t\t %d\t\t	%d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }

    avg_tat=total/n;
    //average turnaround time 
    printf("\n\nAverage Waiting Time=%d",avg_wt); 
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
}
