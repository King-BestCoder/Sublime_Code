#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
using namespace std;
const int maxn=205;

int dp[maxn][maxn];
int k[maxn][maxn];
int dp1[maxn],dp2[maxn];
int n,x;

int main()
{
	while(~scanf("%d",&n)&&n){
		dp1[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			dp1[i]=dp1[i-1]+x;
		}
		scanf("%d",&dp2[1]);
		for(int i=2;i<=n+1;i++){
			scanf("%d",&x);
			dp2[i]=dp2[i-1]+x;
		}
		for(int i=1;i<=n+1;i++)
			dp[i][i-1]=dp2[i]-dp2[i-1];
		for(int i=1;i<=n;i++)
			dp[i][i]=(dp2[i+1]-dp2[i-1]<<1)+dp1[i]-dp1[i-1],k[i][i]=i;
		for(int i=1;i<n;i++){
			for(int j=1;j<=n-i;j++){
				k[j][i+j]=k[j][i+j-1];
				for(int l=k[j][i+j-1]+1;l<=k[j+1][i+j];l++)
					if(dp[j][k[j][i+j]-1]+dp[k[j][i+j]+1][i+j]>dp[j][l-1]+dp[l+1][i+j])
						k[j][i+j]=l;
				dp[j][i+j]=dp[j][k[j][i+j]-1]+dp[k[j][i+j]+1][j+i]+dp1[i+j]-dp1[j-1]+dp2[i+j+1]-dp2[j-1];
			}
		}
		printf("%d\n",dp[1][n]-dp2[n+1]);
	}
}