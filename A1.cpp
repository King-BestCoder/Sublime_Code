#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

typedef struct Node{
    int x,y;
}node;
node num[10005];
bool cmp(node a,node b){
    if(a.y!=b.y)
        return a.y<b.y;
    else 
        return a.x<b.x;
}

int main(int argc, char const *argv[])
{
    int n;
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++)
            scanf("%d %d",&num[i].x,&num[i].y);
        int ans=1;
        sort(num,num+n,cmp);
        // for(int i=0;i<n;i++)
        //     printf("%d %d\n",num[i].x,num[i].y);
        int sta=num[0].y;
        for(int i=1;i<n;i++){
            if(num[i].x>=sta){
                ans++;
                sta=num[i].y;
            }
            else{
                continue;
            }
        }
        printf("Case #%d:\n",t);
        printf("%d\n",ans);
    }
    return 0;
}