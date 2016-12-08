#include <bits/stdc++.h>
using namespace std;
int n;
typedef long long LL;
const int maxn=1000005;
LL num[maxn];
int c[maxn];
int main(int argc, char const *argv[])
{
	while(~scanf("%d",&n)){
		LL sum=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&num[i]);
			sum+=num[i];
		}
		LL ave=sum/n;
		c[0]=0;
		for(int i=1;i<n;++i){
			c[i]=c[i-1]+num[i]-ave;
		}
		sort(c,c+n);
		// cout<<ave<<endl;
		LL mid=c[n/2];
		LL ans=0;
		for(int i=0;i<n;++i)
			ans+=abs(mid-c[i]);
		printf("%lld\n",ans);
	}
	return 0;
}
