#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
LL cnt(LL n){
	if(n==1)
		return 0;
	LL ans=0;
	for(LL i=2;i*i<=n;i++)
		if(n%i==0) ans++;
	return ans;
}
int main(int argc, char const *argv[])
{
	LL n;
	scanf("%I64d",&n);
	LL ans=cnt(n);
	if(ans) printf("F\n");
	else printf("T\n");
	return 0;
}
