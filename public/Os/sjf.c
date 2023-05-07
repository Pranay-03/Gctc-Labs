#include<stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
  int n,pro[20],bursttime[20],waitingtime[20],turnaroundtime[20],i,j,total=0,pos,temp;
  float avg_wait,avg_total;
      printf("enter the total no of processes \n ");
        scanf("%d",&n);
  
    printf("enter the execution time all processes :\n");
    for(i=0;i<n;i++)
        {
   	        printf("proess %d   :",i+1);
   	             scanf("%d",&bursttime[i]);
        	pro[i]=i+1;
        }
        for(i=0;i<n;i++)// sorting the processes in order
        {
            pos=i;
                for(j=i+1;j<n;j++)
                {
                    if(bursttime[j]<bursttime[pos])
                        pos=j;
                }
            swap(&bursttime[i],&bursttime[pos]);
            swap(&pro[i],&pro[pos]);
        }

        waitingtime[0]=0;
        for(i=1;i<n;i++)
        {
            waitingtime[i]=0;
                for(j=0;j<i;j++)
                    waitingtime[i]+=bursttime[j];
            total=total+waitingtime[i];
        }
  avg_wait=total/n;
  total=0;
    printf("Process \t burst time \t waiting time \t turn around time\n");
    for(i=0;i<n;i++)
    {
        turnaroundtime[i]=bursttime[i]+waitingtime[i];
        total+=turnaroundtime[i];
        printf("  %d        \t|  %d        \t|  %d        \t|  %d\n",pro[i],bursttime[i],waitingtime[i],turnaroundtime[i]);
    }
    avg_total=total/n;
    printf("Average waiting time %f\n",avg_wait);
    printf("Average turn around  time %f",avg_total);
}


