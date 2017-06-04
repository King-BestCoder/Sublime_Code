#include <bits/stdc++.h>
// #define test TEST
using namespace std;

typedef long long LL;
const LL mod=1e9+7;
const int maxn=1005;

int num[maxn][maxn];
int dp[maxn][maxn];


int main(int argc, char const *argv[])
{
	#ifdef test
	freopen("test.txt","r",stdin);
	#endif

	int n,m,h;
	while(~scanf("%d %d %d",&n,&m,&h)){
		memset(num,0,sizeof(num));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&num[i][j]);
			}
		}
		memset(dp,-1,sizeof(dp));
		dp[0][0]=num[0][0]+h;
		for(int i=1;i<n;i++){
			if(dp[i-1][0]>=0){
				dp[i][0]=dp[i-1][0]+num[i][0];
			}
			else break;
		}
		for(int i=1;i<m;i++){
			if(dp[0][i-1]>=0){
				dp[0][i]=dp[0][i-1]+num[0][i];
			}
			else break;
		}
		int flag=0;
		for(int i=1;i<n;i++){
			for(int j=1;j<m;j++){
				if(dp[i-1][j]>=0){
					dp[i][j]=max(dp[i][j],dp[i-1][j]+num[i][j]);
					if(i==n-1&&j==m-1&&dp[i][j]>=0) flag=1;
				}
				if(dp[i][j-1]>=0){
					dp[i][j]=max(dp[i][j],dp[i][j-1]+num[i][j]);
					if(i==n-1&&j==m-1&&dp[i][j]>=0) flag=1;
				}
			}
		}
		if(flag){
			printf("%d\n",dp[n-1][m-1]);
		}
		else{
			printf("-1\n");
		}
	}
	return 0;
}