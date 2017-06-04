#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef struct Node{
	int x,y,z;
	double t;
	double temp;
}node;
int fa[maxn],n,m;
double h;
int find(int a){
	if(a==fa[a]) return a;
	else return fa[a]=find(fa[a]);
}
void merge(int a,int b){
	int aa=find(a),bb=find(b);
	if(aa==bb) return ;
	else fa[aa]=bb;
}
node num[maxn];
bool cmp(const node &a,const node &b){
	return a.temp<b.temp;
}
bool kruskal(double k){
	for(int i=1;i<=n;i++) 
		fa[i]=i;
	for(int i=0;i<m;i++){
		if(num[i].z==1)
			num[i].temp=num[i].t*k;
		else
			num[i].temp=num[i].t;
	}
	double ans=0;
	int cnt=0;
	sort(num,num+m,cmp);
	for(int i=0;i<m;i++){
		if(cnt==n-1) break;
		int a=find(num[i].x),b=find(num[i].y);
		if(a==b){
			continue;
		}
		else{
			fa[a]=b;
			ans+=num[i].temp;
			cnt++;
		}
		if(ans>h+10) return 0;
	}
	if(ans<=h) return 1;
	else return 0;
}
int main(int argc, char const *argv[])
{
	while(~scanf("%d %d %lf",&n,&m,&h)){
		for(int i=0;i<m;i++){
			scanf("%d %d %lf %d",&num[i].x,&num[i].y,&num[i].t,&num[i].z);
		}
		double mid,l=1,r=1e10;
		double ans;
		for(int i=0;i<55;i++){
			mid=(r+l)/2;
			if(kruskal(mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%.6f\n",ans);
	}
	return 0;
}