#include <bits/stdc++.h>

using namespace std;
const int maxn=100;
char s[maxn][maxn];
int num[maxn][4];
int cnt=0;
int tx,ty;
int flag=0;
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
bool judge(int i,int j){
    return (i>=1&&i<=7&&j>=1&&j<=7);
}
void done(){
    for(int i=1;i<=7;i++){
        for(int j=1;j<=7;j++){
            if(s[i][j]=='E'){
                s[i][j]='e';
                tx=i,ty=j;
            }
            else if(s[i][j]=='O'){
                s[i][j]='o';
                tx=i,ty=j;
                // num[cnt][0]=i,num[cnt][1]=j;
                cnt++;
            }
            else if(s[i][j]=='o'){
                // num[cnt][0]=i,num[cnt][1]=j;
                cnt++;
            }
        }
    }
}
void print(){
    for(int i=1;i<cnt;i++){
            printf("%d. (%d, %d) to (%d, %d)\n",i,num[i][1],num[i][0],num[i][3],num[i][2]);
        }
}
void dfs(int step,int sum){
    if(flag) return ;
    if(step==sum){
        if(s[tx][ty]=='o'){
            flag=1;
            print();
            return ;
        }
        return ;
    }
    // printf("%d\n",step);
    int x,y,xx,yy,xxx,yyy,k;
    for(x=1;x<=7;x++){
        for(y=1;y<=7;y++){
            if(s[x][y]=='o'){
                for(k=0;k<4;k++){
                    xx=x+dx[k],yy=y+dy[k];
                    if(judge(xx,yy)&&s[xx][yy]=='o'){
                        xxx=xx+dx[k],yyy=yy+dy[k];
                        if(judge(xxx,yyy)&&s[xxx][yyy]=='e'){
                            // for(int l=1;l<=7;l++)
                            //     printf("%s\n",s[l]+1);
                            // printf("%d %d %d %d %d %d %d\n",x,y,k,xx,yy,xxx,yyy);
                            s[x][y]='e';
                            s[xx][yy]='e';
                            s[xxx][yyy]='o';
                            num[step][0]=x,num[step][1]=y,num[step][2]=xxx,num[step][3]=yyy;
                            dfs(step+1,sum);
                            // printf("%d %d %d %d\n",num[step][0],num[step][1],num[step][2],num[step][3]);
                            s[x][y]='o';
                            s[xx][yy]='o';
                            s[xxx][yyy]='e';
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    int T;
    scanf("%d\n",&T);
    for(int t=1;t<=T;t++){
        memset(s,0,sizeof(s));
        memset(num,0,sizeof(num));
        flag=cnt=0;
        for(int i=1;i<=7;i++){
            for(int j=1;j<=7;j++){
                scanf("%c",&s[i][j]);
                getchar();
            }
        }
        done();
        // for(int i=1;i<=7;i++)
        //     printf("%s\n",s[i]+1);
        // printf("%d %d\n",tx,ty);
        printf("Dataset %d:\n",t);
        dfs(1,cnt);
        // if(flag){
        //     // for(int i=1;i<cnt;i++){
        //     // printf("%d. (%d, %d) to (%d, %d)\n",i,num[i][1],num[i][0],num[i][3],num[i][2]);
        // // }
        // }
        if(!flag){
            printf("No solution.\n");
        }
        printf("\n");
    }
    return 0;
}