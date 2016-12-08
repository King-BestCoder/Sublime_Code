#include <iostream>
#include <stdio.h>
#include <fstream>
#include <time.h>
using namespace std;

int main()
{
    freopen("data1m.txt","r",stdin);
    freopen("Inter_Sort_1m.txt","w",stdout);
    clock_t s=clock();
    int n;
    scanf("%d",&n);
    int *num=new int[n];
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    int i,j,key;
    for(j=1;j<n;j++)
    {
        key=num[j];
        i=j-1;
        while(i>=0&&num[i]>key)
        {
            num[i+1]=num[i];
            i--;
        }
        num[i+1]=key;
    }
    clock_t t=clock();
    printf("%f\n",(double)(t-s)/CLOCKS_PER_SEC);
    for(i=0;i<n;i++)
        printf("%d\n",num[i]);
    return 0;
}
