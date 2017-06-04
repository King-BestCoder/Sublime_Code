#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL gcd(LL a,LL b){
	if(a<b) swap(a,b);
	return b==0?a:gcd(b,a%b);
}
LL exgcd(LL a,LL b,LL &x,LL &y){
	if(b==0){
		x=1;y=0;return a;
	}
	LL t=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return t;
}

int main(int argc, char const *argv[])
{
	LL a,b,c,k;
	while(~scanf("%lld %lld %lld %lld",&a,&b,&c,&k)){
		if(!a&&!b&&!c&&!k) break;
		LL mod=(1LL)<<k;
		LL dis=b-a;
		dis%=mod;
		if(dis<0) dis+=mod;
		if(dis==0){
			printf("0\n");
		}
		else{
			LL temp=gcd(mod,c);
			if(dis%temp){
				printf("FOREVER\n");
			}
			else{
				c/=temp,mod/=temp,dis/=temp;
				LL ans,j;
				exgcd(c,mod,ans,j);
				ans*=dis;
				ans%=mod;
				if(ans<0) ans+=mod;
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}