#include<iostream>
#include<stdio.h>
#include<string.h>
#define lson (id*2)
#define rson (id*2+1)
using namespace std;
struct node{
    int lx,rx,val;
}tr[100002*8];
int a[200005];
int n,m;
int ans;
void push_up(int id,int l,int r)
{
    int mid=(l+r)>>1;
    if(a[mid]==a[mid+1])tr[id].val=max(tr[lson].rx+tr[rson].lx,max(tr[lson].val,tr[rson].val));
    else tr[id].val=max(tr[lson].val,tr[rson].val);

    if(tr[lson].lx==mid-l+1&&a[mid]==a[mid+1])
    tr[id].lx=tr[lson].rx+tr[rson].lx;
    else tr[id].lx=tr[lson].lx;

    if(tr[rson].rx==r-mid&&a[mid]==a[mid+1])
    tr[id].rx=tr[rson].lx+tr[lson].rx;
    else tr[id].rx=tr[rson].rx;
}
void build(int id,int l,int r)
{
    if(l==r)
    {
        tr[id].lx=tr[id].rx=tr[id].val=1;
        return;
    }
    int mid=(l+r)>>1;
    build(lson,l,mid);
    build(rson,mid+1,r);
    push_up(id,l,r);
    //cout<<l<<"  "<<r<<"           "<<tr[id].val<<endl;
}
int query(int id,int L,int R,int l,int r)
{
    if(L>r||R<l||R<L) return 0;
    if(L>=l&&R<=r) return tr[id].val;
    int mid=(L+R)>>1;
    int m=1,m1=1,m2=1;
    if(a[mid+1]==a[mid]) m=min(mid-l+1,tr[lson].rx)+min(r-mid,tr[rson].lx);
    if(l<=mid)
    m1=query(lson,L,mid,l,r);
    if(r>mid)
    m2=query(rson,mid+1,R,l,r);
    m=max(max(m1,m2),m);
    return m;

}
int main()
{
    while(scanf("%d",&n))
    {
        if(n==0) return 0;
        int aa,bb;
        scanf("%d",&m);
        for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
        build(1,1,n);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&aa,&bb);
            printf("%d\n",query(1,1,n,aa,bb));
        }
        for(int i=1;i<=n;i++){
            printf("%d %d %d\n",tr[i].lx,tr[i].rx,tr[i].val);
        }
    }

}