#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1122;
int dp[maxn][13];
int su[maxn],num[maxn],cnt;

int main()
{
	memset(dp,0,sizeof(dp));
	for(int i=1;i<maxn;i++) su[i]=1;
	dp[0][0]=1;
	cnt=1;
	for(int i=2;i<maxn;i++){
		if(su[i]){
			num[cnt++]=i;
			for(int j=i<<1;j<maxn;j+=i){
				su[j]=0;
			}
		}
	}
	for(int i=1;i<maxn;i++){
		
	}
	int n,k;
	while(~scanf("%d %d",&n,&k)){
		if(!n&&!k) break;
		printf("%d\n",dp[n][k]);
 	}
	return 0;
}