/*

hint 1: 考虑在每个盒子内拿出的花没有个数限制，有多少种组合

hint 2: 考虑集合S表示的集合，所对应的盒子内的花有个数限制
时，有多少组组合~ 然后就可以容斥了。

*/

#include <iostream>
using namespace std;
typedef long long LL;

const LL MOD = 1e9+7;
LL n, s, f[22], inv[22], c[22];
  
LL qpow(LL a, LL b){
    LL ans=1;
    while(b){
        if(b&1) ans=(ans*a)%MOD;
        a = (a*a)%MOD;
        b>>=1;
    }
    return ans;
}

LL getc(LL a,LL b){
    if(a<b)return 0;
    if(b>a-b)b=a-b;
    LL s1=1,s2=1;
    for(LL i=0;i<b;i++){
        s1=s1*(a-i)%MOD;
        s2=s2*(i+1)%MOD;
    }
    return s1*qpow(s2,MOD-2)%MOD;
}

LL C(LL n,LL k){
    if(n<0) return 0;
    if(k==0) return 1;
    return getc(n%MOD,k%MOD)*C(n/MOD,k/MOD)%MOD;
}

int main()
{
    cin >> n >> s;
    for(int i=1;i<=n;i++){
        cin >> f[i];
    }
    LL ans = C(s+n-1, n-1);
    for(int i=1;i<(1<<n);i++){
        int cnt = 0;
        LL sum = 0;
        for(int j=0;j<n;j++){
            if((1<<j)&i){
                cnt ++;
                sum += f[j+1]+1;
            }
        }
        LL tmp = C((s - sum) + (n-1), (n-1));
        if(cnt % 2 == 1){
            ans -= tmp;
        } 
        else {
            ans += tmp;
        }
        ans = (ans + MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}