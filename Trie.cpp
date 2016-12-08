#include <bits/stdc++.h>
using namespace std;
const int maxn=1000;
const int max_size=128;
int flag=0;
struct trie{
	int ch[maxn][max_size];
	int val[maxn];
	int tot;
	trie(){
		tot=1;
		memset(ch[0],0,sizeof(ch[0]));
	}
	int idx(char c){return c-'a';}
	void insert(char *str){
		flag=0;
		int u=1,n=strlen(str);
		for(int i=0;i<n;i++){
			int c=str[i];
			if(!ch[u][c]){
				tot++;
				memset(ch[tot],0,sizeof(ch[tot]));
				val[tot]=0;
				ch[u][c]=tot;
			}
			u=ch[u][c];
		}
		val[u]++;
	}
	bool sub_str(char *str){
		int u=1,n=strlen(str);
		for(int i=0;i<n&&u;i++){
			int c=str[i];
			printf("%d %d %d\n",u,c,ch[u][c]);
			u=ch[u][c];
		}
		return u;
	}
};
char s[25];
int sum=0;

int main(int argc, char const *argv[])
{
	int cas=1;
	while(~scanf("%s",s)){
		struct trie t;
		flag=0;
		t.insert(s);
	}
	return 0;
}