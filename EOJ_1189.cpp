// #include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
const int maxn=100005;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
typedef struct Node{
	double x,y;
	Node(){
	}
	Node(double x1,double y1){
		x=x1,y=y1;
	}
}point;
double det(const Node &a,const Node &b){
	return a.x*b.y-a.y*b.x;
}
double dis(const Node &a,const Node &b){
    double c=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    return sqrt(c);
}
bool cmp(const Node &a,const Node &b){
	if(a.x!=b.x)
		return a.x<b.x;
	return a.y<b.y;
}
point num[maxn];
point vec[maxn];
int n,r;

int main(int argc, char const *argv[])
{
	while(~scanf("%d %d",&n,&r)){
		memset(num,0,sizeof(num));
		memset(vec,0,sizeof(vec));
		for(int i=0;i<n;i++){
			scanf("%lf %lf",&num[i].x,&num[i].y);
		}
		sort(num,num+n,cmp);
		int k=0,i,t;
		for(i=0;i<n;i++){//下链
			while(k>1&&det(point(vec[k-1].x-vec[k-2].x,vec[k-1].y-vec[k-2].y),
				point(num[i].x-vec[k-2].x,num[i].y-vec[k-2].y))<=0)
				k--;
			vec[k++]=num[i];
		}
		for(i=n-1,t=k;i>=0;i--){//上链
			while(k>t&&det(point(vec[k-1].x-vec[k-2].x,vec[k-1].y-vec[k-2].y),
				point(num[i].x-vec[k-2].x,num[i].y-vec[k-2].y))<=0) 
				k--;
			vec[k++]=num[i];
		}
		double ans=0;
		for(i=0;i<k-1;i++){
			ans+=dis(vec[i],vec[i+1]);
		}
		printf("%.0f\n",ans+2*pi*(double)r);
	}
	return 0;
}