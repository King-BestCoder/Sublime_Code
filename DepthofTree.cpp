#include <stdio.h>
int main()
{
	int i,n,l,r,k=0,t,m,parent[10005];
	scanf("%d",&n);
	parent[1]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		if(l!=0)parent[l]=i;
		if(r!=0)parent[r]=i;
	}
	for(t=1;t<=n;t++)
	{
		m=1;i=t;
	while(parent[i]!=0)
	{m++;i=parent[i];}
	if(m>k)k=m;
	}
	printf("%d",k);
        return 0;
}