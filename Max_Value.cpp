#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
const int maxn=50005;
typedef struct Node{
	int x,y;
}node;
node num[maxn];
int n;
bool cmp(node a,node b){
	if(a.x!=b.x)
		return a.x<b.x;
	else
		return a.y<b.y;
}
priority_queue<int,vector<int>,greater<int> >que;

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
	scan_d(n);
	for(int i=0;i<n;i++){
		scan_d(num[i].x);
		scan_d(num[i].y);
	}
	sort(num,num+n,cmp);
	LL ans=0;
	for(int i=0;i<n;i++){
		if(num[i].x>que.size()){
			ans+=num[i].y;
			que.push(num[i].y);
		}
		else{
			if(num[i].y>que.top()){
				ans=ans-que.top()+num[i].y;
				que.pop();
				que.push(num[i].y);
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
