#include <bits/stdc++.h>
using namespace std;
int n,m,t;
map<string,int>mapint;
int cnt=1,ans=0;
string a,b;
const int maxn=105;
int cost[maxn][maxn];
const int inf=0x3f3f3f3f;
int main(int argc, char const *argv[])
{
	while(~scanf("%d %d",&n,&m)){
		cnt=ans=0;
		mapint.clear();
		for(int i=0;i<=100;i++)
			for(int j=0;j<=100;j++)
				cost[i][j]=cost[j][i]=inf;
		for(int i=0;i<m;i++){
			cin>>a>>b>>t;
            if (mapint[a] == 0)
                mapint[a] = cnt++;
            if (mapint[b] == 0)
                mapint[b] = cnt++;
            cost[mapint[a]][mapint[b]] = t;
            cost[mapint[b]][mapint[a]] = t;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				printf("%d%c",cost[i][j],j==n?'\n':' ');
			}
		}
		scanf("%d",&t);
		int ans=0;
		while(t--){
			cin>>a>>b;
			if(!mapint[a]||!mapint[b]) ans=-1;
			else{
				int ia=mapint[a],ib=mapint[b];
				if(cost[ia][ib]==inf) ans=-1;
				else ans=cost[ia][ib];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}