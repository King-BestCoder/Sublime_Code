#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double pi=acos(-1.0);
struct P
{
    double x,y;
    P () {}
    P (double x,double y):x(x),y(y){
    }
    P operator -(P p){
        return P(x-p.x,y-p.y);
    }
    double det(P p){
        return x*p.y-y*p.x;
    }
};
double dis(P a,P b)
{
    double c=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    return sqrt(c);
}
bool cmp(P a,P b)
{
    if(a.x!=b.x)
		return a.x<b.x;
    return a.y<b.y;
}
P q[100000],qs[100000];
int main()
{
	int i,k,t,n,r;
	double sum;
    scanf("%d%d",&n,&r);
	k=0;
	for(i=0;i<n;i++)
		scanf("%lf%lf",&q[i].x,&q[i].y);
	sort(q,q+n,cmp);
	for(i=0;i<n;i++)//下链。
	{
		while(k>1 && (qs[k-1]-qs[k-2]).det(q[i]-qs[k-2])<=0) k--;
		qs[k++]=q[i];
	}
	printf("%d\n",k);
	for(i=n-1,t=k;i>=0;i--)//上链
	{
		while(k>t && (qs[k-1]-qs[k-2]).det(q[i]-qs[k-2])<=0) k--;
		qs[k++]=q[i];
	}
	sum=0;
	for(i=0;i<k-1;i++){
		sum+=dis(qs[i],qs[i+1]);
	}
	printf("%d  %.0f\n",k,sum);
	printf("%.0f\n",sum+2*pi*(double)r);
    return 0;
}