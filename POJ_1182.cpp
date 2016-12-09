#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;
typedef long long LL;
LL ans=0;
const int maxn=50000;
int n,m;
int rela[3*maxn+5];
int find(int a){
	if(a!=rela[a])
		rela[a]=find(rela[a]);
	return rela[a];
}
bool merge(int a,int b){
	int fa=find(a);
	int fb=find(b);
	if(fa!=fb){
		rela[fa]=fb;
		return true;
	}
	else 
		return false;
}
bool same(int a,int b){
	int fa=find(a),fb=find(b);
	if(fa==fb) return true;
	else return false;
}
int main(int argc, char const *argv[])
{
	int t,a,b;
	scanf("%d %d",&n,&m);
	ans=0;
	for(int i=0;i<150005;i++)
		rela[i]=i;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&t,&a,&b);
		if(a>n||b>n){
			ans++;
			// cout<<a<<"  "<<b<<endl;
			continue;
		}
		if(t==1){
			//表示要以同类相处理
			if(same(a,b+n)||same(a,b+2*n)){
				ans++;
				// cout<<a<<"  "<<b<<endl;
			}
			else{
				merge(a,b),merge(a+n,b+n),merge(a+n+n,b+n+n);
			}
		}
		else{
			//表示二者要以捕食关系处理
			if(same(a,b)||same(a,b+2*n)){
				ans++;
				// cout<<a<<"  "<<b<<endl;
			}
			else{
				merge(a,b+n),merge(a+n,b+n+n),merge(a+n+n,b);
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
