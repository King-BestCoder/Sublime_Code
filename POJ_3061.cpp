#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
const int maxn=100005;
int num[maxn];
int sum[maxn];
int s,n;

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&s);
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
			if(i==0) sum[i]=num[i];
			else sum[i]=sum[i-1]+num[i];
		}
		int i,t,ans=n;
		if(sum[n-1]<s){
			ans=0;
		}
		else{
			for(i=0;sum[i]+s<=sum[n-1];i++){
				t=lower_bound(sum+i,sum+n-1,sum[i]+s)-sum;
				ans=min(ans,t-i);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
