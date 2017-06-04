#include <bits/stdc++.h>
using namespace std;
const int maxn=25;
char s[maxn][maxn];
int vis[maxn][maxn];
typedef struct Node{
	int id;
	string str;
	Node(int i,string str1){
		id=i;
		str=str1;
	}
}node;
bool cmp(node a,node b){
	return a.id<b.id;
}
int main(int argc, char const *argv[])
{
	int n,m;
	int cas=0;
	while(~scanf("%d",&n)&&n){
		scanf("%d",&m);
		for(int i=0;i<n;i++)
			scanf("%s",s[i]);
		int t=1;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(s[i][j]!='*'&&(!i||!j||s[i-1][j]=='*'||s[i][j-1]=='*')){
					vis[i][j]=t++;
				}
			}
		}
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<m;j++){
		// 		printf("%d%c",vis[i][j],j==m-1?'\n':' ');
		// 	}
		// }
		if(cas>=1) printf("\n");
		printf("puzzle #%d:\n",++cas);
		printf("Across\n");
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(vis[i][j]){
					printf("%3d.",vis[i][j]);
					while(j<m&&s[i][j]!='*'){
						printf("%c",s[i][j]);
						j++;
					}
					printf("\n");
				}
			}
		}

		printf("Down\n");
		vector<node>vec;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(vis[j][i]){
					int temp=vis[j][i];
					string str;
					while(j<n&&s[j][i]!='*'){
						str+=s[j][i];
						j++;
					}
					vec.push_back(node(temp,str));
				}
			}
		}
		sort(vec.begin(),vec.end(),cmp);
		for(int i=0;i<vec.size();i++){
			printf("%3d.",vec[i].id);
			cout<<vec[i].str<<endl;
		}
	}
	return 0;
}