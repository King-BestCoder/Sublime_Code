#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <vector>
typedef long long LL;
using namespace std;
const int maxn=100005;
LL n;
LL lef[maxn], righ[maxn], num[maxn];
LL sum=0;

int main(int argc, char const *argv[])
{
    while(~scanf("%I64d",&n)&&n){
        memset(lef,0,sizeof(lef));
        memset(righ,0,sizeof(righ));
        memset(num,0,sizeof(num));
        sum=0;
        for(LL i=1;i<=n;i++)
            scanf("%I64d",&num[i]);
        lef[1]=1;
        for(LL i=2;i<=n;i++){
            LL j=i;
            while(j>1&&num[j-1]>=num[i]){
                j=lef[j-1];
            }
            lef[i]=j;
        }
        righ[n]=n;
        for(LL i=n-1;i>=1;i--){
            LL j=i;
            while(j<n&&num[j+1]>=num[i])
                j=righ[j+1];
            righ[i]=j;
        }

        for(LL i=1;i<=n;i++){
            sum=max(sum,(righ[i]-lef[i]+1)*num[i]);
        }
        printf("%I64d\n",sum);
    }    
    return 0;
}