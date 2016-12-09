#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int inf=0x3f3f3f3f;
const int N=601;
typedef long long LL;
LL dis[N];
int vis[N];
LL map[N][N];
 
int n,m;
LL mi(LL a,LL b){
    return a>b?b:a;
}

void dijkstra()
{
    memset(vis,0,sizeof(vis));
    memset(dis,inf,sizeof(dis));
    dis[1]=0;
    for(int i=1; i<=n; i++)
    {
        int min=inf,pos=-1;
        for(int j=1; j<=n; j++)
        {
            if(vis[j]==0&&min>dis[j])
                min=dis[j],pos=j;
        }
        vis[pos]=1;
        for(int j=1; j<=n; j++)
        {
            if(vis[j]==0)
                dis[j]=mi(dis[j],dis[pos]+map[pos][j]);
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j) 
                map[i][j]=0;
			else  
                map[i][j]=inf;
 
    int a,b;
    LL c;
 
    for(int i=0; i<m; i++){
        scanf("%d %d %I64d",&a,&b,&c);
        if(c<map[a][b])
            map[a][b]=c;
    }
    if(map[1][n]==inf)
        printf("-1\n");
    else{
        dijkstra();
        printf("%I64d\n",dis[n]);
    }
    return 0;
}