#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn=31;
int w[maxn];
int dp[maxn][20005];
//装箱问题  EOJ_1113
int main(int argc, char const *argv[])
{
	int n,m;
	while(~scanf("%d",&m)){
		scanf("%d",&n);
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			scanf("%d",&w[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<=m;j++){
				if(j<w[i])
					dp[i+1][j]=dp[i][j];
				else
					dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+w[i]);
			}
		}
		printf("%d\n",m-dp[n][m]);
	}
	return 0;
}
