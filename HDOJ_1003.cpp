#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
const int maxn=100005;
int num[maxn];

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
	int T,t;
	scan_d(T);
	for(t=1;t<=T;t++){
		int n;
		scan_d(n);
		for(int i=1;i<=n;i++){
			scan_d(num[i]);
		}
		int ans=num[1],anstart=1,ansend=1;
		int tmp=num[1];
		int j=1;
		for(int i=2;i<=n;i++){
			if(tmp>=0)
				tmp+=num[i];
			else{
				tmp=num[i];
				j=i;
			}
			if (tmp>ans)
			{
				ans=tmp;
				anstart=j;
				ansend=i;
			}
		}
		printf("Case %d:\n",t);
		printf("%d %d %d\n",ans,anstart,ansend);
		if(t<T) printf("\n");
	}
	return 0;
}
