#include <bits/stdc++.h>

using namespace std;

void Radix_Sort(int *a,int n,int depth){//基数排序
    vector<int>num[10];
    int shift=1;
    for(int i=1;i<=depth;i++)
        shift*=10;
    for(int i=0;i<n;i++){
        int mod=a[i]/shift;
        num[mod%10].push_back(a[i]);
    }
    int k=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<num[i].size();j++){
            a[k++]=num[i][j];
        }
    }
}

int main()
{
//    freopen("data1w.txt","r",stdin);
//    freopen("ans1w.txt","w",stdout);
    int *a;
    int n;
    while(~scanf("%d",&n)){
        a=new int[n];
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<=9;i++)
            Radix_Sort(a,n,i);
        for(int i=0;i<n;i++)
            printf("%d\n",a[i]);
    }
    return 0;
}
