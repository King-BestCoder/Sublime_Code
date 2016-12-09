#include <stdio.h>
#include <algorithm>
#include <string.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
typedef long long LL;
const int maxn=111111;
LL sum[maxn<<2];
LL add[maxn<<2];
LL c;
char s[5];
int n,q,a,b;
void pushup(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void pushdown(int rt,int m){
	if(add[rt]){
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		sum[rt<<1]+=add[rt]*(m-(m>>1));
		sum[rt<<1|1]+=add[rt]*(m>>1);
		add[rt]=0;
	}
}
void build(int l,int r,int rt){
	add[rt]=0;
	if(l==r){
		scanf("%I64d",&sum[rt]);
		return ;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}
void update(int left,int right,int c,int l,int r,int rt){
	if(left<=l&&right>=r){
		add[rt]+=c;
		sum[rt]+=(LL)c*(r-l+1);
		// printf("sdfs%d %d %d\n",r,l,r-l+1);
		return ;
	}
	pushdown(rt,r-l+1);
	int m=(l+r)>>1;
	if(left<=m) update(left,right,c,lson);
	if(right>m) update(left,right,c,rson);
	pushup(rt);
}
LL query(int left,int right,int l,int r,int rt){
	if(left<=l&&right>=r){
		return sum[rt];
	}
	pushdown(rt,r-l+1);
	int m=(l+r)>>1;
	LL tmp=0;
	if(left<=m) tmp+=query(left,right,lson);
	if(right>m) tmp+=query(left,right,rson);
	return tmp;
}
int main(int argc, char const *argv[])
{
	scanf("%d %d",&n,&q);
	build(1,n,1);
	for(LL i=0;i<q;i++){
		scanf("%s",s);
		// printf("%s\n",s);
		if(s[0]=='Q'){
			scanf("%d %d",&a,&b);
			printf("%I64d\n",query(a,b,1,n,1));
		}
		else if(s[0]=='C'){
			scanf("%d %d %I64d",&a,&b,&c);
			update(a,b,c,1,n,1);
		}
	}
	return 0;
}