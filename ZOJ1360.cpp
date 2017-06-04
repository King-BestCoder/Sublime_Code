#include <bits/stdc++.h>
using namespace std;

const int maxn=1005;
typedef struct Node{
	double x,y;
	double l,r;
}node;

bool cmp(const node &a,const node &b){
	if(a.r!=b.r)
		return a.r<b.r;
	else 
		return a.l<b.l;
}
node num[maxn];

double dis(const node &a,const node &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main(int argc, char const *argv[])
{
	int n,__=1;
	double m;
	while(~scanf("%d %lf",&n,&m)){
		if(n==0&&m==0) break;
		int flag=0;
		for(int i=0;i<n;i++){
			scanf("%lf %lf",&num[i].x,&num[i].y);
			if(num[i].y>m){
				flag=1;
				continue;
			}
			num[i].l=num[i].x-sqrt(m*m-num[i].y*num[i].y);
			num[i].r=num[i].x+sqrt(m*m-num[i].y*num[i].y);
		}
		printf("Case %d: ",__++);
		if(flag){
			printf("-1\n");
		}
		else{
			sort(num,num+n,cmp);
			int ans=0;
			double len=-10000000;
			for(int i=0;i<n;i++){
				if(num[i].l<=len)
					continue;
				len=num[i].r;
				ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}