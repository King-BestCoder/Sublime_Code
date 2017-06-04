#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <set>
#include <vector>
 
using namespace std;
const int maxn=105;
typedef long long LL;
LL fib[maxn];
int n;
int main(int argc, char const *argv[])
{
    fib[0]=0,fib[1]=1;
    for(int i=2;i<=64;i++)
        fib[i]=fib[i-1]+fib[i-2];
    while(~scanf("%d",&n)){
        printf("%lld\n",fib[n]);
    }
    return 0;
}