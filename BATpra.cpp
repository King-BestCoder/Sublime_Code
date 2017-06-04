#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 500005
const int INF=1000000000;
int siz[maxn],son[maxn][2],key[maxn],psum[maxn],ssum[maxn],msum[maxn],sum[maxn];
int lazy[maxn],tag[maxn],father[maxn];
int n,m,rt=1,tot=1,st[maxn],top,a[maxn];
 
inline int read(void) 
{
    char ch=getchar();
    int x=0,f=1;
    while (ch<'0'||ch>'9') 
    {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') 
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
 
inline int nw(void) 
{
    int x;
    if (top>0) x=st[top--];else x=++tot;
    lazy[x]=tag[x]=son[x][0]=son[x][1]=0;
    return x;
}
 
inline int wh(int x) 
{
    return x==son[father[x]][1];
}
 
inline void update(int x) 
{
    siz[x]=siz[son[x][0]]+siz[son[x][1]]+1;
    sum[x]=sum[son[x][0]]+sum[son[x][1]]+key[x];
    psum[x]=max(psum[son[x][0]],key[x]+sum[son[x][0]]+max(0,psum[son[x][1]]));
    ssum[x]=max(ssum[son[x][1]],key[x]+max(ssum[son[x][0]],0)+sum[son[x][1]]);
    msum[x]=max(max(msum[son[x][0]],msum[son[x][1]]),max(ssum[son[x][0]],0)+max(psum[son[x][1]],0)+key[x]);
}
 
inline void rotate(int x) 
{
    int f=father[x],g=father[f],opt=wh(x);
    if (g) son[g][wh(f)]=x;father[x]=g;
    son[f][opt]=son[x][opt^1];father[son[x][opt^1]]=f;
    son[x][opt^1]=f;father[f]=x;
    update(f);update(x);
}
 
inline void splay(int x,int goal) 
{
    while (father[x]!=goal) 
    {
        if (father[father[x]]!=goal) 
            rotate(wh(x)==wh(father[x])?father[x]:x);
        rotate(x);
    }
    if (goal==0) rt=x;
}
 
inline void paint(int x) 
{
    lazy[x]^=1;
    swap(son[x][0],son[x][1]);
    swap(psum[x],ssum[x]);
}
 
inline void paint(int x,int v) 
{
    tag[x]=1;lazy[x]=0;
    key[x]=v;sum[x]=siz[x]*v;
    msum[x]=psum[x]=ssum[x]=max(v,sum[x]);
}
 
inline void push_down(int x) 
{
    if (lazy[x]) 
    {
        if (son[x][0]) paint(son[x][0]);
        if (son[x][1]) paint(son[x][1]);
        lazy[x]=0;
    }
    if (tag[x]) 
    {
        if (son[x][0]) paint(son[x][0],key[x]);
        if (son[x][1]) paint(son[x][1],key[x]);
        tag[x]=0;
    }
}
 
void build(int x,int l,int r) 
{
    int mid=(l+r)>>1;
    key[x]=a[mid];
    if (l==r) 
    {
        siz[x]=1;
        sum[x]=msum[x]=psum[x]=ssum[x]=key[x];
        return;
    }
    if (l<mid) son[x][0]=nw(),father[son[x][0]]=x,build(son[x][0],l,mid-1);
    if (r>mid) son[x][1]=nw(),father[son[x][1]]=x,build(son[x][1],mid+1,r);
    update(x);
}
 
int Kth(int x,int k) 
{
    if (x==0) return -1;
    push_down(x);
    if (siz[son[x][0]]+1==k) return x;
    if (siz[son[x][0]]+1<k) return Kth(son[x][1],k-siz[son[x][0]]-1);
    if (siz[son[x][0]]+1>k) return Kth(son[x][0],k);
}
 
void Ins(void) 
{
    int k=read(),t=read();
    for (int i=1;i<=t;i++) a[i]=read();
    int p=Kth(rt,k+1);splay(p,0);
    int x=Kth(rt,k+2);splay(x,p);
    son[x][0]=nw();father[son[x][0]]=x;
    build(son[x][0],1,t);
    update(x);update(p);
}
 
void erase(int x) 
{
    if (x==0) return;
    st[++top]=x;
    if (son[x][0]) erase(son[x][0]);
    if (son[x][1]) erase(son[x][1]);
}
 
void Del(void) 
{
    int k=read(),t=read();
    int p=Kth(rt,k);splay(p,0);
    int x=Kth(rt,k+t+1);splay(x,p);
    erase(son[x][0]);father[son[x][0]]=0;son[x][0]=0;
    update(x);update(p);
}
 
void Rev(void) 
{
    int k=read(),t=read();
    int p=Kth(rt,k);splay(p,0);
    int x=Kth(rt,k+t+1);splay(x,p);
    paint(son[x][0]);
    update(x);update(p);
}
 
void Mak(void) 
{
    int k=read(),t=read(),v=read();
    int p=Kth(rt,k);splay(p,0);
    int x=Kth(rt,k+t+1);splay(x,p);
    paint(son[x][0],v);
    update(x);update(p);
}
  
int Sum(void) 
{
    int k=read(),t=read();
    int p=Kth(rt,k);splay(p,0);
    int x=Kth(rt,k+t+1);splay(x,p);
    return sum[son[x][0]];
}   
  
int main()
{
    n=read();m=read();
    for (int i=1;i<=n;i++) a[i+1]=read();
    a[1]=a[n+2]=-INF;psum[0]=ssum[0]=msum[0]=-INF;
    build(rt,1,n+2);
    for (int i=1;i<=m;i++) 
    {
        char s[10];
        scanf("%s",s);
        if (s[0]=='I') Ins();
        if (s[0]=='D') Del();
        if (s[0]=='R') Rev();
        if (s[2]=='K') Mak();
        if (s[0]=='G') printf("%d\n",Sum());
        if (s[2]=='X') printf("%d\n",msum[rt]);
    }
    return 0;
}