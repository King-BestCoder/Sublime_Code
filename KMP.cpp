#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <math.h>
#include <time.h>
using namespace std;
typedef long long LL;

template <class T>
inline bool scan_d(T &ret) {
	char c; int sgn;
	if(c=getchar(),c==EOF) return 0; //EOF-
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	 	sgn=(c=='-')?-1:1;
	 	ret=(c=='-')?0:(c-'0');
		while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
	 	ret*=sgn;
	return 1;
}

inline void out(int x) {
	if(x>9) out(x/10);
 	putchar(x%10+'0');
}

int n,m;
const int maxn=1000005;
int a[maxn],b[10005];
// vector<int>nextt;
int nextt[10005];

void getnextt(){
	int k;
	nextt[0]=-1;
	for(int i=1;i<m;i++){
		k=nextt[i-1];
		while(k!=-1&&b[i-1]!=b[k])
			k=nextt[k];
		nextt[i]=k+1;
	}
}

int KMP(){
	getnextt();
	int i=0,j=0;
	while(i<n){
		while(j!=-1&&b[j]!=a[i])
			j=nextt[j];
		if(j==m-1) return i-m+1+1;
		i++,j++;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int T;
	scan_d(T);
	while(T--){
		memset(nextt,0,sizeof(nextt));
		scan_d(n),scan_d(m);
		for(int i=0;i<n;i++)
			scan_d(a[i]);
		for(int i=0;i<m;i++)
			scan_d(b[i]);
		printf("%d\n",KMP());
	}
	return 0;
}
