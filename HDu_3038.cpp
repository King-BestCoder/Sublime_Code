#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//带权并查集

const int N=200050;
int n,m;
int fa[N],rankk[N];
void init()
{
    for(int i=0;i<=n;i++)
    {
        fa[i]=i;
        rankk[i]=0;
    }
}

int findd(int x)
{
    if(x==fa[x])return x;
    int temp=fa[x];
    fa[x]=findd(fa[x]);
    rankk[x]+=rankk[temp];
    return fa[x];
}

bool unite(int x,int y,int c)
{
    int xx=findd(x),yy=findd(y);
    if(xx==yy)
    {
        if(rankk[y]!=rankk[x]+c) return false;
        return true;
    }
    fa[yy]=xx;
    rankk[yy]=rankk[x]-rankk[y]+c;
    return true;
}

int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        int lies=0;
        init();
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(a>b) swap(a,b);
            if(!unite(a-1,b,c)) lies++;//区间注意
        }
        printf("%d\n",lies);
    }
}

