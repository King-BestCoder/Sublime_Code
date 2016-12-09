#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
// #include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <math.h>
#include <time.h>
using namespace std;

const int st_size=(1<<15)-1;
const int maxn=20005;
const double M_PI=acos(-1.0);

int n,c;
int L[maxn],S[maxn],A[maxn];

double vx[st_size],vy[st_size];
double ang[st_size];
double prv[maxn];

void init(int k,int l,int r){
	ang[k]=vx[k]=0.0;
	if(r-l==1){
		vy[k]=L[l];
	}
	else{
		int chl=k*2+1,chr=k*2+2;
		init(chl,l,(l+r)/2);
		init(chr,(l+r)/2,r);
		vy[k]=vy[chl]+vy[chr];
	}
}

void change(int s,double a,int v,int l,int r){
	if(s<=l) return ;
	else if(s<r){
		int chl=v*2+1,chr=v*2+2;
		int m=(l+r)/2;
		change(s,a,chl,l,m);
		change(s,a,chr,m,r);
		if(s<=m) ang[v]+=a;

		double s=sin(ang[v]),c=cos(ang[v]);
		vx[v]=vx[chl]+(c*vx[chr]-s*vy[chr]);
		vy[v]=vy[chl]+(s*vx[chr]+c*vy[chr]);

	}
}

void solve(){
	init(0,0,n);
	for(int i=1;i<n;i++) prv[i]=M_PI;

	for(int i=0;i<c;i++){
		int s=S[i];
		double a=A[i]/360.0*2*M_PI;
		change(s,a-prv[s],0,0,n);
		prv[s]=a;
		printf("%.2f %.2f\n",vx[0],vy[0]);
	}
}

int main(int argc, char const *argv[])
{
	while(~scanf("%d %d",&n,&c)){
		memset(L,0,sizeof(L));
		memset(A,0,sizeof(A));
		memset(S,0,sizeof(S));
		for(int i=0;i<n;i++)
			scanf("%d",&L[i]);
		for(int i=0;i<c;i++)
			scanf("%d %d",&S[i],&A[i]);
		solve();
		printf("\n");
	}
	return 0;
}