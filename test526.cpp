#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int num[maxn*maxn];
int ans[maxn][maxn];
bool vis[maxn][maxn];

int main(int argc, char const *argv[])
{
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		for(int i=0;i<m*n;i++)
			scanf("%d",&num[i]);
		int x=0,y=0,cnt=0;
		memset(vis,0,sizeof(vis));
		ans[0][0]=num[cnt++];
		vis[x][y]=1;
		while(cnt<n*m){
             while (y + 1 < m && !vis[x][y + 1]) 
             	ans[x][++y] = num[cnt++] ,vis[x][y]=1;
             while (x + 1 < n && !vis[x + 1][y]) 
             	ans[++x][y] = num[cnt++] ,vis[x][y]=1;
             while (y - 1 >= 0 && !vis[x][y - 1]) 
             	ans[x][--y] = num[cnt++] ,vis[x][y]=1;
             while (x - 1 >= 0 && !vis[x - 1][y])
             	ans[--x][y] = num[cnt++] ,vis[x][y]=1;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				printf("%d%c",ans[i][j],j==m-1?'\n':' ');
			}
		}
	}
	return 0;
}