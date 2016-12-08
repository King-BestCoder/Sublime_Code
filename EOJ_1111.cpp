#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;
typedef long long LL;

int num[105][105];
int dp[105][105];

int main(int argc, char const *argv[])
{
	int T,n;
	// int n;
	scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof(dp));
		memset(num,0,sizeof(num));
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			for(int j=0;j<=i;j++){
				scanf("%d",&num[i][j]);
			}
		}
		// LL sum=0;
		for(int i=0;i<n;i++)
			dp[n-1][i]=num[n-1][i];
		for(int i=n-1;i>0;i--){
			for(int j=0;j<i;j++){
				if(dp[i][j]>=dp[i][j+1]){
					dp[i-1][j]=num[i-1][j]+dp[i][j+1];
				}
				else{
					dp[i-1][j]=num[i-1][j]+dp[i][j];
				}
			}
		}
		// for(int i=0,j;i<n;i++){
		// 	for(j=0;j<i;j++)
		// 		printf("%d ",num[i][j]);
		// 	printf("%d\n",num[i][j]);
		// }
		// for(int i=0,j;i<n;i++){
		// 	for(j=0;j<i;j++)
		// 		printf("%d ",dp[i][j]);
		// 	printf("%d\n",dp[i][j]);
		// }
		printf("%d\n",dp[0][0]);
	}	
	return 0;
}
