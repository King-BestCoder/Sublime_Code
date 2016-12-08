#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int maxn=55;
typedef pair<int,int> pii;
struct node{
	vector<pii>z;
	bool operator < (const struct node &b){
		return z.size()<b.z.size();
	}
}e[maxn*maxn];
char ma[maxn][maxn];
char fu[maxn][maxn];
int n,m,k;
const int dx[]={1,0,0,-1},dy[]={0,1,-1,0};
int ty,tx;
int flag=0;
vector<pii>temp;

void solve(int i,int j){
	if(ma[i][j]=='*'){
		return ;
	}
	if(i==0||i==n-1||j==0||j==m-1||flag)
		flag=1;
	else 
		flag=0;
	ma[i][j]='*';
	temp.push_back(pii(i,j));
	for(int k=0;k<4;k++){
		tx=dx[k]+i,ty=dy[k]+j;
		if(tx>=0&&tx<n&&ty>=0&&ty<m&&ma[tx][ty]=='.'){
			solve(tx,ty);
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d %d %d\n",&n,&m,&k);
	for(int i=0;i<n;i++){
		scanf("%s",ma[i]);
		strcpy(fu[i],ma[i]);
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			flag=0;
			if(ma[i][j]=='.'){
				temp.clear();
				solve(i,j);
				if(!flag){
					// printf("%d %d\n",i,j);
					e[cnt++].z=temp;
				}
			}
		}
	}
	sort(e,e+cnt);
	int ans=0;
	// printf("%d\n",cnt);
	for(int i=0;i<cnt-k;i++){
		for(int j=0;j<e[i].z.size();j++){
			pii p=e[i].z[j];
			fu[p.first][p.second]='*';
			ans++;
		}
	}
	// printf("%d\n",cnt);
	printf("%d\n",ans);
	for(int i=0;i<n;i++)
		printf("%s\n",fu[i]);
	return 0;
}
