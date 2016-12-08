#include <stdio.h>
int num[55];
int main(int argc, char const *argv[])
{
	int i,n;
	num[1]=1;
	num[2]=2;
	num[3]=3;
	num[4]=4;
	for(i=5;i<=55;i++)
		num[i]=num[i-2]+num[i-3]+num[i-4];
	while(~scanf("%d",&n)&&n){
		printf("%d\n",num[n]);
	}
	return 0;
}