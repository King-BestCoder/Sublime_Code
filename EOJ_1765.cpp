#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
const int maxn=20005;

typedef struct Node{
    int w,h;
    friend bool operator < (const Node &a,const Node &b){
        if(a.h<b.h&&a.w<b.w)
            return true;
        else
            return false;
    }
    friend bool operator > (const Node &a,const Node &b){
        if(a.h>b.h&&a.w<b.w)
            return true;
        else
            return false;
    }
}node;

node num[maxn],tmp[maxn];

bool cmp(node a,node b){
    if(a.w>b.w||(a.w==b.w&&a.h<b.h))
        return true;
    else
        return false;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        memset(num,0,sizeof(num));
        memset(tmp,0,sizeof(tmp));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d %d",&num[i].w,&num[i].h);
        sort(num,num+n,cmp);
        for(int i=0;i<n;i++)
            printf("%d  %d\n",num[i].w,num[i].h);
        int ans=0,l,r,mid;
        tmp[ans++]=num[0];
        for(int i=1;i<n;i++){
            l=-1,r=ans-1;
            while(l+1<r){
                mid=l+(r-l)/2;
                if(num[i]<tmp[mid])
                    r=mid;
                else
                    l=mid;
            }
            printf("%d\n",r);
            printf("%d %d\n%d %d\n",num[i].w,num[i].h,tmp[r].w,tmp[r].h);
            if(num[i]<tmp[r])
                tmp[r]=num[i];
            else
                tmp[ans++]=num[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}