#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

struct Node{
	int value,end;
	friend bool operator<(const Node &x,const Node &y){
		if(x.end!=y.end)
			return x.end>y.end;
		else
			return x.value>y.value;
	}
	friend bool operator>(const Node &x,const Node &y){
		if(x.value!=y.value)
			return x.value<y.value;
		else 
			return x.end<y.end;
	}
};

const int maxn=10005;
typedef struct Node node;
int n,a,b;

bool cmp(node a,node b){
	if(a.end!=b.end)
		return a.end>b.end;
	else 
		return a.value>b.value;
}

int main(int argc, char const *argv[])
 {
 	while(~scanf("%d",&n)){
 		priority_queue<int>que;
 		vector<int>date[maxn];
 		int enday=0;
 		for(int i=0;i<n;i++){
 			scanf("%d %d",&a,&b);
 			enday=max(enday,b);
 			date[b].push_back(a);
 		}
 		int ans=0;
 		if(n>0){
 			for(int i=enday;i>=1;i--){
 				if(date[i].size()){
 					for(int j=0;j<date[i].size();j++){
 						que.push(date[i][j]);
 					}
 					ans+=que.top();
 					que.pop();
 				}
 				else{
 					if(!que.empty()){
 						ans+=que.top();
 						// printf("%d\n",que.top());
 						que.pop();
 					}
 				}
 			}
	 	}
 		printf("%d\n",ans);
 	}
 	return 0;
 } 