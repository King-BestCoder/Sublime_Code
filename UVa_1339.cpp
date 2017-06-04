#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
char s1[maxn],s2[maxn];
int cnt1[26],cnt2[26];
int main(int argc, char const *argv[])
{
	while(~scanf("%s %s",s1,s2)){
		sort(s1,s1+strlen(s1));
		sort(s2,s2+strlen(s2));
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		// printf("%s\n%s\n",s1,s2);
		int n=strlen(s1),m=strlen(s2);
		// printf("%d\n%d\n",n,m);
		for(int i=0;i<n;i++){
			cnt1[s1[i]-'A']++;
		}
		for(int i=0;i<m;i++){
			cnt2[s2[i]-'A']++;
		}
		int flag=1;
		if(n==m){
			sort(cnt1,cnt1+26);
			sort(cnt2,cnt2+26);
			// for(int i=0;i<26;i++)
			// 	printf("%d%c",cnt1[i],i==25?'\n':' ');
			// for(int i=0;i<26;i++)
			// 	printf("%d%c",cnt2[i],i==25?'\n':' ');
			for(int i=0;i<26;i++){
				if(cnt1[i]!=cnt2[i]){
					flag=0;
					break;
				}
			}
		}
		else flag=0;
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}