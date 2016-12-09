#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
const int maxn=100005;
int n;
struct node{
	double x,y;
}num[maxn];

bool cmp(struct node a,struct node b){
	return a.y<b.y;
}
double dis(struct node a,struct node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(int argc, char const *argv[])
{
	while(~scanf("%d",&n)!=EOF&&n){
		memset(num,0,sizeof(num));
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&num[i].x,&num[i].y);
		sort(num,num+n,cmp);
		double d=dis(num[0],num[1]);
		for(int i=0;i<n-1;i++){
			d=min(d,dis(num[i],num[i+1]));
		}
		printf("%.2f\n",d/2.0);
	}
	return 0;
}

