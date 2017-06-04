#include <bits/stdc++.h>
using namespace std;
const int maxn=55;
char s[maxn][1005];

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		memset(s,0,sizeof(s));
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%s",s[i]);
		}
		string str;
		int ans=0;
		int word[200];
		for(int i=0;i<m;i++){
			memset(word,0,sizeof(word));
			for(int j=0;j<n;j++){
				word[s[j][i]]++;
			}
			int maxc=max(word['A'],max(word['T'],max(word['C'],word['G'])));
			if(word['A']==maxc) str+='A';
			else if(word['C']==maxc) str+='C';
			else if(word['G']==maxc) str+='G';
			else str+='T';
			ans+=n-maxc;
		}
		cout<<str<<endl<<ans<<endl;
	}
	return 0;
}