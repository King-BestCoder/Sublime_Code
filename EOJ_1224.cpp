#include <bits/stdc++.h>

using namespace std;
const int maxn=205;
typedef long long LL;
typedef pair<int,int>pii;
char s[maxn][maxn],tmp[maxn][maxn];
int mx,my,cx,cy;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};
int nx,ny,n,m;
bool used[maxn][maxn];
using namespace std;
typedef struct Node{
    int x,y,sum;
}node;
bool operator < (const Node a,const Node b){
    return a.sum>b.sum;
}
int main()
{
    while(~scanf("%d %d",&n,&m)){
        memset(s,0,sizeof(s));
        memset(tmp,0,sizeof(tmp));
        memset(used,false,sizeof(used));
        for(int i=0;i<n;i++){
            scanf("%s",s[i]);
            strcpy(tmp[i],s[i]);
        }
        for(cx=0;cx<n;cx++){
            for(cy=0;cy<m;cy++)
                if(s[cx][cy]=='S') break;
            if(s[cx][cy]=='S') break;
        }
        for(mx=0;mx<n;mx++){
            for(my=0;my<m;my++)
                if(s[mx][my]=='T') break;
            if(s[mx][my]=='T') break;
        }
        int flag=0;
        priority_queue<node>que;
        node p;
        p.x=cx,p.y=cy,p.sum=0;
        que.push(p);
        while(que.size()){
            p=que.top();
            que.pop();
            if(p.x==mx&&p.y==my){
                flag=1;
                break;
            }
            s[p.x][p.y]='#';
            used[p.x][p.y]=true;
            for(int i=0;i<4;i++){
                nx=p.x+dx[i],ny=p.y+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&!used[nx][ny]&&s[nx][ny]!='#'){
                    node q;
                    q.x=nx,q.y=ny;
                    q.sum=s[nx][ny]=='X'?p.sum+2:p.sum+1;
                    que.push(q);
                    used[nx][ny]=true;
                }
            }
        }
        if(!flag) printf("impossible\n");
        else{
            printf("%d\n",p.sum);
        }
    }
    return 0;
}