#include <bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=111111;
int num[maxn<<2];
int col[maxn<<2];
int n,m,a,b,c;
void pushup(int rt){
	num[rt]=num[rt<<1]+num[rt<<1|1];
}
void pushdown(int rt,int m){
	if(col[rt]){
		col[rt<<1]=col[rt<<1|1]=col[rt];//根节点向子节点的颜色传递
		//子节点的数值更新
		num[rt<<1]=(m-(m>>1))*col[rt];
		num[rt<<1|1]=(m>>1)*col[rt];
		col[rt]=0;
	}
}
void build(int l,int r,int rt){
	col[rt]=0;
	num[rt]=1;
	if(l==r) return ;
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}
void update(int left,int right,int c,int l,int r,int rt){
	if(left<=l&&right>=r){
		col[rt]=c;
		num[rt]=c*(r-l+1);
		return ;
	}
	pushdown(rt,r-l+1);
	int m=(l+r)>>1;
	if(left<=m) update(left,right,c,lson);
	if(right>m) update(left,right,c,rson);
	pushup(rt);
}
int main(int argc, char const *argv[])
{
	int T,t;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d %d",&n,&m);
		build(1,n,1);
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&c);
			update(a,b,c,1,n,1);
		}
		printf("Case %d: The total value of the hook is %d.\n",t,num[1]); 
	}
	return 0;
}