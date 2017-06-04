#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;

int main(int argc, char const *argv[])
{
	int n,a,b,c,d;
	while(~scanf("%d ",&n)){
		printf("YES\n");
		for(int i=0;i<n;i++){
			scanf("%d %d %d %d",&a,&b,&c,&d);
			printf("%d\n",1+2*(a&1)+(b&1));
		}
	}
	return 0;
}