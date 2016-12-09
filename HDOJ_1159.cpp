#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int maxn=505;
char a[maxn],b[maxn];
int dp[2][maxn];
int main(int argc, char const *argv[])
{
	while(~scanf("%s %s",a,b)){
		memset(dp,0,sizeof(dp));
		int n=strlen(a),m=strlen(b);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i-1]==b[j-1])
					dp[i%2][j]=dp[(i-1)%2][j-1]+1;
				else
					dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
			}
		}
		printf("%d\n",dp[n%2][m]);
	}
	return 0;
}
