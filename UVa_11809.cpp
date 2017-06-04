#include <bits/stdc++.h>
using namespace std;
const int maxn=25;
char s[maxn];
char a[maxn],b[maxn];
int main(int argc, char const *argv[])
{
	while(~scanf("%s",s)){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int i=0,n=strlen(s);
		cnt=0;
		for(i=0;i<n;i++){
			if(s[i]=='e') break;
			a[cnt++]=s[i];
		}
		cnt=0;
		for(i=i+1;i<n;i++){
			b[cnt++]=s[i];
		}
		
	}
	return 0;
}