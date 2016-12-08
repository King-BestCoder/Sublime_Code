#include <bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
/*

 4 5
 0 1 2
 0 2 4
 1 2 3
 0 2 4
 1 1 4
 1
 2
 */
const int maxn=111111;
int sum[maxn<<2];
int col[maxn<<2];
int a,b,c;
using namespace std;
void pushup(int rt){
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void pushdown(int rt,int m){
    if(col[rt]){
        // printf("root  %d  pushdown  yes\n",rt);
        col[rt]=0;
        col[rt<<1]^=1;
        col[rt<<1|1]^=1;
        sum[rt<<1]=m-(m>>1)-sum[rt<<1];
        sum[rt<<1|1]=(m>>1)-sum[rt<<1|1];
    }
}

void build(int l,int r,int rt){
    col[rt]=0;
    if(l==r){
        sum[rt]=0;
        return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int left,int right,int l,int r,int rt){
    if(left<=l&&right>=r){
        col[rt]^=1;
        sum[rt]=r-l+1-sum[rt];
        return ;
    }
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    if(left<=m){
        // printf("%d  left  update\n",rt);
        update(left,right,lson);
    }
    if(right>m){
        // printf("%d  right  update\n",rt);
        update(left,right,rson);
    }
    pushup(rt);
}

int query(int left,int right,int l,int r,int rt){
    if(left<=l&&right>=r){
        return sum[rt];
    }
    int m=(l+r)>>1;
    int tmp=0;
    pushdown(rt,r-l+1);
    if(left<=m)
        tmp+=query(left,right,lson);
    if(right>m)
        tmp+=query(left,right,rson);
    return tmp;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    build(1,n,1);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&c);
        if(a==0){
            update(b,c,1,n,1);
        }
        else if(a==1){
            printf("%d\n",query(b,c,1,n,1));
        }
    }
    return 0;
}