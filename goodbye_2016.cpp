#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int d[maxn],c[maxn];
typedef long long LL;
char dir[10];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	long long sum=1901;
	int t,di,flag=0;
	for(int i=0;i<n;i++){
		scanf("%d %d",&t,&di);
		if(i==0&&di==2) sum=1899; 
		if((di==1&&sum<1900)||(di==2&&sum>=1900)){
			flag=1;
		}
		sum+=t;
	}
	if(flag) printf("Impossible\n");
	else{
		if(sum%2==0) printf("Infinity\n");
		else printf("%I64d\n",sum);
	}
	return 0;
}