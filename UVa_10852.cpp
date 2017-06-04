#include <bits/stdc++.h>
using namespace std;
const int maxn=10005;
int num[maxn],su[maxn],cnt;

int main(int argc, char const *argv[])
{
	for(int i=1;i<maxn;i++)
		su[i]=1;
	cnt=0;
	for(int i=2;i<maxn;i++){
		if(su[i]){
			num[++cnt]=i;
			for(int j=i<<1;j<maxn;j+=i){
				su[j]=0;
			}
		}
	}
	int n;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int id=-1,value=-1;
		for(int i=1;i<=cnt;i++){
			if(num[i]>n) break;
			if(n%num[i]>value){
				id=i;
				value=num[i];
			}
		}
		printf("%d\n",num[id]);
	}
	return 0;
}