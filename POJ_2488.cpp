#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
const int dx[]={-2,-2,-1,-1,1,1,2,2};
const int dy[]={-1,1,-2,2,-2,2,-1,1};
const int maxn=50;
int used[maxn][maxn];
int path[maxn*maxn][3];
int flag=0;
typedef pair<int,int>pii;
vector<pii>vec;
void dfs(int tx,int ty,int sum){
	// printf("%d %d\n",tx,ty);
	if(sum==n*m){
		for(int i=0;i<sum;i++){
			printf("%c%d",path[i][0]+'A'-1,path[i][1]);
		}
		printf("\n\n");
		flag=1;
		return ;
	}
	for(int i=0;i<8;i++){
		int nx=tx+dx[i],ny=ty+dy[i];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!used[nx][ny]){
			used[nx][ny]=1;
			path[sum][0]=nx,path[sum][1]=ny;
			dfs(nx,ny,sum+1);
			used[nx][ny]=0;
			if(flag) return ;
		}
	}
}
void judge(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(used[i][j]==0){
				flag=0;
				return ;
			}
		}
}
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d %d",&m,&n);
		memset(used,0,sizeof(used));
		memset(path,0,sizeof(path));
		printf("Scenario #%d:\n",t);
		used[1][1]=1;
		flag=0;
		path[0][0]=1,path[0][1]=1;
		dfs(1,1,1);
		// judge();
		if(!flag) printf("impossible\n\n");
	}
	return 0;
}