#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
const int maxn=500005;
int c[maxn],u[maxn];

int main(int argc, char const *argv[])
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d %d",&c[i],&u[i]);
	int cnt=0,ans=0;
	c[n]=k;
	for(int i=0;i<n;i++){
		if(u[i]==1) continue;
		if(ans+c[i]>=c[i+1])
			continue;
		else{
			ans+=c[i];
			cnt++;
			// printf("%d\n",c[i]);
		}
	}
	if(cnt==0)
		printf("0\n%d\n",k-1);
	else
		printf("%d\n%d\n",cnt,k-ans);
	return 0;
}
