#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;
typedef struct node
{
    double x,y;
}point;
const int inf=(1<<30)-1;
const int maxn=100005;
point num[maxn],ln[maxn],rn[maxn];
int n;
double d=inf;
bool judge(point a,point b){
    if(a.x==b.x||a.y==b.y) return false;
    if((a.x-b.x)*(a.y-b.y)<0) return true;
}
int sum=0;
void Merge(point *num,int left,int mid,int right)
{
    int n1=mid-left+1,n2=right-left,i,j,k;
    for(i=0;i<n1;i++)
        ln[i]=num[i+left];
    ln[n1].x=ln[i].y=inf;
    for(i=0;i<n2;i++)
        rn[i]=num[mid+i+1];
    rn[n2].x=rn[n2].y=inf;
    i=j=0;
    for(k=left;k<=right;k++)
    {
        if(ln[i].y<rn[j].y){
            num[k]=ln[i++];
        }
        else{
            num[k]=rn[j++];
            sum=sum+
        }
    }
    return ;
}
 
void Sort(point *num,int left,int right)
{
    if(left<right)
    {
        // int mid=pivot(num,left,right);
        Sort(num,left,mid-1);
        Sort(num,mid+1,right);
        Merge(num,left,mid,right); 
    }
    return ;
}
 
int main()
{
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        for(int i=0; i<n; i++)
            scanf("%lf %lf",&num[i].x,&num[i].y);
//        sort(num,num+n,cmp_y);
        Sort(num,0,n-1);
//        for(int i=0;i<n;i++)
//            printf("%.2f %.2f\n",num[i].x,num[i].y);
        d=inf;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((num[j].y-num[i].y)>d) break;
                d=min(d,dis(num[i],num[j]));
            }
        }
        d/=2.0;
        printf("%.2f\n",d);
    }
    return 0;
}