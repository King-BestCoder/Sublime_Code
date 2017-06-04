#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[10],n,k,pr[10];
void dfs(int pos,int num,int cnt) 
{
	if(num<=1) 
	{
		for(int p=0;p<cnt;p++)
			p==0?printf("%d",pr[p]):printf(" %d",pr[p]);
		printf("\n");
		return ;
	}
	for(int j=pos+1;j<n;j++) 
	{
		pr[cnt]=a[j];    
		dfs(j,num-1,cnt+1); 
	}
	return ;
}
int main()
{
	int t,T;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		int i,j;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		printf("Case #%d:\n",t);
		printf("\n");
		for(k=1;k<=n;k++)  
		{
			memset(pr,0,sizeof(pr)); 
			for(int j=0;j<n-k+1;j++)
			{
				pr[0]=a[j];
				dfs(j,k,1);  
			}
		}
	}
	return 0;
}