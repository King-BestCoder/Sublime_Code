#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <stack>
using namespace std;
const int maxn=205;
const int inf=(1<<30)-1;
int dp[maxn][maxn];
int sum[maxn][maxn];
int p[maxn],q[maxn];
int n;
int main(int argc, char const *argv[])
{
	while(~scanf("%d",&n)&&n){
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		for(int i=0;i<=n;i++)
			scanf("%d",&q[i]);
		for(int i=1;i<=n;i++)
			sum[i][i]=p[i]+q[i]+q[i-1];
		for(int i=1;i<=n+1;i++){
			dp[i][i-1]=0;
			sum[i][i-1]=q[i-1];
		}
		for(int i=1;i<n;i++)
			for(int j=1;j+i<=n;j++)
				sum[j][i+j]=sum[j][i+j-1]+p[i+j]+q[i+j];
		for(int d=0;d<n;++d)
			for(int i=1;i+d<=n;i++){
				int j=i+d;
				int minx=inf;
				for(int r=i;r<=j;++r)
					minx=min(minx,dp[i][r-1]+dp[r+1][j]);
				dp[i][j]=minx+sum[i][j];
			}	
		printf("%d\n",dp[1][n]);
	}
	return 0;	
}