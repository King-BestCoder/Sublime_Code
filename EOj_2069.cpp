#include <bits/stdc++.h>
using namespace std;
const int maxn=505;
int n,m;
int matched[maxn];
int used[maxn];
int num[maxn][maxn];
bool dfs(int u){
	for(int i=1;i<=n;i++){
		if(num[i][u]&&!used[i]){
			used[i]=1;
			if(matched[i]==-1||dfs(matched[i])){
				matched[i]=u;
				return true;
			}
		}
	}
	return false;
}
int main(int argc, char const *argv[])
{
	while(scanf("%d %d",&n,&m)==2){
		int a,b;
		memset(num,0,sizeof(num));
		for(int i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			num[a][b]=1;
		}
		int ans=0;
		memset(matched,-1,sizeof(matched));
		for(int i=1;i<=n;i++){
			memset(used,0,sizeof(used));
			if(dfs(i)) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}