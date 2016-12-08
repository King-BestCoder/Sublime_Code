#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <time.h>
using namespace std;

int Partition(int *num,int p,int r)
{
    int x=num[p];
    int i=p;
    for(int j=p+1;j<=r;j++)
    {
        if(num[j]<=x)
        {
            i++;
            swap(num[i],num[j]);
        }
    }
    swap(num[i],num[p]);
    return i;
}

void Quick_Sort(int *num,int p,int r)
{
    if(p<r)
    {
        int q=Partition(num,p,r);
        Quick_Sort(num,p,q-1);
        Quick_Sort(num,q+1,r);
    }
}
//0.67s
int main()
{
   freopen("data1m.txt","r",stdin);
   freopen("Quick_Sort_1m.txt","w",stdout);
   clock_t s=clock();
    int i,n;
    scanf("%d",&n);
    int *num=new int[n];
    for(i=0;i<n;i++)
        scanf("%d",&num[i]);
    Quick_Sort(num,0,n-1);
    clock_t t=clock();
    printf("%.2f\n",(double)(t-s)/CLOCKS_PER_SEC);
    for(i=0;i<n-1;i++)
        printf("%d ",num[i]);
    printf("%d\n",num[i]);
    return 0;
}
