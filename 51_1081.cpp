#include <bits/stdc++.h>
using namespace std;
const int maxn=55555;
typedef long long LL;
LL sum[maxn<<2];
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
void pushup(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt){
	if(l==r){
		scanf("%I64d",&sum[rt]);
		return ;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}
LL query(int left,int right,int l,int r,int rt){
	if(left<=l&&right>=r){
		return sum[rt];
	}
	int m=(l+r)>>1;
	LL ans=0;
	if(left<=m) ans+=query(left,right,lson);
	if(right>m) ans+=query(left,right,rson);
	return ans;
}
int main(int argc, char const *argv[])
{
	int n,q,a,b;
	scanf("%d",&n);
	build(1,n,1);
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d %d",&a,&b);
		b=b+a-1;
		LL ans=query(a,b,1,n,1);
		printf("%I64d\n",ans);
	}
	return 0;
}