#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int p,n;
typedef long long LL;
const int maxn=505;
// const double pi=3.14159265358979323;
int num[maxn][maxn];
int match[maxn];
bool used[maxn];
bool dfs(int u){
	// used[u]=true;
	for(int i=1;i<=n;i++){
		if(!used[i]&&num[u][i]){
			used[i]=true;
			if(match[i]==-1||dfs(match[i])){
				match[i]=u;
				return true;
			}
		}
	}
	return false;
}
int main(int argc, char const *argv[])
{
	int T,t,k;
	scanf("%d",&T);
	while(T--){
		memset(num,0,sizeof(num));
		memset(match,-1,sizeof(match));
		scanf("%d %d",&p,&n);
		for(int i=1;i<=p;i++){
			scanf("%d",&k);
			for(int j=0;j<k;j++){
				scanf("%d",&t);
				num[i][t]=1;
			}
		}
		int ans=0;
		for(int i=1;i<=p;i++){
			memset(used,0,sizeof(used));
			if(dfs(i))
				ans++;
		}
		// printf("%d\n",ans);
		if(ans==p) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}