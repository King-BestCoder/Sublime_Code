#include <bits/stdc++.h>

using namespace std;
const int dx[]={0,1,0,-1,-1,-1,1,1};
const int dy[]={-1,0,1,0,-1,1,-1,1};
int n,m;
const int maxn=800;
int num[maxn][maxn];
int used[maxn][maxn];
int high,cnt;
typedef pair<int,int>pii;
int nx,ny;
void paint(int tx,int ty,int t){
    for(int i=0;i<4;i++){
        nx=dx[i]+tx,ny=dy[i]+ty;
        if(nx>=0&&nx<n&&ny>=0&&ny<m){
            num[nx][ny]=t;
            used[nx][ny]=1;
        }
    }
}
int flag=0;

void dfs(int tx,int ty){
    for(int i=0;i<8;i++){
        nx=tx+dx[i];
        ny=ty+dy[i];
        if(nx>=0&&nx<n&&ny>=0&&ny<m){
            if(num[nx][ny]>high){
                flag=0;
            }
            else if(num[nx][ny]==high&&!used[nx][ny]){
                used[nx][ny]=1;
                dfs(nx,ny);
            }
        }
    }
}

int main()
{
    while(~scanf("%d %d",&n,&m)){
        memset(used,0,sizeof(used));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&num[i][j]);
        int ans=0;
        high=0,cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(num[i][j]!=0&&!used[i][j]){
                    flag=1;
                    high=num[i][j];
                    dfs(i,j);
                    if(flag){
                        ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}