#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
const int maxn=50005;
typedef long long LL;
using namespace std;
int n;
int l[maxn],h[maxn],Left[maxn],Right[maxn];
LL sum=0;

int main(int argc, char const *argv[])
{
	while(scanf("%d",&n)!=EOF){
		if(n==-1) break;
		for(int i=1;i<=n;i++)
			scanf("%d%d",&l[i],&h[i]);
		Left[1]=1;
		for(int i=2;i<=n;i++){
			int j=i;
			while(j>1&&h[j-1]>=h[i])
				j=Left[j-1];
			Left[i]=j;
		}
		Right[n]=n;
		for(int i=n-1;i>=1;i--){
			int j=i;
			while(j<n&&h[j+1]>=h[i])
				j=Right[j+1];
			Right[i]=j;
		}
		sum=0;
		for(int i=1;i<=n;i++){
			LL t=0;
			for(int j=Left[i];j<=Right[i];j++)
				t+=l[j];
			sum=max(sum,t*h[i]);
		}
		printf("%I64d\n",sum);
	}
	return 0;
}