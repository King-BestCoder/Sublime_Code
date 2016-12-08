#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=355;
char s[maxn],s1[maxn],s2[maxn];
int num1[maxn],num2[maxn];
int n;
 
int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++){
        if(s[i]=='w'){
            s1[i]='b',s2[i]='r';
        }
        else
            s1[i]=s2[i]=s[i];
    }
    for(int i=0;i<n;i++){
        int cnt=0,j=i;
        while(s1[j]==s1[i]){
            cnt++;
            j=(j+1+n)%n;
            if(cnt>=n) break;
        }
        num1[i]=max(num1[i],cnt);
        cnt=0,j=i;
        while(s2[j]==s2[i]){
            cnt++;
            j=(j+1+n)%n;
            if(cnt>=n) break;
        }
        num1[i]=max(num1[i],cnt);
    }
    for(int i=0;i<n;i++){
        int cnt=0,j=i;
        while(s1[j]==s1[i]){
            j=(j-1+n)%n;
            cnt++;
            if(cnt>=n) break;
        }
        num2[i]=max(num2[i],cnt);
        cnt=0,j=i;
        while(s2[j]==s2[i]){
            cnt++;
            j=(j-1+n)%n;
            if(cnt>=n) break;
        }
        num2[i]=max(num2[i],cnt);
    }
    int ans=0;
   // for(int i=0;i<n;i++)
   //     printf("%c%c",s[i],i==n-1?'\n':' ');
   // for(int i=0;i<n;i++)
   //     printf("%d%c",num1[i],i==n-1?'\n':' ');
   // for(int i=0;i<n;i++)
   //     printf("%d%c",num2[i],i==n-1?'\n':' ');
    for(int i=0;i<n;i++){
    	int a=num2[i],b=num1[(i+1+n)%n];
    	if((a+b)>=n)
    		ans=n;
    	else
    		ans=max(ans,(a+b));
        // ans=max(ans,num2[i]+num1[(i+1+n)%n]);
    }
    printf("%d\n",ans);
    return 0;
}