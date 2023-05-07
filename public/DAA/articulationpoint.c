#include<stdio.h>
int df[20],l[20],adj[20][20]={0};
int num=1,vertex,start=1;

int min(int a,int b)
{
	if(a>b)
		return b;
	else
		return a;
}
void art(int u,int v)
{
  int w;
  df[u]=l[u]=num;
  num++;
	for(w=1;w<=vertex;w++)
	{
		if(adj[u][w]==1)
		{
			if(df[w]==0)
			{
				art(w,u);
				if(u!=start &&l[w]>=df[u])  
					printf("\n%d is articulation point\n",u);
				l[u]=min(l[u],l[w]);
			}
			else if (w!=v)
				l[u]=min(l[u],df[w]);
		}
	}
}
int main()
{
    int i,j,temp;
    printf("Enter the no of vertex in  graph  : ");
    scanf("%d",&vertex);
    for(i=1;i<=vertex;i++)
    {
    	printf("enter the vertex conneted to %d(-1 to move to next vertex)\n",i);
      	while(1)
      	{
        	printf("\tenter the vertices: ");
        	scanf("%d",&temp);
        		if(temp==-1)
        			break;
        		else if(temp>vertex || temp<-1)
        			printf("\n please enter valid vertex");
        		else if(temp)
        			adj[i][temp]=1;
      	}
   }
	art(1,0);
	int u,w;
		for(i=1;i<=vertex;i++)
			printf("%d ",l[i]);
	printf("\n");
		for(i=1;i<=vertex;i++)
			printf("%d ",df[i]);
}
