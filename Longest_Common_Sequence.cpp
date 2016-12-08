#include <bits/stdc++.h>
using namespace std;
const int maxn=50005;
typedef struct Node{
	int x,y;
}node;
node num[maxn];
int n;
bool cmp(node a,node b){
	if(a.x!=b.x)
		return a.x<b.x;
	else 
		return a.y>b.y;
}

int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&num[i].x,&num[i].y);
	}
	sort(num+1,num+n+1,cmp);
	node p=num[1];
	int ans=-1;
	for(int i=2;i<=n;i++){
		if(num[i].y<p.y){
			ans=max(ans,num[i].y-num[i].x);
		}
		else if(num[i].x<p.y&&num[i].y>=p.y){
			ans=max(ans,p.y-num[i].x);
			p=num[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}
