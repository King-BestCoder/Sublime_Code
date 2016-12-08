#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
typedef long long LL;
const int maxn=1000005;
const LL mod=1e10;

int num[maxn];
LL ans=0;
LL n;

void solve(){
	for(int i=1;i<=maxn;i++){
		num[i]++;
		for(int j=1;j<=i;j++){
			int t=i-j;

		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%I64d",&n);
	solve();
	printf("%I64d\n",ans);
	return 0;
}