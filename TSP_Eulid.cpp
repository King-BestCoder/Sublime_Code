#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <vector>
#include <map>
#include <string>
using namespace std;
const int maxn=10055;
typedef long long LL;
// int num[maxn];

int main(int argc, char const *argv[])
{
	LL n,s,a,b,t;
	while(cin>>n>>s>>t>>a>>b){
		if(s<n*b){
			LL m;
			for(m=0;m<n;m++){
				if(s<=m*b) break;
			}
			LL temp=n-m;
			LL x=llabs(a*temp-t),y=llabs(a+b);
			if(x%y!=0){
				printf("CHEATED");
			}
			else{
				LL cnt=x/y;
				for(int i=0;i<m;i++)
					printf("X");
				for(LL i=0;i<temp;i++){
					if(i>=cnt) 
						printf("O");
					else
						printf("X");
				}
			}
		}
		else{
			LL x=llabs(t-s+b*n),y=llabs(a+b);
			if(x%y==0){
				LL cnt=x/y;
				for(LL i=0;i<n;i++){
					if(i<cnt)
						printf("O");
					else
						printf("X");
				}
			}	
			else{
				printf("CHEATED");
			}
		}
		printf("\n");
	}
	return 0;
}