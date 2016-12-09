#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;
#define lson l,m,rt>>1
#define rson m+1,r,rt>>1|1
typedef long long LL;
const int maxn=131072;;
bool used[maxn<<2];
int cover[maxn<<2];
int xxor[maxn<<2];
void fxor(int rt){
	if(cover[rt]!=-1)
		cover[rt]^=1;
	else
		xxor[rt]^=1;
}
void pushdown(int rt){
	if(cover[rt]!=-1){
		cover[rt<<1]=cover[rt<<1|1]=cover[rt];
		xxor[rt<<1]=xxor[rt<<1|1]=0;
		cover[rt]=-1;
	}
	if(xxor[rt]){
		fxor(rt<<1);
		fxor(rt<<1|1);
		xxor[rt]=0;
	}
}
void update(char op,int left,int right,int l,int r,int rt){
	if(left<=l&&right>=r){
		if(op=='U'){
			cover[rt]=1;
			xxor[rt]=0;
		}
		else if(op=='D'){
			cover[rt]=0;
			xxor[rt]=0;
		}
		else if(op=='C'||op=='S'){
			fxor(rt);
		}
		return ;
	}
	pushdown(rt);
	int m=(l+r)>>1;
	if(left<=m) update(op,left,right,lson);
	else if(op=='T'||op=='C'){
		xxor[rt<<1]=cover[rt<<1]=0;
	}
	if(right>m){
		update(op,left,right,rson);
	}
	else if(op=='T'||op=='C'){
		xxor[rt<<1|1]=cover[rt<<1|1]=0;
	}
}
void query(int l,int r,int rt){
	if(cover[rt]==1){
		for(int i=l;i<=r;i++){
			used[i]=true;
		}
		return ;
	}
	else if(cover[rt]==0) return ;
	if(l==r) return ;
	pushdown(rt);
	int m=(l+r)>>1;
	query(lson);
	query(rson);
}
int main(int argc, char const *argv[])
{
	cover[1]=xxor[1]=0;
	char op,l,r;
	int a,b;
	while(~scanf("%c %c%d,%d%c\n",&op,&l,&a,&b,&r)){
		// printf("yes\n");
		// printf("%c %c%d,%d%c\n",op,l,a,b,r);
		a<<=1,b<<=1;
		if(l=='(') a++;
		if(r==')') b--;
		if(a>b){
			if(op=='C'||op=='I'){
				cover[1]=xxor[1]=0;
			}
		}
		else update(op,a,b,0,maxn,1);
	}
	query(0,maxn,1);
	bool flag=false;
	int s=-1,e;
	for(int i=0;i<=maxn;i++){
		if(used[i]){
			if(s==-1) s=i;
			e=i;
		}
		else{
			if(s!=-1){
				if(flag) printf(" ");
				flag=true;
				// printf("%d %d\n",s,e);
				printf("%c%d,%d%c",s&1?'(':'[',s>>1,(e+1)>>1,e&1?')':']');
				s=-1;
			}
		}
	}
	// printf("bo\n");
	if(!flag) printf("empty set");
	printf("\n");
	return 0;
}