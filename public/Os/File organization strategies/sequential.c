#include<stdio.h>

int main()
{
    char name[10][10];
    int start[10],length[10],num;
    
    printf("\nEnter the no of files :");
    scanf("%d",&num);
    
    int count=0;
    int i,j,k;
    
    for(i=0;i<num;i++)
    {
        printf("\nEnter the name of file %d :",i+1);
        scanf("%s",&name[i][0]);
        
        printf("\nEnter the start block of the file %d :",i+1);
        scanf("%d",&start[i]);
        
        printf("\nenter the lenght of the file  %d:",i+1);
        scanf("%d",&length[i]);
        
        
        for(j=0,k=1;j<num &&k<num;j++,k++)
        {
            if(start[j+1] <=start[j] || start[j+1] >=length[j])
            {
                
            }
            else
                count++;
        }
        
        if(count==1)
            printf("\n%s cannot be allocated ",name[i]);
    }
    
    printf("\nFile allocation table \n");
    printf("File name\tStart Block \tLength\n");
    printf("%s\t\t      %d\t\t      %d\t\t\n",name[0],start[0],length[0]);
    
    for(i=0,j=1;i<num &&j<num;i++,j++)
    {
        if(start[i+1] <=start[i] || start[i+1] >=length[i])
            printf("%s\t\t      %d\t\t      %d\t\t\n",name[j],start[j],length[j]);
    }
    
}
