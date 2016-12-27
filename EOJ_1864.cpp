#include <bits/stdc++.h>
using namespace std;
int n,m;
const int maxm=55;
const int maxn=1005;
int adj[maxm][maxm];
char word[maxm],cube[maxm][maxm];
int ans[maxm];
int used[maxm],match[maxm];

int hungrain(int t){
	for(int i=0;i<n;i++){
		if(adj[t][i]&&!used[i]){
			++used[i];
			if(match[i]==-1||hungrain(match[i])){
				match[i]=t;
				return 1;
			}
		}
	}
	return 0;
}
int max_matched(int len){
	int ans=0;
	memset(match,-1,sizeof(match));
	for(int i=0;i<len;i++){
		memset(used,0,sizeof(used));
		if(hungrain(i))
			ans++;
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	while(~scanf("%d %d",&n,&m)){
		for(int i=0;i<n;i++){	
			scanf("%s",cube[i]);
		}
		int cnt=0;
		for(int i=0;i<m;i++){
			scanf("%s",word);
			memset(adj,0,sizeof(adj));
			int len=strlen(word);
			for(int j=0;j<len;j++){
				for(int k=0;k<n;k++){
					if(strchr(cube[k],word[j])!=NULL)
						adj[j][k]++;
				}
			}
			if(max_matched(len)==len){
				ans[cnt++]=i;
			}
		}
		if(cnt==0) printf("-1\n");
		else{
			for(int i=0;i<cnt;i++)
				printf("%d%c",ans[i],i==cnt-1?'\n':' ');
		}
	}
	return 0;
}