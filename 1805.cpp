#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
const int maxn=105000;
using namespace std;
int n,k;
int sa[maxn],h[maxn];
int rk[maxn],tmp[maxn];
string s,a;

bool cmp(int i, int j)
{
    if (rk[i] != rk[j]) return rk[i] < rk[j];
    else {
        int ii = i + k <= n ? rk[i + k] : -1;
        int jj = j + k <= n ? rk[j + k] : -1;
        return ii < jj;
    }
}

void Construct_sa()
{
    n = s.size();
    for (int i = 0; i <= n; i++){
        sa[i] = i;
        rk[i] = i < n ? s[i] : -1;
    }
    for (k = 1; k <= n; k <<= 1)
    {
        sort(sa, sa + n + 1, cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i <= n; i++)
        {
            tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]) ;
        }
        for (int i = 0; i <= n; i++){
            rk[i] = tmp[i];
        }
    }
}

void Construct_h()
{
    n = s.size();
    for (int i = 0; i <= n; i++) 
        rk[sa[i]] = i;
    int k = 0;
    for (int i = 0; i < n; i++){
        int j = sa[rk[i] - 1];
        if (k) k--;//下面证明
        for ( ; j + k < n&&i + k < n&&s[j + k] == s[i + k]; k++);
        h[rk[i] - 1] = k;
    }
}

int main(int argc, char const *argv[])
{
    getline(cin,s);
    getline(cin,a);
    memset(rk,0,sizeof(rk));
    memset(sa,0,sizeof(sa));
    memset(h,0,sizeof(h));
    memset(tmp,0,sizeof(tmp));
    int len1=s.size();
    s+='\n'+a;
    Construct_sa();
    Construct_h();
    int len = s.size();
    int ans = 0;
    for(int i=0; i<len; i++)
        if((sa[i] < len1) != (sa[i+1] < len1))
             ans=max(ans,h[i]);
    cout<<ans<<endl;
    return 0;
}