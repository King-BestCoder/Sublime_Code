#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <string>

using namespace std;
const int maxn=10005;
char a[maxn],b[maxn];
int dp[maxn][maxn];

int main(int argc, char const *argv[])
{
	while(scanf("%s %s",a,b)!=EOF){
		int n=strlen(a),m=strlen(b);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i-1]==b[j-1]){                  		//如果两个字符串有相同的字符
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else{									
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);//如果两个字符串没有相同的字符
				}
			}
		}
		//打印出找到的dp，用string储存
		string s;
		int i=1,j=1;
		for(i=1;i<=n;i++){
			for(j=1;j<m;j++)
				printf("%d ",dp[i][j]);
			printf("%d\n",dp[i][j]);
		}
		i=n,j=m;
	    while(dp[i][j])
	    {
	        if(dp[i][j]==dp[i-1][j]) i--;
	        else if(dp[i][j]==dp[i][j-1]) j--;
	        else {s.push_back(a[i-1]);i--;j--;}
		}
		printf("%d\n",dp[n][m]);
		for(i=s.length()-1;i>=0;i--)
			cout<<s[i];
		cout<<endl;
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
	}
	return 0;
}
