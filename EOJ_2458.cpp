#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=100005;
int num[maxn<<2],ln[maxn<<2],rn[maxn<<2],sum[maxn<<2];
int col[maxn<<2];
int n,m;
void pushup(int rt,int l,int r){
	int m=(l+r)>>1;
	if(num[m]==num[m+1]){
		sum[rt]=max(ln[rt<<1|1]+rn[rt<<1],max(sum[rt<<1],sum[rt<<1|1]));
	}
	else{
		sum[rt]=max(sum[rt<<1],sum[rt<<1|1]);
	}
	if(ln[rt<<1]==m-l+1&&num[m]==num[m+1]){
		ln[rt]=rn[rt<<1]+ln[rt<<1|1];
	}
	else{
		ln[rt]=ln[rt<<1];
	}
	if(rn[rt<<1|1]==r-m&&num[m]==num[m+1]){
		rn[rt]=ln[rt<<1|1]+rn[rt<<1];
	}
	else{
		rn[rt]=rn[rt<<1|1];
	}
}
void build(int l,int r,int rt){
	if(l==r){
		sum[rt]=ln[rt]=rn[rt]=1;
		return ;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt,l,r);
}

int query(int id,int L,int R,int l,int r)
{
    if(L>r||R<l||R<L) return 0;
    if(L>=l&&R<=r) return sum[id];
    int mid=(L+R)>>1;
    int m=1,m1=1,m2=1;
    if(num[mid+1]==num[mid]) m=min(mid-l+1,rn[id<<1])+min(r-mid,ln[id<<1|1]);
    if(l<=mid)
    m1=query(id<<1,L,mid,l,r);
    if(r>mid)
    m2=query(id<<1|1,mid+1,R,l,r);
    m=max(max(m1,m2),m);
    return m;
}

int main(int argc, char const *argv[])
{
	while(~scanf("%d",&n)&&n){
		memset(ln,0,sizeof(ln));
		memset(rn,0,sizeof(rn));
		memset(num,0,sizeof(num));
		memset(sum,0,sizeof(sum));
		scanf("%d",&m);
		for(int i=1;i<=n;i++) 
			scanf("%d",&num[i]);
		build(1,n,1);
		int a,b;
		for(int i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			printf("%d\n",query(1,1,n,a,b));
		}
	}
	return 0;
}