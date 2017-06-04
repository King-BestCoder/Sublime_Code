#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef struct Node{
	int to,from,cost;
	friend bool operator < (const Node&a,const Node&b){
		return a.cost>b.cost;
	}
}node;
node num[50005];
bool cmp(node a,node b){
	return a.cost<b.cost;
}
int f[maxn];
int find(int u){
	if(u==f[u]) return u;
	else return f[u]=find(f[u]);
}
void merge(int a,int b){
	int fa=find(a),fb=find(b);
	if(fa!=fb){
		f[fa]=fb;
	}
}

int main(int argc, char const *argv[])
{
	int n,m,tot=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		f[i]=i;
	priority_queue<node>que;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&num[i].from,&num[i].to,&num[i].cost);
		que.push(num[i]);
	}
	long long ans=0;
	for(int i=0;i<m;i++){
		node p=que.top();
		que.pop();
		int fa=find(p.from),fb=find(p.to);
		if(fa!=fb){
			ans+=p.cost;
			f[fa]=fb;
			tot++;
		}
		if(tot==n-1) break;
	}
	printf("%I64d\n",ans);
	return 0;
}