#include <bits/stdc++.h>
using namespace std;
const int maxn=50005;
int a[maxn];
int t;
int index[1000001];
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d %d",&m,&n);
	int low=0x3f3f3f3f,high=-1;
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
		low=min(low,a[i]);
		high=max(high,a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		int j;
		for(j=1;j<=m;j++){
			if(a[j]>=t) break;
		}
		if(j==1) continue;
		else if(j==m+1&&a[j-1]<t) continue;
		else{
			a[j-1]++;
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",a[i]);
	return 0;
}