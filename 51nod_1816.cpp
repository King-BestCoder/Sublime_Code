#include <bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
int x[maxn],y[maxn];
int used[maxn],matched[maxn];
bool dfs(int u){

}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&x[i],&y[i]);
	}
	sort(x,x+n);
	sort(y,y+n);
	int ans=0;
	memset(matched,-1,sizeof(matched));
	for(int i=0;i<n;i++){
		memset(used,0,sizeof(used));
		if(dfs(i)){
			ans++;
		}
	}

	return 0;
}