#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int main(int argc, char const *argv[])
{
	int a,b;
	while(~scanf("%d %d",&a,&b)){
		printf("%d/%d = %d.",a,b,a/b);
		int cnt=0;
		int num[3005],vis[3005];
		memset(num,0,sizeof(num));
		memset(vis,0,sizeof(vis));
		a=a%b;
		while(!vis[a]){
			num[++cnt]=a*10/b;
			vis[a]=cnt;
			a=a*10%b;
		}
		for(int i=1;i<=cnt&&i<51;i++){
			if(i==vis[a]){
				printf("(");
			}
			printf("%d",num[i]);
			if(i==50) printf("...");
		}
		printf(")\n");
		printf("   %d = number of digits in repeating cycle\n\n",cnt-vis[a]+1);
	}
	return 0;
}