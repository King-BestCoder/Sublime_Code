#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=1005;
int num[maxn];
int dp[maxn];

int main(int argc, char const *argv[])
{
	int n;
	while(~scanf("%d",&n)&&n){
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		// dp[1]=num[1];
		for(int i=1;i<=n;i++){
			dp[i]=num[i];
			for(int j=1;j<i;j++){
				if(num[j]<num[i]){
					dp[i]=max(dp[i],dp[j]+num[i]);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			ans=max(ans,dp[i]);
		printf("%d\n",ans);
	}
	return 0;
}
