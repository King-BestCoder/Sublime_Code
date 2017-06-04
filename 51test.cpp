#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+6;

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int x;
		scanf("%d",&x);
		int temp=6;
		int ans=1;
		while(ans<maxn){
			if(temp%x==0){
				break;
			}
			temp=(temp%x)*10+6;
			ans++;
		}
		if(ans>=maxn)
			ans=-1;
		printf("Case %d: %d\n",t,ans);
	}
	return 0;
}