#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define CLR(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f3f
#define LL long long
double x,y,r;
double xx[3];
double yy[3];
double dis(int i)
{
	return ((xx[i] - x) * (xx[i] - x) + (yy[i] - y) * (yy[i] - y));
}
bool check(int i,int j)
{
	double d1,d2;
	d1 = dis(i);
	d2 = dis(j);
	if (d1 == r*r || d2 == r*r)		//点在线上 
		return true;
	if ((d1 > r*r) ^ (d2 > r*r))		//一点在内一点在外，则相交
		return true;
	if ((d1 < r*r) && (d2 < r*r)) 		//两点都在圆内，不想交
		return false;
	//那么最后一种情况就是两点都在外
	if (xx[i] == xx[j])		//斜率不存在，特殊处理 
	{
		double maxy = max (yy[i] , yy[j]);
		double miny = min (yy[i] , yy[j]);
		if (miny > y)
			return false;
		else if (maxy < y)
			return false;
		else if (fabs(x-xx[i]) <= r)		//点到直线的距离小于半径
			return true;
		else
			return false; 
	}
	double maxx = max (xx[i] , xx[j]);
	double minx = min (xx[i] , xx[j]);
	double k,b;
	k = (yy[i] - yy[j]) / (xx[i] - xx[j]);
	b = yy[i] - k * xx[i];
	double A,B,C;
	double K;		//对称轴 
	A = k*k + 1;
	B = 2*k*(b-y) - 2*x;
	C = pow(b-y , 2) + x*x;
	K = -B / 2 / A;
	if (K > maxx)
	{
		if (A*maxx*maxx + B*maxx + C <= r*r)
			return true;
		else
			return false;
	}
	else if (K < minx)
	{
		if (A*minx*minx + B*minx + C <= r*r)
			return true;
		else
			return false;
	}
	else
	{
		if (A*K*K + B*K + C <= r*r)
			return true;
		else
			return false;
	}
}
int main()
{
	int u;
//	freopen("in.txt","r",stdin);
//	freopen("out2.txt","w",stdout);
	scanf ("%d",&u);
	while (u--)
	{
		scanf ("%lf %lf %lf",&x,&y,&r);
		for (int i = 0 ; i < 3 ; i++)
			scanf ("%lf %lf",&xx[i],&yy[i]);
		if (check(0,1) || check(0,2) || check(1,2))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}