#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int maxn=10005;
typedef struct Node{
	int x,y;
}node;
node num[maxn];
bool cmp(node a,node b){
	if(a.y!=b.y)
		return a.y<b.y;
	else 
		return a.x>b.x;
}
typedef long long LL;
LL ans=0;
int n;
template <class T>
inline bool scan_d(T &ret) {
	char c; int sgn;
	if(c=getchar(),c==EOF) return 0;
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	 	sgn=(c=='-')?-1:1;
	 	ret=(c=='-')?0:(c-'0');
		while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
	 	ret*=sgn;
	return 1;
}
int main(int argc, char const *argv[])
{
	while(~scanf("%d",&n)){
		priority_queue<int,vector<int>,greater<int> >que;
		for(int i=0;i<n;i++){
			scan_d(num[i].x);
			scan_d(num[i].y);
		}
		sort(num,num+n,cmp);
		ans=0;
		for(int i=0;i<n;i++){
			if(num[i].y>que.size()){
				que.push(num[i].x);
				ans+=num[i].x;
			}
			else{
				if(num[i].x>que.top()){
					ans=ans+num[i].x-que.top();
					que.pop();
					que.push(num[i].x);
				}
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}