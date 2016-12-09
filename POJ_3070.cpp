#include <cstdio>
#include <iostream>

using namespace std;

const int mod = 1e9+7;
typedef long long LL;
struct matrix
{
    LL m[2][2];
}ans, base;

matrix multi(matrix a, matrix b)
{
    matrix tmp;
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            tmp.m[i][j] = 0;
            for(int k = 0; k < 2; ++k)
                tmp.m[i][j] = (tmp.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;
        }
    }
    return tmp;
}
LL fast_mod(LL n)  
{
    base.m[0][0] = base.m[0][1] = base.m[1][0] = 1;
    base.m[1][1] = 0;
    ans.m[0][0] = 3;
    ans.m[1][1] = 1;  
    ans.m[0][1] = ans.m[1][0] = 2;
    while(n)
    {
        if(n & 1)  
        {
            ans = multi(ans, base);
        }
        base = multi(base, base);
        n >>= 1;
    }
    return ans.m[0][1]%mod;
}

int main()
{
    LL n;
    while(scanf("%lld", &n) && n != 0)
    {   if(n==1)cout<<1<<endl;
        else if(n==2) cout<<2<<endl;
        else
            printf("%lld\n", fast_mod(n-2));
    }
    return 0;
}