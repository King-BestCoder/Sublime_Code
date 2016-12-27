#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
typedef struct Node{
	int x,y;
}node;
int n;
node num[maxn];
int main(int argc, char const *argv[])
{
	while(~scanf("%d",&n)&&n){
		memset(num,0,sizeof(num));
		for(int i=0;i<n;i++){
			scanf("%d %d",&num[i].x,&num[i].y);
		}	
		double ans=0;
		for(int i=0;i<n-1;i++){
			ans+=num[i].x*num[i+1].y-num[i].y*num[i+1].x;
		}
		ans+=num[n-1].x*num[0].y-num[n-1].y*num[0].x;
		ans/=2.0;
		printf("%.1f\n",ans);
	}
	return 0;
}