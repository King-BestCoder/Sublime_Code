#include <bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int maxn=205005;
int num[maxn<<2];
int n,m;
char s[10];
int a,b;
void pushup(int rt){
	num[rt]=max(num[rt<<1],num[rt<<1|1]);
}
void build(int l,int r,int rt){
	if(l==r){
		scanf("%d",&num[rt]);
		return ;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}
void update(int pos,int value,int l,int r,int rt){
	if(l==r){
		num[rt]=value;
		return ;
	}
	int m=(l+r)>>1;
	if(pos<=m) update(pos,value,lson);
	else update(pos,value,rson);
	pushup(rt);
}
int query(int left,int right,int l,int r,int rt){
	if(left<=l&&right>=r){
		return num[rt];
	}
	int m=(l+r)>>1;
	int tmp=0;
	if(left<=m) tmp=max(tmp,query(left,right,lson));
	if(right>m) tmp=max(tmp,query(left,right,rson));
	return tmp;
}
int main(int argc, char const *argv[])
{
	while(~scanf("%d %d",&n,&m)){
		build(1,n,1);
		for(int i=0;i<m;i++){
			scanf("%s%d%d",s,&a,&b);
			if(s[0]=='Q'){
				// printf("%s %d %d\n",s,a,b);
				printf("%d\n",query(a,b,1,n,1));
			}
			else if(s[0]=='U'){
				// printf("%s %d %d\n",s,a,b);
				update(a,b,1,n,1);
			}
		}
	}
	return 0;
}