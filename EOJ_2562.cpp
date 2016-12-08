#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
using namespace std;
const int maxn=100005;
string s1,s2;
int n;
map<string,int>num;

class dsu
{
private:
    int father[maxn],rank[maxn],sum[maxn];
public:
    dsu()
    {
        for(int i=0; i<=maxn; i++)
        {
            rank[i]=0;
            father[i]=i;
            sum[i]=1;
        }
    }
    int find_set(int node)
    {
        if(father[node]!=node)
        {
            father[node]=find_set(father[node]);
        }
        return father[node];
    }
    bool merge(int node1,int node2)
    {
        int ancestor1=find_set(node1);
        int ancestor2=find_set(node2);
        if(ancestor1!=ancestor2)
        {
            if(rank[ancestor1]>rank[ancestor2])
            {
                swap(ancestor1,ancestor2);
            }
            father[ancestor1]=ancestor2;
            rank[ancestor2]=max(rank[ancestor1]+1,rank[ancestor2]);
            sum[ancestor2]+=sum[ancestor1];
            return true;
        }
        return false;
    }
    int getsum(int a){
        int b=find_set(a);
        return sum[b];
    }
};

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int cnt=1;
        dsu x;
        num.clear();
        for(int i=0;i<n;i++){
            cin>>s1>>s2;
            if(!num[s1]) num[s1]=cnt++;
            if(!num[s2]) num[s2]=cnt++;
//            printf("%d %d\n",num[s1],num[s2]);
            x.merge(num[s1],num[s2]);
            // int ans=x.getsum(num[s1]);
            int ans=max(x.getsum(num[s1]),x.getsum(num[s2]));
            printf("%d\n",ans);
        }
    }
    return 0;
}