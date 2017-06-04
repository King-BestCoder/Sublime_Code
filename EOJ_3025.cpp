#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int n;
		scanf("%d",&n);
		ll ans=0;
		n<<=1;
		for(int i=2;i*(i-1)<n;i++){
			if(n%i==0&&(n/i-i+1)%2==0){
				ans++;
			}
		}
		printf("Case %d: %lld\n",t,ans);
	}
	return 0;
}