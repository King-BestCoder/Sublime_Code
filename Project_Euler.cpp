#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100000;
LL num[maxn];
bool judge(LL  a){
	if(a==1) return false;
	if(a==2) return true;
	if(a%2==0) return false;
	for(LL i=3;i*i<=a;i+=2){
		if(a%i==0) return false;
	}
	return true;
}
int main(int argc, char const *argv[])
{
	LL n=600851475143;
	LL max=1;
	for(LL i=2;i<=n;i++){
		if(n%i==0&&judge(i)) {
			max=i;
			cout<<i<<endl;
		}
	}
	cout<<max<<endl;
	return 0;
}
