#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
#define CLR(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f3f
#define LL long long
struct Num
{
	int num,g;		//实际值，离散化之后的值 
}a[50011];
int n;
int ant[50011];
bool cmp(Num a,Num b)
{
	return a.num < b.num;
}
void add(int x,int y)		//在x位置加y
{
	while (x <= n)
	{
		ant[x] += y;
		x += x & (-x);
	}
}
int Query(int x)		//从1加到x 
{
	int sum = 0;
	while (x)
	{
		sum += ant[x];
		x -= x & (-x);
	}
	return sum;
}
int main()
{
	CLR(ant,0);
	scanf ("%d",&n);
	for (int i = 1 ; i <= n ; i++)
	{
		scanf ("%d",&a[i].num);
		a[i].g = i;
	}
	sort(a+1 , a+1+n , cmp);
	for (int i = 1 ; i <= n ; i++)
		add(i,1);
	int ans = 0;
	for (int i = 1 ; i <= n ; i++)
	{
		ans += Query(a[i].g-1);
		add(a[i].g , -1);
	}
	printf ("%d\n",ans);
	return 0;
}