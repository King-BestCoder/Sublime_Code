#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long LL;

const int maxn=11111;
bool Hash[maxn];
using namespace std;

int li[maxn],ri[maxn];
int X[maxn*3];
int col[maxn<<4];
int cnt;
void pushup(int rt){
	X[rt]=X[rt<<1]+X[rt<<1|1];
}
void pushdown(int rt){
	if(col[rt]!=-1){
		col[rt<<1]=col[rt<<1|1]=col[rt];
		col[rt]=-1;
	}
}
void update(int left,int right,int c,int l,int r,int rt){
	if(left<=l&&right>=r){
		col[rt]=c;
		return ;
	}
	pushdown(rt);
	int m=(l+r)>>1;
	if(left<=m)	update(left,right,c,lson);
	if(right>m)	update(left,right,c,rson);
}
void query(int l,int r,int rt){
	if(col[rt]!=-1){
		int t=col[rt];
		if(!Hash[t]) cnt++;
		Hash[t]=true;
		return ;
	}
	if(l==r) return ;
	int m=(l+r)>>1;
	query(lson);
	query(rson);
}
int Bin(int key,int n,int x[]){
	int l=0,r=n-1;
	while(l<=r){
		int m=(l+r)>>1;
		if(X[m]==key) return m;
		if(X[m]<key) l=m+1;
		else r=m-1;
	}
	return -1;
}
int main(int argc, char const *argv[])
{
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int nn=0;
		for(int i=0;i<n;i++){
			scanf("%d %d",&li[i],&ri[i]);
			X[nn++]=li[i];
			X[nn++]=ri[i];
		}
		sort(X,X+nn);
		int m=1;
		for(int i=1;i<nn;i++){
			if(X[i]!=X[i-1]) X[m++]=X[i];
		}
		for(int i=m-1;i>0;i--){
			if(X[i]!=X[i-1]+1) X[m++]=X[i-1]+1;
		}
		sort(X,X+m);
		memset(col,-1,sizeof(col));
		for(int i=0;i<n;i++){
			int l=Bin(li[i],m,X);
			int r=Bin(ri[i],m,X);
			update(l,r,i,0,m,1);
		}
		cnt=0;
		memset(Hash,false,sizeof(Hash));
		query(0,m,1);
		printf("%d\n",cnt);
	}
	return 0;
}