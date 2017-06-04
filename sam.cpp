#include <bits/stdc++.h>
using namespace std;

const int maxn=250100;
const int inf=1e9+7;

typedef struct suffix_automation{
	int last,tot,step[maxn<<1],pre[maxn<<1],go[maxn<<1][26];
	int new_node(int s){
		step[++tot]=s;
		pre[tot]=0;
		memset(go[tot],0,sizeof(go[tot]));
		return tot;
	}
	void init(){
		memset(step,0,sizeof(step));
		memset(pre,0,sizeof(pre));
		memset(go,0,sizeof(go));
		tot=0;
		last=new_node(0);
	}
	inline int idx(char c){
		return c-'a';
	}
	void insert(char ch){
		int c=idx(ch),p=last,cur=new_node(step[last]+1);
		while(p&&!go[p][c]){
			go[p][c]=cur,p=pre[p];
		}	
		if(!p) pre[cur]=1;
		else{
			int q=go[p][c];
			if(step[q]==step[p]+1) pre[cur]=q;
			else{
				int nq=new_node(step[p]+1);
				memcpy(go[nq],go[q],sizeof(go[q]));
				pre[nq]=pre[q];
				pre[cur]=pre[q]=nq;
				while(p&&go[p][c]==q){
					go[p][c]=nq,p=pre[p];
				}
			}
		}
		last=cur;
	}
	int solve(char s[],int result[]){
		int n=strlen(s),len=0,u=1,ans=0;
		for(int i=0;i<n;i++){
			int c=idx(s[i]);
			if(!go[u][c]){
				while(u&&!go[u][c]){
					u=pre[u];
				}
				if(!u) u=1,len=0;
				else len=step[u]+1,u=go[u][c];
			}
			else{
				len++;
				ans=max(ans,len);
				u=go[u][c];
			}
			result[i]=len;
		}
		return ans;
	}
}sam;

int n,tlen,slen;
char s[maxn],t[maxn];
int common[11][maxn];
sam san;

int check(int l){
	int forcheck=0;
	for(int i=0;i<tlen;){
		if(common[forcheck][i]>=l){
			i+=l;
			forcheck++;
			if(forcheck>=n){
				return 1;
			}
		}
		else{
			i++;
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	scanf("%s",t);
	tlen=strlen(t);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		san.init();
		slen=strlen(s);
		for(int j=0;j<slen;j++){
			san.insert(s[j]);
		}
		san.solve(t,common[i]);
	}
	if(!check(1)){
		printf("-1\n");
		return 0;
	}
	int left=1,right=tlen;
	while(left<right){
		int mid=(left+right+1)/2;
		if(check(mid)) left=mid;
		else right=mid-1;
	}
	printf("%d\n",left);
	return 0;
	return 0;
}