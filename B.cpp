#include <stdio.h>
typedef long long LL;
int main(int argc, char const *argv[])
{
	int T;
	LL a,b;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%lld %lld",&a,&b);
		printf("Case #%d:\n",t);
		if(a>b) printf("Win\n");
		else printf("Lose\n");
	}
	return 0;
}