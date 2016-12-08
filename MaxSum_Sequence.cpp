#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef long long LL;
LL num[50005];

int main()
{
    LL n,i,j,answer,answerstart=1,answerend=1,endmax;
    scanf("%I64d",&n);
    for(i=1;i<=n;i++)
        scanf("%I64d",&num[i]);
    i=1;
    endmax=num[1];
    answer=num[1];
    for(j=2;j<=n;j++)
    {
    	endmax=max((LL)endmax+num[j],num[j]);
        if(answer<endmax)
        {
            answer=endmax;
            answerstart=i;
            answerend=j;
        }
    }
    printf("%I64d\n",answer);
    return 0;
}