#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn=111115;
int ans[maxn][2];
bool su[20000005];
int num[maxn];
int cnt;
int main(int argc, char const *argv[])
{
	for(int i=1;i<20000005;i++)
		su[i]=1;
	for(int i=2;i<20000005;i++){
		if(su[i]){
			// num[++cnt]=i;
			for(int j=2*i;j<20000005;j+=i){
				su[j]=0;
			}
		}
	}
	int p=0;
	for(int i=2;i<20000005;i++){
		if(su[i]&&su[i+2]){
			++p;
			ans[p][0]=i,ans[p][1]=i+2;
		}
	}
	// printf("%d\n",p);
	int s;
	while(~scanf("%d",&s)){
		printf("(%d, %d)\n",ans[s][0],ans[s][1]);
	}	
	return 0;
}