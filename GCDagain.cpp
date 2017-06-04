#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
const int maxn=10010000;
bool vis[maxn];
int p[maxn/10];
LL cnt;

/*
SPOJ  Produce it again
考虑某一个质数p对答案的贡献ans。
ans = p^((n/p * m/p) + ((n/p^2 * m/p^2)) + ....)
原理类比n!的质因子分解后，对某个质因子p的指数大小的计数。
所以我们只需要一个线性筛即可，然后暴力计数。
复杂度约为O((n/logn)* logn * logn)。
*/
void Get_Prime(){//线性筛
	cnt=0;
	for(LL i=2;i<maxn;i++){
		if(!vis[i]){
			p[cnt++]=i;
		}
		for(LL j=0;j<cnt&&p[j]*i<maxn;j++){
			vis[p[j]*i]=1;
			if(i%p[j]==0){
				break;
			}
		}
	}
}

LL getcnt(LL pval,LL lim1,LL lim2){
	LL cnt=0;
	LL nval=pval;
	while(nval<=min(lim1,lim2)){
		cnt+=(lim1/nval)*(lim2/nval);
		nval*=pval;
	}
	return cnt;
}

LL Pow(LL a,LL b){
	LL ans=1;
	while(b){
		if(b&1){
			ans=ans*a;
			if(ans>mod) ans%=mod;
		}
		a*=a;
		b>>=1;
		if(a>mod) a%=mod;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	Get_Prime();
	LL n,m;
	LL T;
	scanf("%lld",&T);
	for(LL t=0;t<T;t++){
		scanf("%lld %lld",&n,&m);
		LL ans=1;

		for(LL i=0;i<cnt&&(p[i]<=min(n,m));i++){
			ans*=Pow(p[i],getcnt(p[i],n,m));
			if(ans>mod) ans%=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}