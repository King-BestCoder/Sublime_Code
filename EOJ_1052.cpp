#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;
typedef long long LL;
const int maxn=100005;
int n,m;
int w[21],v[21];
int dp[maxn];
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while(T--) {
		memset(dp,0,sizeof(dp));
		int n;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d %d",&w[i],&v[i]);
		for(int i=1;i<=n;i++){
			for(int j=m;j>=w[i];j--){
				dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
			}
		}
		printf("%d\n",dp[m]);
}
	return 0;
}