#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
const int maxn=1005;
int num[maxn];
int find(int a){
	if(a==num[a]) return a;
	else return num[a]=find(num[a]);
}
void merge(int a,int b){
	int fa=find(a),fb=find(b);
	num[fa]=fb;
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int n,m;
		memset(num,0,sizeof(num));
		scanf("%d %d",&n,&m);
		int a,b;
		for(int i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			merge(a,b);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(num[i]==i) ans++;
		}
		printf("Case %d: ",t);
		if(ans&1) printf("NO\n");
		else printf("YES\n")；
	}
	return 0;
}