#include <bits/stdc++.h>
using namespace std;
const int maxn=333;
char s[maxn][maxn];
int n,c;
int vis[maxn][maxn];
const int dx[]={0,0,-1,1};
const int dy[]={1,-1,0,0};

int dfs(int i,int j){
	if(vis[i][j]==0||vis[i][j]==1) return vis[i][j];
	if(s[i][j]=='.'){
		vis[i][j]=1;
		return 1;
	}
	if(s[i][j]=='^'){
		if(i-1>=0) vis[i][j]=dfs(i-1,j);
		else vis[i][j]=0;
	}	
	else if(s[i][j]=='>'){
		if(j+1<c)	vis[i][j]=dfs(i,j+1);
		else vis[i][j]=0;
	}
	else if(s[i][j]=='<'){
		if(j-1>=0) vis[i][j]=dfs(i,j-1);
		else vis[i][j]=0;
	}
	else{
		if(i+1<n) vis[i][j]=dfs(i+1,j);
		else vis[i][j]=0;
	}
	return vis[i][j];
}

void change(int i,int j){

}

int main(int argc, char const *argv[])
{
	while(~scanf("%d %d",&n,&c)){
		memset(vis,-1,sizeof(vis));
		for(int i=0;i<n;i++)
			scanf("%s",s[i]);
		for(int i=0;i<n;i++){
			for(int j=0;j<c;j++){
				dfs(i,j);
			}
		}
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<c;j++){
				if(i==0||j==0||i==n-1||j==c-1){
					if(vis[i][j]==0){
						ans++;
					}
				}
			}
		}	
		printf("%d\n",ans);
	}
	return 0;
}