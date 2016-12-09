#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <set>
#include <iomanip>

using namespace std;
const int charset=26,base='0',maxn=10005;
struct Trie
{
	int tot,root,child[maxn][charset];
	bool flag[maxn];
	Trie(){
		memset(child[1],0,sizeof(child[1]));
		flag[1]=false;
		root=tot=1;
	}
	void insert(const char *str){
		int *cur=&root;
		for(const char *p=str;*p;++p){
			cur=&child[*cur][*p-base];
			if(*cur==0){
				*cur=++tot;
				memset(child[tot],0,sizeof(child[tot]));
				flag[tot]=false;
			}
		}
		flag[*cur]=true;
	}
	bool query(const char *str){
		int *cur=&root;
		for(const char *p=str;*p&&*cur;++p){
			cur=&child[*cur][*p-base];
		}
		return (*cur&&flag[*cur]);
	}
};
char s[maxn];
int main(int argc, char const *argv[])
{
	struct Trie t;
	gets(s);
	// puts(s);
	t.insert(s);
	if(t.query(s))
		cout<<"yes"<<endl;
	return 0;
}