#include <bits/stdc++.h>
using namespace std;
int word[26];
int has[26];
const char *s[3]={"You win.","You lose.","You chickened out."};
int main(int argc, char const *argv[])
{
	int kase;
	string a,b;
	while(~scanf("%d",&kase)&&kase!=-1){
		cin>>a>>b;
		int cnt=0;
		int n=a.length(),m=b.length();
		memset(word,0,sizeof(word));
		memset(has,0,sizeof(has));
		for(int i=0;i<n;i++){
			word[a[i]-'a']++;
		}
		int ans=0;
		for(int i=0;i<m;i++){
			if(ans==n) break;
			if(!word[b[i]-'a']||has[b[i]-'a']){
				cnt++;
			}
			else{
				has[b[i]-'a']++;
				ans+=word[b[i]-'a'];
			}
		}
		printf("Round %d\n",kase);
		if(ans==n&&cnt<=6){
			printf("%s\n",s[0]);
		}
		if(cnt>6){
			printf("%s\n",s[1]);
		}
		if(ans!=n&&cnt<=6){
			printf("%s\n",s[2]);
		}
	}
	return 0;
}