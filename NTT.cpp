#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
const double pi=acos(-1.0);
typedef long long LL;
const int N=262144,K=17;

struct comp{
	double r,i;
	comp(double _r=0,double _i=0):r(_r),i(_i){};
	comp operator + (const comp &x){
		return comp(r+x.r,i+x.i);
	}
	comp operator - (const comp &x){
		return comp(r-x.r,i-x.i);
	}
	comp operator * (const comp &x){
		return comp(r*x.r-i*x.i,r*x.i+i*x.r);
	}
};

void FFT(comp a[],int n,int t){
	for(int i=1,j=0;i<n-1;i++){
		for(int s=n;j^=s>>=1,~j&s;);
		if(i<j) swap(a[i],a[j]);
	}
	for(int d=0;(1<<d)<n;d++){
		int m=1<<d,m2=m<<1;
		double o=pi/m*t;
		comp _w(cos(o),sin(o));
		for(int i=0;i<n;i+=m2){
			comp w(1,0);
			for(int j=0;j<m;j++){
				comp &A=a[i+j+m],&B=a[i+j],t=w*A;
				A=B-t;
				B=B+t;
				w=w*_w;
			}
		}
	}
	if(t==-1) {
		for(int i=0;i<n;i++){
			a[i].r/=n;
		}
	}
}


int main(int argc, char const *argv[])
{
	printf("Hello Claris!\n");
	return 0;
}