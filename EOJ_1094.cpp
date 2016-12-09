#include <iostream>  
#include <cmath>  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>

using namespace std;  
typedef long long LL;
LL pow_mod(LL a,LL n,LL d){
	LL ans=1;
	while(n>0){
		if(n&1) ans=ans*a%d;
		a=a*a%d;
		n>>=1;
	}
	return ans;
}

bool test(LL n,LL a,LL d){
	if(n==2) return true;
	if(n==a) return true;
	if((n&1)==0) return false;
	while(!(d&1)) d=d>>1;//消除2的幂
	LL t=pow_mod(a,d,n);
	while((d!=n-1)&&(t!=1)&&(t!=n-1)){
		t=(LL)t*t%n;
		d=d<<1;
	}
	return (t==n-1||(d&1)==1);
}

bool isPrime(LL n){
	if(n<2) return false;
	int a[]={2,3,61};
	for(int i=0;i<3;i++)
		if(!test(n,a[i],n-1)) return false;
	return true;
}
int main()  
{  
    long long n;  
    while(scanf("%I64d",&n)!=EOF)  
    {  
       if(isPrime(n))
	       	printf("YES\n");
       else 
       		printf("NO\n");
    }  
  
    return 0;  
} 