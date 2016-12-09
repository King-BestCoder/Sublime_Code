#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int inf=(1<<31)-1;
clock_t start;
void Merge(int *num,int p,int q,int r)
{
    int i,j,n1=q-p+1,n2=r-q;
    int *lef=new int[n1+1];
    int *rig=new int[n2+1];
    for(i=0;i<n1;i++)
        lef[i]=num[p+i];
    lef[n1]=inf;
    for(i=0;i<n2;i++)
        rig[i]=num[q+i+1];
    rig[n2]=inf;
    i=j=0;
    for(int k=p;k<=r;k++)
    {
        if(lef[i]<rig[j])
            num[k]=lef[i++];
        else
            num[k]=rig[j++];
    }
    return ;
}

void Merge_Sort(int *num,int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
//        cout<<p<<"   "<<q<<"   "<<r<<endl;
        Merge_Sort(num,p,q);
        Merge_Sort(num,q+1,r);
        Merge(num,p,q,r);
    }
    return ;
}
//1.07s
int main()
{
    freopen("data1m.txt","r",stdin);
    freopen("Merge_Sort_1m.txt","w",stdout);
    clock_t s=clock();
    int n;
    scanf("%d",&n);
    int *num=new int[n];
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    Merge_Sort(num,0,n-1);
    clock_t t=clock();
    printf("%.2f\n",(double)(t-s)/CLOCKS_PER_SEC);
    for(int i=0;i<n;i++)
        printf("%d\n",num[i]);
    return 0;
}
