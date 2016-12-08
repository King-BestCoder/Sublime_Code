#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
#include<set>
#define ll long long
#define db double
#define lson k<<1
#define rson k<<1|1
using namespace std;

const int N = 10005;
const ll MOD = 1000000007;

ll quick_pow(ll x,ll k)
{
    ll res=1LL;
    while(k)
    {
        if(k&1) res=res*x%MOD;
        x=x*x%MOD;
        k>>=1;
    }
    return res;
}

ll inv(ll t)
{
    return quick_pow(t,MOD-2);
}

ll C(ll n,ll m)
{
    ll res1=1LL,res2=1LL;
    m=min(m,n-m);
    for(ll i=1;i<=m;i++)
    {
        res1=res1*(n-i+1)%MOD;
        res2=res2*i%MOD;
    }
    return res1*inv(res2)%MOD;
}

int main()
{
    ll n,m;
//    while(scanf("%lld%lld",&n,&m)+1)
    int T;
    scanf("%d",&T);
    while(T--){
	    scanf("%lld%lld",&n,&m);
	    {
	        printf("%lld\n",C(n+m-1,n));
	    }
	}
    return 0;
}