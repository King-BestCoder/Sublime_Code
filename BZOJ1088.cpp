#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn=10005;
int num[maxn];
int temp[maxn];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&num[i]);
	int ans=0;
	for(int i=0;i<=num[0];i++){
		memset(temp,0,sizeof(temp));
		temp[0]=i;
		temp[1]=num[0]-i;
		for(int j=2;j<=n;j++){
			temp[j]=num[j-1]-temp[j-1]-temp[j-2];
		}
		if(temp[n]==0) ans++;
	}
	printf("%d\n",ans);
	return 0;
}