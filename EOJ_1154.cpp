#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn=100005;
LL a,b;
LL num[maxn],temp[maxn];
int cnt=0,k;
void copy(){
    for(int i=1;i<=k;i++){
        num[i]=temp[i];
        // printf("%I64d\n",temp[i]);
    }
}
LL gcd(LL aa,LL bb){
    if(aa<bb) swap(aa,bb);
    LL t;
    while(bb){
        t=aa%bb;
        aa=bb;
        bb=t;
    } 
    return aa;
}
LL fac(LL aa,LL bb){
    LL t=bb/aa;
    if(bb%aa) t++;
    return t; 
}
bool good(int step){
    if(num[step]==-1||temp[step]<num[step]) return true;
    else return false;
}
bool dfs(int d, long long from, long long aa, long long bb, int limit)
{
    if (d == limit)
    {
        if (bb % aa)
            return false;
        temp[d] = bb / aa;
        if (good(d))
            copy();
        return true;
    }
    bool ok = false;
    from = max(from,fac(aa, bb));
    for (int i = from; ; ++i)
    {
        if (bb * (limit + 1 - d) <= i * aa)
            break;
        temp[d] = i;
        long long b2 = bb * i;
        long long a2 = aa * i - bb;
        long long g = gcd(a2, b2);
        if (dfs(d + 1, i + 1, a2 / g, b2 / g, limit))
            ok = true;
    }
    return ok;
}
int main()
{
    while(~scanf("%I64d %I64d",&a,&b)){
        for(k=1;;k++){
            memset(num,-1,sizeof(num));
            if(dfs(1,fac(a,b),a,b,k)){
                break;
            }
        }
        for(int i=1;i<=k;i++)
            printf("%I64d%c",num[i],i==k?'\n':' ');
    }
    return 0;
}