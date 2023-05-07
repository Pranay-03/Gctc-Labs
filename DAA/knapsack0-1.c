#include<stdio.h>
int max(int a, int b) 
{
   if(a>b)
      return a;
   else 
      return b;
}	
int knapsack(int W, int wt[], int val[], int n) {
   int i, w;
   int knap[n+1][W+1];
   
   for (i = 0; i <= n; i++) 
	  for (w = 0; w <= W; w++) {
	     	if (i==0 || w==0)
            		knap[i][w] = 0;
		else if (wt[i-1] <= w)
            		knap[i][w] = max(val[i-1] + knap[i-1][w-wt[i-1]], knap[i-1][w]);
		else
            		knap[i][w] = knap[i-1][w];
      }
   return knap[n][W];
}
int main() 
{
	int n,w,i;
	int val[100],wt[100];
	printf("\nEnter the no of objects :");
	scanf("%d",&n);
	printf("\n");
	printf("**************PROFIT*******************");
	for(i=0;i<n;i++){
		printf("\nEnter the profit of %d :",i+1);
		scanf("%d",&val[i]);
	}
	printf("\n");
	printf("**************WEIGHT*******************");
	for(i=0;i<n;i++){
	    printf("\nEnter the weight of %d :",i+1);
	    scanf("%d",&wt[i]);
	}
	printf("\n");	
	printf("Enter the capacity :");
	scanf("%d",&w);
    printf("The solution is : %d", knapsack(w, wt, val, n));
    return 0;
}
