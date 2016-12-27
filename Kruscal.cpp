// #include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long LL;
const int maxn=1005;
const int maxm=500005;
int F[maxn];
int high[maxn];
typedef struct Node{
	int u,v;
	double w;
	Node(int u1=0,int v1=0,double w1=0){
		u=u1,v=v1,w=w1;
	}
	friend bool operator < (const Node &x,const Node& y){
		return x.w>y.w;
	}
}node;
node edge[maxm];
node point[maxn];
int n,m;
int find(int x){
	if(F[x]==x) return x;
	else return F[x]=find(F[x]);
}
double dis(const node& a,const node& b){
	double t1=(double)(a.u-b.u)*(double)(a.u-b.u);
	double t2=(double)(a.v-b.v)*(double)(a.v-b.v);
	return sqrt(t1+t2);
}
void merge(int x,int y){
	int fa=find(x),fb=find(y);
	if(fa==fb) return;
	if(high[fa]>high[fb]) swap(fa,fb);
	F[fa]=fb;
	high[fb]=max(high[fb],high[fa]+1);
	return ;
}
int main(int argc, char const *argv[])
{
	scanf("%d %d",&n,&m);
	int tol=0,sum=0;
	int a,b;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&point[i].u,&point[i].v);
		F[i]=i;
		high[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			edge[tol].u=i;
			edge[tol].v=j;
			edge[tol++].w=dis(point[i],point[j]);
		}
	}
	priority_queue<node>que;
	for(int i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		int fa=find(a),fb=find(b);
		if(fa!=fb){
			merge(a,b);
			sum++;
		}
	}
	for(int i=0;i<tol;i++){
		que.push(edge[i]);
	}
	double ans=0;
	while(que.size()){
		node t=que.top();
		que.pop();
		int fa=find(t.u),fb=find(t.v);
		double w=t.w;
		if(fa!=fb){
			ans+=w;
			sum++;
			merge(fa,fb);
		}
		if(sum==n-1) break;
	}
	printf("%.2f\n",ans);
	return 0;
}