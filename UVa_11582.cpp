#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;
llu a,b,n;
llu fib[1000005];

llu pow_m(llu x,llu y,llu p){
	llu ans=1;
	while(y){
		if(y&1) ans=((ans%p)*(x%p))%p;
		x=(x*x)%p;
		y>>=1;
		// printf("%I64d\n",y);
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	// fib[0]=0,fib[1]=1;
	// for(int i=2;i<=1000;i++){
	// 	fib[i]=fib[i-1]+fib[i-2];
	// }
	// for(int i=0;i<=1000;i++)
	// 	printf("%I64d\n",fib[i]);
	int T;
	scanf("%d",&T);
	while(T--){
		cin>>a>>b>>n;
		if(a==0||n==1) printf("0\n");
		else{
			llu time=0;
			fib[0]=0,fib[1]=1;
			for(llu i=2;i<=n*n;i++){
				fib[i]=(fib[i-1]+fib[i-2])%n;
				if(fib[i-1]==0&&fib[i]==1){
					time=i-1;
					break;
				}
			}
			llu ans=pow_m(a%time,b,time);
			cout<<fib[ans]<<endl;
		}
	}
	return 0;
}