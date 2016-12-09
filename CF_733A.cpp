#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string>

using namespace std;
int n;
const int maxn=1e5+5;
typedef struct Node{
	int a,b,c,id;
	double ar;
}node;
node num[maxn];
int a1[3],sum=0;
bool cmp(node x,node y){
	if(x.a!=y.a)
		return x.a<y.a;
	else if(x.b!=y.b)
		return x.b<y.b;
	else 
		return x.c<y.c;
}
bool check1(node x,node y){
	if(x.a==y.a&&x.b==y.b)
		return true;
	if(x.a==y.a&&x.c==y.c)
		return true;
	return false;
}
bool check2(node x,node y){
	if(x.b==y.b&&x.c==y.c)
		return true;
	return false;
}
double ans,tmp,tmp1;
int k,ansid,ansid1,ansid2;
int main(int argc, char const *argv[])
{
	while(~scanf("%d",&n)){
		ans=0;
		for(int i=1;i<=n;i++){
			sum=0;
			for(int j=0;j<3;j++){
				scanf("%d",&a1[j]);
				sum+=a1[j];
			}
			sort(a1,a1+3);
			num[i].a=a1[0],num[i].b=a1[1],num[i].c=a1[2];
			num[i].ar=(double)a1[0]/2.0;
			if(num[i].ar>ans){
				ans=num[i].ar,ansid=i;
			}
			num[i].id=i;
		}
		sort(num+1,num+n+1,cmp);
		// printf("\n\n");
		// for(int i=1;i<=n;i++)
		// 	printf("%d %d %d %d\n",num[i].a,num[i].b,num[i].c,num[i].id);
		k=1;
		for(int j,i=1;i<=n;i++){
			for(j=i;j<=n;j++){
				if(check1(num[i],num[j]))
					tmp=(double)num[i].a/2.0;
				if(check2(num[i],num[j])){
					tmp1=min((double)(num[i].a+num[j].a),min((double)num[i].b,(double)num[i].c));
					tmp1=tmp1/2.0;
				}
				tmp=max(tmp,tmp1);
				if(tmp>ans){
					k=2;
					ans=tmp;
					ansid1=num[i].id,ansid2=num[j].id;
				}
			}
		}
		printf("%d\n",k);
		if(k==1)
			printf("%d\n",ansid);
		else printf("%d %d\n",min(ansid1,ansid2),max(ansid1,ansid2));
	}
	return 0;	
}
