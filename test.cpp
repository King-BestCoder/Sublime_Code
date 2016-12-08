#include <bits/stdc++.h>
using namespace std;
const int maxn=10005;
typedef long long LL;
char s[maxn];
int n=492859377;
bool isprime(int a){
    if(a==1) return false;
    if(a==2) return true;
    if(a%2==0) return false;
    for(int i=3;i*i<=a;i++){
        if(a%i==0) return false;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    // while(~scanf("%d",&n)){
        int ans=0;
        for(int i=2;i<=n;i++){
            // cout<<i<<endl;
            if(isprime(i)) ans++;
        }
        cout<<ans<<endl;
    // }
    return 0;
}