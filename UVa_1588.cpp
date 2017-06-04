#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
char s1[maxn],s2[maxn];

int main(int argc, char const *argv[])
{
	while(~scanf("%s %s",s1,s2)){
		int n=strlen(s1),m=strlen(s2);
		int ans1=0;
		int i,j,t;
		i=j=t=0;
		while(i<n&&j<m){
			if(s1[i]+s2[j]-96<=3){
				i++;
				j++;
			}
			else{
				i=0;
				j=++t;
			}
		}
		ans1=m+n-i;
		i=j=t=0;
		while(i<m&&j<n){
			if(s2[i]+s1[j]-96<=3){
				i++,j++;
			}
			else{
				i=0;
				j=++t;
			}
		}
		ans1=min(ans1,m+n-i);
		printf("%d\n",ans1);
	}
	return 0;
}