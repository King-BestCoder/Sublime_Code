#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
const int maxn=55;
int num[maxn];
queue<int>que;
int main(int argc, char const *argv[])
{
	while(~scanf("%d",&n)&&n){
		for(int i=1;i<=n;i++)
			que.push(i);
		int t;
		int cnt=0;
		while(que.size()!=1){
			t=que.front();
			num[cnt++]=t;
			que.pop();
			t=que.front();
			que.pop();
			que.push(t);
		}
		printf("Discarded cards:");
		for(int i=0;i<cnt;i++){
			if(i==0) printf(" %d",num[i]);
			else printf(", %d",num[i]);
		}
		printf("\nRemaining card: %d\n",que.front());
		que.pop();
	}
	return 0;
}