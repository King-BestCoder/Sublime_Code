#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;
typedef long long LL;
const int maxn=505;
int num[maxn][maxn];
int dp[maxn][maxn];
int dp1[maxn][maxn];
int main(int argc, char const *argv[])
{
	int T,n;
	scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof(dp));
		memset(dp1,0,sizeof(dp1));
		memset(num,0,sizeof(num));
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			for(int j=0;j<=i;j++){
				scanf("%d",&num[i][j]);
			}
		}
		for(int i=0;i<n;i++)
			dp[n-1][i]=num[n-1][i];
		for(int i=n-2;i>=0;i--){
			for(int j=0;j<=i;j++)
				dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+num[i][j];
		}
		dp1[0][0]=num[0][0];
		for(int i=1;i<n;i++){
			dp1[i][0]=dp1[i-1][0]+num[i][0];
			dp1[i][i]=dp1[i-1][i-1]+num[i][i];
			for(int j=1;j<i;j++){
				dp1[i][j]=max(dp1[i-1][j],dp1[i-1][j-1])+num[i][j];
			}
		}
		// for(int i=0;i<n;i++)
		// 	for(int j=0;j<=i;j++)
		// 		printf("%d%c",dp[i][j],i==j?'\n':' ');
		// for(int i=0;i<n;i++)
		// 	for(int j=0;j<=i;j++)
		// 		printf("%d%c",dp1[i][j],i==j?'\n':' ');
		int sum=0;
		int hou=0,xian=0;
		for(int i=1;i<n;i++){
			xian=0;
			hou=0;
			for(int j=0;j<i;j++)
				xian=max(xian,dp1[i-1][j]);
			for(int j=0;j<=i;j++)
				hou=max(hou,dp[i][j]);
			sum=max(sum,xian+hou);
		}
		printf("%d\n",sum);
	}	
	return 0;
}