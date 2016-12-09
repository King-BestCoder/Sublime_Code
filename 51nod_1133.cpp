#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn=50005;
typedef struct Node{
	int x,y;
}node;
node num[maxn];
int n;
bool cmp(node a,node b){
	if(a.y!=b.y)
		return a.y<b.y;
	else
		return a.x<b.x;
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&num[i].x,&num[i].y);
	sort(num,num+n,cmp);
	int ans=-0x3f3f3f3f;
	int sum=0;
	for(int i=0;i<n;i++){
		if(ans<=num[i].x){
			sum++;
			ans=num[i].y;
		}
	}
	printf("%d\n",sum);
	return 0;
}