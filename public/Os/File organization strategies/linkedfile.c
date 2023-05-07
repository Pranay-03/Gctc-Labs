#include <stdio.h>
#include<string.h>
int main()
{
    static int b[20],i,j,blocks[20][20];
    char f[20][20],s[20],ch;
    int sb[20],eb[20],x,n;
    
    printf("\nEnter the no of files");
    scanf("%d",&n);
    
     for(i=0;i<n;i++){
       printf("Enter the %d file name \n",i+1);
       scanf("%s",f[i]);
       printf("Enter no of blocks \n");
       scanf("%d",&b[i]);
       
    }
    for(i=0;i<n;i++){
       printf("Enter the starting block of the file %d\n",i+1);
       scanf("%d",&sb[i]);
       printf("Enter blocks for  file %d\n",i+1);
       for(j=0;j<b[i]-1;)
       {
           printf("\n Enter the %d blocks",j-2);
           scanf("%d",&x);
           if(b[i]!=0)
           {
               blocks[i][j]=x;
               j++;
           }
           else
                printf("\n Invslid Block");
       }
    }
    printf("\n Enter the filename");
    scanf("%s",s);
    
    for(i=0;i<n;i++)
    {
        if(strcmp(f[i],s)==0)
        {
            printf("\n Name \t Size\tStart\tBlocks\n");
            printf("\n-------------------------------\n");
            printf("\n%s\t%d\t%d\t",f[i],b[i],sb[i]);
            printf("%d->",sb[i]);
            
            for(j=0;j<b[i];j++)
            {
                if(b[i]!=0)
                    printf("%d->",blocks[i][j]);
            }
        }
    }
    printf("\n--------------------------------------\n");
    return 0;
}

