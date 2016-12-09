#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=200005;
LL n,k1,k2,k3,k4,m,k,x,s;
LL a[maxn],b[maxn],c[maxn],d[maxn];
int main(int argc, char const *argv[])
{
	while(cin>>n>>m>>k){
		scanf("%I64d %I64d",&x,&s);
		for(int i=0;i<m;i++) scanf("%I64d",&a[i]);
		for(int i=0;i<m;i++) scanf("%I64d",&b[i]);
		for(int i=0;i<k;i++) scanf("%I64d",&c[i]);
		for(int i=0;i<k;i++) scanf("%I64d",&d[i]);
		LL ans=(n-c[upper_bound(d,d+k,s)-d-1])*x;
		for(int i=0;i<m;i++){
			if(b[i]<=s){
				ans=min(ans,(LL)(n-c[upper_bound(d,d+k,s-b[i])-d-1])*a[i]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
