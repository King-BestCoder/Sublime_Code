#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;
int a,b;
const int maxn=105;
int used[maxn];
class dsu{
private:
	int father[maxn],son[maxn];
public:
	dsu(){
		for(int i=0;i<maxn;i++){
			father[i]=son[i]=i;
		}
	}
	int find(int a){
		if(a!=father[a])
			father[a]=find(father[a]);
		// printf("find    %d   %d\n",a,father[a]);
		return father[a];
	}
	void merge(int a,int b){
		int fa=find(a);
		int fb=find(b);
		if(fa!=fb){
			father[fb]=fa;
		}
	}
};
int main(int argc, char const *argv[])
{
	int cnt=1;
	while(~scanf("%d %d",&a,&b)){
		if(a==-1&&b==-1)
			break;
		else if(a==0&&b==0)
			printf("Case %d is a tree.\n",cnt++);
		else{
			memset(used,0,sizeof(used));
			dsu x;
			int root;
			int flag=1;
			if(a==b) flag=0;
			else{
				x.merge(a,b);
				used[a]=used[b]=1;
				root=a;
			}
			while(~scanf("%d %d",&a,&b)&&(a!=0&&b!=0)){
				int fa=x.find(a),fb=x.find(b);
				if(fa==fb){
					flag=0;
					// printf("yes\n");
				}
				used[a]=1,used[b]=1;
				x.merge(a,b);
			}
			for(int i=1;i<100;i++){
				if(used[i]&&x.find(i)!=x.find(root)){
					// printf("%d %d %d %d\n",i,root,x.find(i),x.find(root));
					flag=0;
				}
			}
			if(flag)
				printf("Case %d is a tree.\n",cnt++);
			else
				printf("Case %d is not a tree.\n",cnt++);
		}
	}
	return 0;
}