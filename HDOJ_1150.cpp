#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,m,k;
int matched[maxn];
int num[maxn][maxn];
int used[maxn];
int x[maxn],y[maxn];
bool dfs(int u){
	for(int v=1;v<m;v++){
		if(num[u][v]&&!used[v]){
			used[v]=1;
			if(y[v]==-1||dfs(y[v])){
				x[u]=v;
				y[v]=u;
				return true;
			}
		}
	}
	return false;
}
int main(int argc, char const *argv[])
{
	while(~scanf("%d",&n)&&n){
		scanf("%d %d",&m,&k);
		int t,a,b;
		memset(num,0,sizeof(num));
		memset(matched,-1,sizeof(matched));
		memset(x,-1,sizeof(x));
		memset(y,-1,sizeof(y));
		for(int i=0;i<k;i++){
			scanf("%d %d %d",&t,&a,&b);
			num[a][b]=1;
		}
		int ans=0;
		for(int i=1;i<n;i++){
			if(x[i]==-1){
				memset(used,0,sizeof(used));
				if(dfs(i)) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}