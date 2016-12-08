#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
typedef long long LL;
typedef struct Node{
	int x,y;
}node;

node machine[maxn],task[maxn];
int _count[maxn];
int n,m;

bool cmp(node a,node b){
	if(a.x!=b.x)
		return a.x>b.x;
	else 
		return a.y>b.y;
}
int bin(int l,int r,int tmp){
	while(l<=r){
		int mid=(l+r)/2;
		if(machine[mid].x>=tmp) l=mid+1;
		else r=mid-1; 
	}
	return r;
}

int main(int argc, char const *argv[])
{
	while(~scanf("%d %d",&n,&m)){
		for(int i=0;i<n;i++)
			scanf("%d %d",&machine[i].x,&machine[i].y);
		for(int i=0;i<m;i++){
			scanf("%d %d",&task[i].x,&task[i].y);
		}
		memset(_count,0,sizeof(_count));
		sort(machine,machine+n,cmp);
		sort(task,task+m,cmp);
		LL ans=0;
		int cnt=0;
		int j=0;
		for(int i=0;i<m;i++){
			while(j<n&&machine[j].x>=task[i].x){
				_count[machine[j].y]++;
				j++;
			}
			for(int k=task[i].y;k<=100;k++){
				if(_count[k]){
					ans+=task[i].x*500+task[i].y*2;
					_count[k]--;
					cnt++;
					break;
				}
			}
		}
		printf("%d %I64d\n",cnt,ans);
	}
	return 0;
}
