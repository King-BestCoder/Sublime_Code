#include <Stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <math.h>
#include <time.h>
using namespace std;
const int maxn=500005;
int c[maxn],u[maxn];
 
template <class T>
inline bool scan_d(T &ret) {
	char c; int sgn;
	if(c=getchar(),c==EOF) return 0; //EOF
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

int main(int argc, char const *argv[])
{
	int n,k;
	scan_d(n);
	scan_d(k);
	for(int i=0;i<n;i++){
		scan_d(c[i]);
		scan_d(u[i]);
	}
	int cnt=0,ans=0;
	c[n]=k;
	for(int i=0;i<n;i++){
		if(u[i]==1) continue;
		if(ans+c[i]>=c[i+1])
			continue;
		else{
			ans+=c[i];
			cnt++;
			// printf("%d\n",c[i]);
		}
	}
	if(cnt==0)
		printf("0\n%d\n",k-1);
	else
		printf("%d\n%d\n",cnt,k-ans);
	return 0;
}
