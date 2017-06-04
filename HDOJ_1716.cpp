#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
	int x,id;
	friend bool operator < (const Node &a,const Node &b){
		return a.x<b.x;
	};
}node;

int main(int argc, char const *argv[])
{
	int n;
	while(~scanf("%d",&n)){
		priority_queue<node>que;
		int t;
		node p;
		for(int i=0;i<n;i++){
			scanf("%d",&t);
			p.x=t,p.id=i;
			que.push(p);
		}
		int vis[3005];
		int ans=0;
		memset(vis,0,sizeof(vis));
		
	}
	return 0;
}