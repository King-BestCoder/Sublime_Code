#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
typedef long long LL;
const int maxn=100005;
LL a,b;

bool prime(LL t){
	if(t==2) return true;
	if(t%2==0) return false;
	LL tmp=(LL)sqrt(t);
	for(LL i=3;i<=tmp;i+=2){
		if(t%i==0) return false;
	}
	return true;
}

const int MAXN=1e6+5;
int prime[MAXN];
int cnt[MAXN];
void sieve(){
	memset(prime,1,sizeof(prime));
	prime[1]=prime[0]=0;
	prime[2]=1;
	int p=0;
	for(int i=2;i<MAXN;i++){
		if(prime[i]){
			cnt[i]=++p;
			for(int j=2*i;j<MAXN;j+=i)
				prime[j]=0;
		}
		else cnt[i]=p;
	}
}

LL sum;
int main(int argc, char const *argv[])
{
	int n;
	sieve();
	while(~scanf("%d",&n)){
		printf("%d\n",cnt[n]);
	}
	return 0;
}
