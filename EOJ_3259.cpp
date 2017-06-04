#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct Node{
	int l,r;
	ll v;
	friend bool operator < (Node a,Node b){
		if(a.l!=b.l)
			return a.l>b.l;
		else 
			return a.r>b.r;
	}
}node;

int main(int argc, char const *argv[])
{
	int n;
	node tmp,tmp2;
	int a,b;
	ll c;
	while(~scanf("%d",&n)){
		priority_queue<node>que;
		for(int i=0;i<n;i++){
			scanf("%d %d %lld",&a,&b,&c);
			tmp.l=a,tmp.r=b,tmp.v=c;
			que.push(tmp);
		}
		tmp=que.top();
		que.pop();
		bool flag=1;
		while(que.size()){
			tmp2=que.top();
			if(tmp.l==tmp2.l){
				if(tmp.r==tmp2.r){
					if(tmp.v!=tmp2.v){
						flag=0;
						break;
					}
				}
				else{
					int temp=tmp.r+1;
					ll tempvalue=tmp2.v-tmp.v;
					tmp.l=temp,tmp.r=tmp2.r,tmp.v=tempvalue;
					que.push(tmp);
				}
			}
			if(!flag) break;
			tmp=que.top();
			que.pop();
		}
		if(flag){
			printf("2333!(=v=)\n");
		}
		else{
			printf("666~~~(=_=)\n");
		}
	}
	return 0;
}