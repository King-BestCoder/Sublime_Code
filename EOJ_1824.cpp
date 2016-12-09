#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=115;
int num[maxn][maxn];
int dp[maxn][maxn][10];

int main(int argc, char const *argv[])
{
	int n,T;
	scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof(dp));
		memset(num,0,sizeof(num));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				scanf("%d",&num[i][j]);
		for(int i=1;i<=n;i++)
			dp[n][i][num[n][i]%10]=1;
		for(int i=n;i>=1;i--){
			for(int j=1;j<=i;j++){
				for(int k=0;k<=9;k++){
					if(dp[i][j][k]){
						dp[i-1][j-1][k+(num[i-1][j-1])%10]=1;
						dp[i-1][j][(k+num[i-1][j])%10]=1;
					}
				}
			}
		}

		int ans=0;
		for(int i=1;i<=9;i++){
			if(dp[1][1][i]&&i>ans)
				ans=i;
		}
		printf("%d\n",ans);
		// int i,j;
		// for(i=0;i<n;i++){
		// 	for(j=0;j<i;j++)
		// 		printf("%d ",num[i][j]);
		// 	printf("%d\n",num[i][j]);
		// }
		// for(i=0;i<n;i++){
		// 	for(j=0;j<i;j++)
		// 		printf("%d ",dp[i][j]);
		// 	printf("%d\n",dp[i][j]);
		// }
		// int ans=-0x3f3f3f;
		// for(i=0;i<n;i++)
		// 	ans=max(ans,dp[n-1][i]);
		// printf("%d\n",ans%10);
	}
	return 0;
}
