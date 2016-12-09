#include <bits/stdc++.h>
#define rson m+1,r,rt<<1|1
#define lson l,m,rt<<1
//2528  3277
using namespace std;

const int maxn=50010;
int num[maxn<<2];
int n,a,b;
char s[15];
void pushup(int rt){
	num[rt]=num[rt<<1]+num[rt<<1|1];
}
void construct(int l,int r,int rt){
	if(l==r){
		scanf("%d",&num[rt]);
		return ;
	}
	int m=(l+r)>>1;
	construct(lson);
	construct(rson);
	pushup(rt);
}
void update(int pos,int add,int l,int r,int rt){
	//单点更新
	if(l==r){
		num[rt]+=add;
		return ;
	}
	int m=(l+r)>>1;
	if(pos<=m) update(pos,add,lson);
	else update(pos,add,rson);
	pushup(rt);
}

int query(int left,int right,int l,int r,int rt){
	//区间操作
	int tmp=0;
	if(left<=l&&right>=r){
		return num[rt];
	}
	int m=(l+r)>>1;
	if(left<=m) tmp+=query(left,right,lson);
	if(right>m) tmp+=query(left,right,rson);
	return tmp;
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d",&n);
		construct(1,n,1);
		printf("Case %d:\n",t);
		while(scanf("%s",s)){
			if(s[0]=='E') break;
			scanf("%d %d",&a,&b);
			if(s[0]=='A'){
				update(a,b,1,n,1);
			}
			else if(s[0]=='S'){
				update(a,-b,1,n,1);
			}
			else if(s[0]=='Q'){
				printf("%d\n",query(a,b,1,n,1));
			}
		}
	}
	return 0;
}