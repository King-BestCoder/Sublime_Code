#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int main(int argc, char const *argv[])
{
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		// printf("1234567890123456789012345\n");
		printf("%10d%10d    ",n,m);
		if(n<m) swap(n,m);
		if(gcd(n,m)==1) printf("Good Choice\n\n");
		else printf("Bad Choice\n\n");
	}
	return 0;
}