#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 1025
int num[maxn];
int n,m;
int main(int argc, char const *argv[])
{
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		scanf("%d",&m);
		if(m<1||m>n){
			printf("-1\n");
		}
		else{
			int flag=1;
			for(int i=1;i<=n;i++){
				if(i==m) continue;
				if(flag){
					printf("%d",num[i]);
					flag=0;
				}
				else printf(" %d",num[i]);
			}
			printf("\n");
		}
	}
	return 0;
}