#include<stdio.h>

int main()
{
    int ms,mp[10],i,temp,n=0,ch=1;

    printf("\n Enter the total memory available ");
    scanf("%d",&ms);

    temp=ms;
    for (i=0;ch==1;i++)
    {
        printf("Memory for process %d\n",i+1 );
        scanf("%d",&mp[i]);

        if(mp[i]<=temp)
        {
          printf("Memory allocated \n");
          temp=temp-mp[i];
          n++;
        }
        else
        {
          printf("Memory is full\n");
          break;
        }
        printf("Enter 1 to insert another process\n");
        scanf("%d",&ch);
    }
    printf("Total memory %d\n",ms);
    for (i=0;i<n; i++)
      printf("\n%d  %d",i+1,mp[i]);

    printf("Total memory %d\n",ms-temp);
    printf("External fragmentation %d \n",temp );
}
