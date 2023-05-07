#include<stdio.h>

int main()
{
  int n,bursttime[20],waitingtime[20],turnaroundtime[20],i;
  float averagewait,avergeturn;
  printf("enter the total no of processes \n ");
  scanf("%d",&n);
  
  printf("enter the execution time all processes :\n");
  for(i=0;i<n;i++)
  {
    printf("proess %d   :",i+1);
   	scanf("%d",&bursttime[i]);
  }
  waitingtime[0]=0;
  for( i=1;i<n;i++)
  {
      waitingtime[i]=0;
      for(int j=0;j<i;j++)
             waitingtime[i]=waitingtime[i]+bursttime[j];
  }
  printf("\n processes \t burst time \twaiting time \tturn around time");
  for(i=0;i<n;i++)
  {
      turnaroundtime[i]=bursttime[i]+waitingtime[i];
      averagewait=averagewait+waitingtime[i];
      avergeturn=avergeturn+turnaroundtime[i];
      printf("\n process  %d          \t%d        \t %d          \t %d ",i+1,bursttime[i],waitingtime[i],turnaroundtime[i]);
  }
  averagewait=averagewait/i;
  avergeturn=avergeturn/i;
  printf("\n average waiting time :%f",averagewait);
  printf("\n average turn around time :%f\n",avergeturn); 
}

