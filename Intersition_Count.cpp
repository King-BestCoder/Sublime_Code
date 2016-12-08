#include <iostream>
#include <stdio.h>
#include <fstream>
#include <time.h>
using namespace std;
const int inf=(1<<31)-1;
int cnt=0;

void Merge(int *num,int left,int mid,int right)
{
    int i,j,k,n1=mid-left+1,n2=right-mid;
    int *lnum=new int[n1+1];
    int *rnum=new int[n2+1];
    for(i=0;i<n1;i++)
        lnum[i]=num[left+i];
    lnum[n1]=inf;
    for(i=0;i<n2;i++)
        rnum[i]=num[mid+1+i];
    rnum[n2]=inf;
    i=j=0;
    k=left;
    while(i<n1&&j<n2){
        if(lnum[i]>rnum[j]){
            num[k++]=rnum[j++];
            cnt+=n1-i;
        }
        else{
            num[k++]=lnum[i++];
        }
    }
    while(i<n1) num[k++]=lnum[i++];
    while(j<n2) num[k++]=rnum[j++];
    return ;
}

void Merge_Sort(int *num,int left,int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        Merge_Sort(num,left,mid);
        Merge_Sort(num,mid+1,right);
        Merge(num,left,mid,right);
    }
    return ;
}

//int Inver_merge(int *num1,int n1,int *num2,int n2)
//{
//
//}
//
//void Inver_count(int *num,int n)
//{
//    if(n==1) return ;
//    int r=n/2;
//    Inver_count(num,r);
//    Inver_count(num+r,n-r);
//    Inver_merge(num,r,num+r,n-r);
//}

int main()
{
    // freopen("data.txt","r",stdin);
    // freopen("count.txt","w",stdout);
    // clock_t s;
    int n;
    scanf("%d",&n);
    int *num=new int[n];
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    cnt=0;
    Merge_Sort(num,0,n-1);
    // printf("%.2f\n",(double)clock()/CLOCKS_PER_SEC);
    printf("%d\n",cnt);
    return 0;
}
