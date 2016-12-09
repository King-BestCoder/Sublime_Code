#include <stdio.h>
const int maxn=1005;
int num[maxn];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&num[i]);
	for(int i=n-1;i>=0;i--)
		printf("%d%c",num[i],i==0?'\n':' ');
	return 0;
}