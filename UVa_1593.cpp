#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;
const int maxn=1000005;
int a[maxn],i,j,n,m;
char num[maxn];

int main(){
  memset(a,0,sizeof(0));
  for(i=1;i<=1000001;i++){
   itoa(i,num,10);
   if(strstr(num,"4")!=NULL){a[i]+=a[i-1]+1; continue;}
   if(strstr(num,"62")!=NULL){a[i]+=a[i-1]+1; continue;}
   a[i]=a[i-1];
  }
  scanf("%d%d",&n,&m); int sum,ans;
  while(n!=0&&m!=0){
   sum=m-n+1; ans=sum-(a[m]-a[n-1]);
   printf("%dn",ans);
   scanf("%d%d",&n,&m);
  }
  return 0;
}