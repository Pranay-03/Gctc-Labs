#include<stdio.h>
int df[20],l[20],adj[20][20]={0};
int num=1,vertex,start=1,top=-1;

struct edge
{
    int u;
    int v;
};
struct edge s[20];
void push(struct edge e)
{
    s[++top]=e;
}
struct edge pop()
{
    return s[top--];
}
int EdgeEquals(struct edge s,struct edge t)  // function to test equality of edges
{
	if(s.u==t.u && s.v==t.v)
		return 1;
	else if(s.u==t.v && s.v==t.u)
		return 1;
	else
		return 0;
}
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
            if(w!=v && df[w]<df[u])
			{
				struct edge t={u,w};
				push(t);
			}
			if(df[w]==0)
			{
				art(w,u);
				if(u!=start &&l[w]>=df[u])  
                {
					struct edge t;
					struct edge s={u,w};
					printf("Found a Bicomponent\n");
					do
					{
						t=pop();
						printf("(%d,%d)\n",t.u,t.v);
					}while(!EdgeEquals(t,s));
				}
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
    printf("Found a Bicomponent\n");
	while(top>=0)
	{
		struct edge x=pop();
		printf("(%d,%d)\n",x.u,x.v);
	}
	int u,w;
		for(i=1;i<=vertex;i++)
			printf("%d ",l[i]);
	printf("\n");
		for(i=1;i<=vertex;i++)
			printf("%d ",df[i]);
}
