#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

const int maxn=200005;
int n,m,k;
// int num[maxn];
int c[maxn],cc[maxn],r[maxn];
bool vis[maxn];
vector<int> num[maxn];
int ans=0,cnt=0,mac=0;
void dfs(int u, int ru) {
	cnt++;
	vis[u] = true;
	if (r[c[u]] == ru) cc[c[u]]++;
	else {
		cc[c[u]] = 1;
		r[c[u]] = ru;
	}
	mac = max(mac,cc[c[u]]);
	for (int x : num[u]) if (!vis[x]) dfs(x,ru);
} 
int main(int argc, char const *argv[])
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	int l,ru;
	for(int i=0;i<m;i++){
		scanf("%d %d",&l,&ru);
		num[l].push_back(ru);
		num[ru].push_back(l);
	}
	ans=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			mac=0,cnt=0;
			dfs(i,i);
			ans+=cnt-mac;
		}
	}
	printf("%d\n",ans);
	return 0;
}