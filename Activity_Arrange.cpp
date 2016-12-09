#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
	int x,y;
}node;
const int maxn=10005;
node num[maxn];
int n;
bool cmp(node a,node b){
	if(a.x!=b.x)
		return a.x<b.x;
	else
		return a.y<b.y;
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&num[i].x,&num[i].y);
	}
	sort(num,num+n,cmp);
	// for(int i=0;i<n;i++)
	// 	printf("%d %d\n",num[i].x,num[i].y);
	int ans=1;
	priority_queue<int,vector<int>,greater<int> >que;
	que.push(num[0].y);
	for(int i=1;i<n;i++){
		if(num[i].x<que.top()){
			ans++;
			que.push(num[i].y);
		}
		else{
			que.pop();
			que.push(num[i].y);
		}
	}
	printf("%d\n",ans);
	return 0;
}
