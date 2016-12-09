#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1005;
typedef struct Node{
	double x,y;
}node;
node num[maxn];
bool vis[maxn];
double lowc[maxn];
double cost[maxn][maxn];
int n,m,t1,t2;
double dis(node a,node b){
	// printf("%.2f %.2f %.2f %.2f\n",a.x,b.x,a.y,b.y);
	double temp=(double)sqrt((double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y));
	// printf("%.2f\n",temp);
	return temp;
}
double prim(){
	double ans=0;
	memset(vis,false,sizeof(vis));
	vis[1]=true;lowc[1]=0;
	for(int i=2;i<=n;i++) lowc[i]=cost[1][i];
	for(int i=1;i<n;i++){
		int k=-1;
		double minc=inf;
		for(int j=1;j<=n;j++){
			if(vis[j]) continue;
			if(lowc[j]<minc){
				minc=lowc[j];
				k=j;
			}
		}
		// printf("%d %.2f\n",k,minc);
		if(k==-1) break;
		vis[k]=1;
		ans+=minc;
		for(int j=1;j<=n;j++){
			if(vis[j]) continue;
			if(lowc[j]>=cost[k][j])
				lowc[j]=cost[k][j];
		}
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	while(~scanf("%d %d",&n,&m)){
		for(int i=1;i<=n;i++){
			scanf("%lf %lf",&num[i].x,&num[i].y);
		}
		int a,b;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				cost[i][j]=cost[j][i]=dis(num[i],num[j]);
			}
		}
		for(int i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			cost[a][b]=cost[b][a]=0;
		}
		// for(int i=1;i<=n;i++){
		// 	for(int j=1;j<=n;j++)
		// 		printf("%.2f%c",cost[i][j],j==n?'\n':' ');
		// }
		double sum2=prim();
		printf("%.2f\n",sum2);
	}
	return 0;
}