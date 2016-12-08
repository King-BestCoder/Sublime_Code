#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <set>
using namespace std;

const int MAXN=20010;
int t1[MAXN],t2[MAXN],c[MAXN];//求SA数组需要的中间变量，不需要赋值
//待排序的字符串放在s数组中，从s[0]到s[n-1],长度为n,且最大值小于m,
//除s[n-1]外的所有s[i]都大于0，r[n-1]=0
//函数结束以后结果放在sa数组中
bool cmp(int *r,int a,int b,int l)
{
    return r[a] == r[b] && r[a+l] == r[b+l];
}
void da(int str[],int sa[],int ran[],int height[],int n,int m)
{
    n++;
    int i, j, p, *x = t1, *y = t2;
//第一轮基数排序，如果s的最大值很大，可改为快速排序
    for(i = 0; i < m; i++)c[i] = 0;
    for(i = 0; i < n; i++)c[x[i] = str[i]]++;
    for(i = 1; i < m; i++)c[i] += c[i-1];
    for(i = n-1; i >= 0; i--)sa[--c[x[i]]] = i;
    for(j = 1; j <= n; j <<= 1)
    {
        p = 0;
//直接利用sa数组排序第二关键字
        for(i = n-j; i < n; i++)y[p++] = i;//后面的j个数第二关键字为空的最小
        for(i = 0; i < n; i++)if(sa[i] >= j)y[p++] = sa[i] - j;
//这样数组y保存的就是按照第二关键字排序的结果
//基数排序第一关键字
        for(i = 0; i < m; i++)c[i] = 0;
        for(i = 0; i < n; i++)c[x[y[i]]]++;
        for(i = 1; i < m; i++)c[i] += c[i-1];
        for(i = n-1; i >= 0; i--)sa[--c[x[y[i]]]] = y[i];
//根据sa和x数组计算新的x数组
        swap(x,y);
        p = 1;
        x[sa[0]] = 0;
        for(i = 1; i < n; i++)
            x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        if(p >= n)break;
        m = p;//下次基数排序的最大值
    }
    int k = 0;
    n--;
    for(i = 0; i <= n; i++)ran[sa[i]] = i;
    for(i = 0; i < n; i++)
    {
        if(k)k--;
        j = sa[ran[i]-1];
        while(str[i+k] == str[j+k])k++;
        height[ran[i]] = k;
    }
}
int ran[MAXN],height[MAXN];
int RMQ[MAXN];
int mm[MAXN];
int best[20][MAXN];
void initRMQ(int n)
{
    mm[0]=-1;
    for(int i=1; i<=n; i++)
        mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
    for(int i=1; i<=n; i++)best[0][i]=i;
    for(int i=1; i<=mm[n]; i++)
        for(int j=1; j+(1<<i)-1<=n; j++)
        {
            int a=best[i-1][j];
            int b=best[i-1][j+(1<<(i-1))];
            if(RMQ[a]<RMQ[b])best[i][j]=a;
            else best[i][j]=b;
        }
}
int askRMQ(int a,int b)
{
    int t;
    t=mm[b-a+1];
    b-=(1<<t)-1;
    a=best[t][a];
    b=best[t][b];
    return RMQ[a]<RMQ[b]?a:b;
}
int lcp(int a,int b)
{
    a=ran[a];
    b=ran[b];
    if(a>b)swap(a,b);
    return height[askRMQ(a+1,b)];
}
char str[MAXN];
int r[MAXN];
int sa[MAXN];
int main()
{
    while(scanf("%s",str) == 1)
    {
        int len = strlen(str);
        int n = 2*len + 1;
        for(int i = 0; i < len; i++)r[i] = str[i];
        for(int i = 0; i < len; i++)r[len + 1 + i] = str[len - 1 - i];
        r[len] = 1;
        r[n] = 0;
        da(r,sa,ran,height,n,128);
        for(int i=1; i<=n; i++)RMQ[i]=height[i];
        initRMQ(n);
        int ans=0,st;
        int tmp;
        for(int i=0; i<len; i++)
        {
            tmp=lcp(i,n-i);//偶对称
            if(2*tmp>ans)
            {
                ans=2*tmp;
                st=i-tmp;
            }
            tmp=lcp(i,n-i-1);//奇数对称
            if(2*tmp-1>ans)
            {
                ans=2*tmp-1;
                st=i-tmp+1;
            }
        }
        str[st+ans]=0;
        printf("%s\n",str+st);
    }
    return 0;
}
