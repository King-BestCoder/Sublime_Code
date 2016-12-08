#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
typedef long long LL;
LL num[maxn];
LL m,n;
LL a,b,tmp;
int main(LL argc, char const *argv[])
{
	while(~scanf("%I64d %I64d",&n,&m)){
		for(LL i=1;i<=n;i++){
			scanf("%I64d",&tmp);
			num[i]=tmp*2;
		}
		for(LL i=0;i<m;i++){
			scanf("%I64d %I64d %I64d",&a,&b,&tmp);
			num[a]+=tmp;
			num[b]+=tmp;
		}
		sort(num+1,num+n+1);
		LL ans=0;
		if(n%2==0){
			for(LL i=n;i>=2;i-=2){
				ans+=num[i]-num[i-1];
			}
		}
		else {
			ans+=num[1];
			for(LL i=n;i>=3;i-=2)
				ans+=num[i]-num[i-1];
		}
		printf("%I64d\n",ans/2);
	}
	return 0;
}