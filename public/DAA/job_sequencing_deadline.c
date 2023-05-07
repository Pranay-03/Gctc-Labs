#include<stdio.h>
int n,i,j,k,t;
int swap(int *a,int *b)
{
    int temp=*a;
        *a=*b;
        *b=temp;
}
int check(int s[],int p)
{
    int ptr=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==p)
                ptr++;
        }           
        if(ptr==0)
            return 1;
        else
            return 0;
}    
                     
int main()
{  
    printf("enter the no of jobs      : ");
    scanf("%d",&n);
    int slot[20]={0},profit,p[n],d[n],total=0;
    for(i=0;i<n;i++)
    {
        printf("\n enter the profit of job %d      :",i+1);
        scanf("%d",&p[i]);                 
        printf("\n enter the deadline of job %d    :",i+1);
        scanf("%d",&d[i]);
    }
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(p[i]<p[j])
            {
                swap(&p[i],&p[j]);
                swap(&d[i],&d[j]);
            }
    for(i=0;i<n;i++)
         for(j=d[i];j>0;j--)
             {
                if(check(slot,j)==1)
                {
                    slot[i]=j;
                    break;
                } 
             }
     printf("\n\n INDEX   PROFIT  DEADLINE  SLOT ALLOTTED ");      
     for(i=0;i<n;i++)
     {
        if(slot[i]>0)
        {
            printf("\n\n   %d       %d        %d    [%d - %d]", i+1,p[i],d[i],(slot[i]-1),slot[i]);
            total=total+p[i];
        }
        else
            printf("\n\n   %d       %d        %d    REJECTED", i+1,p[i],d[i]);
     }
     printf("\n\n Total profit is : %d",total);
}   
