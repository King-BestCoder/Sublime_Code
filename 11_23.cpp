#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn=105;
int num[maxn][maxn];
const int mod=1e9+7;
void solve(){
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			if(i==0||j==0) num[i][j]=1;
			else num[i][j]=(num[i-1][j]+num[i][j-1])%mod;
		}
	}
}
int main(int argc, char const *argv[])
{
	solve();
	int T;
	scanf("%d",&T);
	while(T--) {
		int x,y;
		scanf("%d %d",&x,&y);
		int ans=x;
		for(int i=1;i<=y;i++){
			ans=(ans+num[x][i])%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}