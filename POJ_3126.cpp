#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=505;
int dp[maxn],num[maxn][maxn];
int n;
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)
			scanf("%d",&num[i][j]);
	}
	for(int i=1;i<=n;i++)
		dp[i]=num[n][i];
	// for(int i=1;i<=n;i++)
	// 	printf("%d ",dp[i]);
	// printf("\n");
	for(int i=n-1;i>=1;i--){
		for(int j=1;j<=i;j++){
			dp[j]=max(dp[j]+num[i][j],dp[j+1]+num[i][j]);
		}
	}
	printf("%d\n",dp[1]);
	return 0;
}
