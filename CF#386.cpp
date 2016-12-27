#include <bits/stdc++.h>
using namespace std;
const int maxn=2005;
int s,x1,x2,t1,t2,p,d;
char s[maxn],str[maxn];
void change(int &a,int &dir){
	a+=dir;
	if(a>=s){
		dir=-dir;
	}
}
int main(int argc, char const *argv[])
{
	while(~scanf("%d %d %d",&s,&x1,&x2)){
		scanf("%d %d",&t1,&t2);
		scanf("%d %d",&p,&d);
		int ans=0;
		int dir2=x2-x1;
		int len;
		if(dir==dir2) len=abs(x1-p);
		else len=abs(s-p+s-x1);
	}
	return 0;
}