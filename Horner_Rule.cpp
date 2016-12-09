#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
typedef long long LL;

int main(int argc, char const *argv[])
{
	LL n,x;
	scanf("%I64d",&n);
	LL *num=new LL[n];
	for(LL i=0;i<n;i++)
		scanf("%I64d",&num[i]);
	scanf("%I64d",&x);
	LL sum=0;
	for(LL i=n-1;i>=0;i--)
		sum=num[i]+x*sum;
	printf("%I64d\n",sum);
	return 0;
}
