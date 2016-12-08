#include <bits/stdc++.h>  
using  namespace  std;  
#define rrep(i,k,n) for(int i=k;i>=n;i--)  
  
const int N=1e4+10;  
  
char s[N];  
int ans;  
  
int  main(){  
  int t;  
  scanf("%d", &t);  
  while(t--){  
    scanf("%s", s + 1);  
    ans = 0;  
    int n = strlen(s + 1);  
    rrep(i, n, 1){  
      if(s[i] != 'r')continue;  
      for(int q = 2; q <= i; q++){  
        if(i * q > n)break;  
        if(i % q) continue;  
        if(s[i / q] == 'y' && s[i * q] == 'x' || s[i / q] == 'x' && s[i * q] == 'y')ans++;  
      }  
    }  
    printf("%d\n", ans);  
  }  
  return 0;  
}  