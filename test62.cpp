#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(int argc, char const *argv[])
{
	LL n,m;
	while(~scanf("%lld %lld",&n,&m)){
		if(n==2||m==2){
			if(n%2==1||m%2==1){
				printf("NO\n");
			}
			else{
				printf("YES\n");
			}
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}