#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long LL;
int n,m;
int num[505][505];

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){r
        for(int j=1;j<=m;j++){
            scanf("%d",&num[i][j]);
        }
    }
   	int *c=new int[n];
   	memset(c,0,sizeof(c));
   	for(int i=1;i<=n;i++){
   		for(int j=i;j<=n;j++){
   			for(int k=i;k<=j;k++){
   				if(i==j) 
   					c[k]=num[i][]
   			}
   		}
   	}
    return 0;
}