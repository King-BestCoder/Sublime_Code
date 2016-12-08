#include <bits/stdc++.h>

using namespace std;
const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};
int n,m;
const int maxn=100;
char s[maxn][maxn];
int used[maxn][maxn][4];
typedef pair<int,int>pii;
int nx,ny;
typedef struct Node{
    int x,y,sum,dir;
    Node(int a=0,int b=0,int a1=0,int b1=0){
        x=a,y=b,sum=a1,dir=b1;
    }
    friend bool operator < (const Node &a,const Node &b){
        return a.sum>b.sum;
    }
}node;

void start(){
    for(nx=0;nx<n;nx++){
        for(ny=0;ny<m;ny++)
            if(s[nx][ny]=='@') return ;
    }
}
int ans=0;

void dfs(int i,int j,int cnt){

}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        memset(s,0,sizeof(s));
        memset(used,0,sizeof(used));
        for(int i=0;i<n;i++)
            scanf("%s",&s[i]);
        ans=0;
        start();
        node p,q;
        p.x=nx,p.y=ny,p.dir=-1;
        priority_queue<node>que;
        que.push(p);
        int flag=0;
        while(que.size()){
            p=que.top();
            que.pop();
            if(p.x==0||p.x==n-1||p.y==0||p.y==m-1){
                flag=1;
                break;
            }
            for(int i=0;i<4;i++){
                q.x=p.x+dx[i];
                q.y=p.y+dy[i];
                q.sum=p.sum+1;
                q.dir=i;
                if(!used[q.x][q.y][i]&&s[q.x][q.y]!='#'){
                    if(i%2==p.dir%2){
                        if(i==p.dir)
                        {
                            if(i&1&&s[p.x-1][p.y]=='#' &&s[p.x+1][p.y]=='#'){
                               used[q.x][q.y][i]=true;
                               que.push(q);
                            }
                           if(!(i&1) &&s[p.x][p.y-1]=='#' &s[p.x][p.y+1]=='#'){
                               used[q.x][q.y][i]=true;
                               que.push(q);
                            }
                        }
                    }
                    else{
                        used[q.x][q.y][i]=true;
                        que.push(q);
                    }
                }
            }
        }
        if(!flag) p.sum=-1;
        printf("%d\n",p.sum);
    }
    return 0;
}



// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <cmath>
// #include <string>
// #include <queue>
// using namespace std;
// chars[100][100];
// bool used[100][100][4];
// int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
// struct Node{
//     int x,y,step,d;
//     Node(int a=0,int b=0,int c=0,intdd=0){x=a;y=b;step=c;d=dd;}
//     friend bool operator<(constNode a,const Node b){
//         return a.step>b.step;
//     }
// };

// int bfs(int x,int y,int n,int m){
//     Node p,q;
//     p.x=x;p.y=y;p.d=-1;
//     priority_queue<Node> q;
//     q.push(p);
//     while(!q.empty()){
//         p=q.top();
//         q.pop();
//         if(p.x==n-1 || p.x==0 ||p.y==0 || p.y==m-1)
//             return p.step;
//         for(int i=0;i<4;++i){
//             q.x=p.x+dx[i];
//             q.y=p.y+dy[i];
//             q.step=p.step+1;
//            q.d=i;
//            if(!used[q.x][q.y][i] &&s[q.x][q.y]!='#'){
//                 if(i%2==p.d%2){
//                     if(i==p.d)
//                     {
//                         if(i&1&&s[p.x-1][p.y]=='#' &&s[p.x+1][p.y]=='#'){
//                            used[q.x][q.y][i]=true;
//                            q.push(q);
//                         }
//                        if(!(i&1) &&s[p.x][p.y-1]=='#' &s[p.x][p.y+1]=='#'){
//                            used[q.x][q.y][i]=true;
//                            q.push(q);
//                         }
//                     }
//                 }
//                 else{
//                    used[q.x][q.y][i]=true;
//                     q.push(q);
//                 }
//             }
//         }
//     }
//     return -1;
// }

// int main(){
//     int t,n,m,i,j,x,y;
//     scanf("%d",&t);
//     while(t--){
//        scanf("%d%d",&n,&m);
//         for(i=0;i<n;++i){
//            scanf("%s"s[i]);
//             for(j=0;j<m;++j){
//                 ifs[i][j]=='@'){
//                     x=i;y=j;
//                 }
//             }
//         }
//         memset(used,false,sizeof(used));
//         int ans=bfs(x,y,n,m);
//        printf("%d\n",ans);
//     }
//     return 0;
// }
