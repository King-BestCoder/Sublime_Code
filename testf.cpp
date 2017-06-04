#include <bits/stdc++.h>
using namespace std;
const int maxn=2e3+3;
typedef long long LL;

int lcs[maxn][maxn],dp[maxn][maxn];
char a[maxn],b[maxn];
 
int main(int argc, char const *argv[])
{
    int n, k;
    while (~scanf("%d %d", &n, &k)){
    	getchar();
        scanf("%s %s",a,b);
        memset(lcs,0,sizeof(lcs));
        memset(dp,0,sizeof(dp));
        for(int i=n-1; i>=0;i--){
            for(int j =n-1;j>=0;j--){
                if(a[i]==b[j]) lcs[i][j]=lcs[i+1][j+1]+1;
            }
        }
        // for(int i=0;i<n;i++){
        // 	for(int j=0;j<n;j++){
        // 		printf("%d%c",lcs[i][j],j==n-1?'\n':' ');
        // 	}
        // }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (lcs[i][j]>=k){
                    if(i>=k&&j>=k)
                        dp[i][j]=dp[i-k][j-k]+1;
                    else
                        dp[i][j]=1;
                }
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }
        }
        // for(int i=0;i<n;i++){
        // 	for(int j=0;j<n;j++){
        // 		printf("%d%c",dp[i][j],j==n-1?'\n':' ');
        // 	}
        // }
        printf("%d\n",dp[n-1][n-1]);
    }
    return 0;
}