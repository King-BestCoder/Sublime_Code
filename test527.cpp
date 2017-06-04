#include <bits/stdc++.h>
using namespace std;
const int maxn=5005;
typedef long long LL;
typedef struct Node{
	int x,y;
	bool friend operator < (Node a,Node b){
		if(a.x<=b.x&&a.y<=b.y) return true;
		else return false;
	}
}node;
node num[maxn];
bool vis[maxn];

bool cmp(const node &a,const node &b){
	if(a.x!=b.x)
		return a.x<b.x;
	else 
		return a.y<b.y;
}
bool ok(const int &n){
	for(int i=0;i<n;i++){
		if(!vis[i]) return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d %d",&num[i].x,&num[i].y);
		}
		sort(num,num+n,cmp);
		int ans=0;
		while(!ok(n)){
			int cur=-1;
			for(int i=0;i<n;i++){
				if(!vis[i]){
					cur=i;
					break;
				}
			}
			vis[cur]=1;
			for(int j=cur+1;j<n;j++){
				if(!vis[j]&&num[cur]<num[j]){
					vis[j]=1;
					cur=j;
				}
			}
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}