#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=11111;
LL num[maxn<<2];
void pushup(int rt){
	num[rt]=max(num[rt<<1],num[rt<<1|1]);
}
void build(int l,int r,int rt){
	if(l==r){
		scanf("%I64d",&num[rt]);
		// cout<<num[rt]<<endl;
		return ;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}
LL query(int left,int right,int l,int r,int rt){
	if(left<=l&&right>=r){
		return num[rt];
	}
	int m=(l+r)>>1;
	LL ans=0;
	if(left<=m) ans=max(ans,query(left,right,lson));
	if(right>m) ans=max(ans,query(left,right,rson));
	return ans;
}
int main(int argc, char const *argv[])
{
	int n,q,a,b;
	scanf("%d",&n);
	build(1,n,1);
	scanf("%d",&q);
	// for(int i=1;i<=n;i++)
	// 	printf("%I64d%c",num[i],i==n?'\n':' ');
	while(q--){
		scanf("%d %d",&a,&b);
		a++,b++;
		printf("%I64d\n",query(a,b,1,n,1));
	}
	return 0;
}