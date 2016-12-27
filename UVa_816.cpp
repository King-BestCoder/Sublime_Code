#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int has_edge[maxn][maxn][maxn][maxn];
const char *dirs="NESW";
const char *turns="FLR";
int dir_id(char c){
	return strchr(dirs,c)-dirs;
}
int turns_id(char c){
	return strchr(turns,c)-turns;
}
const int dr[]={-1,0,1,0};
const int dc[]={0,1,0,-1};
struct Node{
	int r,c,dir;
	Node(int x,int y,int z){
		r=x,c=y,dir=z;
	}
};
Node walk(const Node &u,int turn){
	int dir=u.dir;
	if(turn==1) dir=(dir+3)%4;
	if(turn==2) dir=(dir+1)%4;
	return Node(u.r+dr[dir],u.c+dc[dir],dir);
}
void solve(){
	queue<Node>que;
	memset(d,-1,sizeof(d));
	Node u(r1,c1,dir);
	
}
int main(int argc, char const *argv[])
{
	
	return 0;
}