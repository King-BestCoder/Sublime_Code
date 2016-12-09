#include <stdio.h>
#include <string>
#include <iostream>
#include <set>
#include <stack>
#include <queue>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
using namespace std;
typedef long long LL;
const int maxn=10005;
int num[maxn];

int main(int argc, char const *argv[])
{
	LL n,m;
	while(~scanf("%I64d %I64d",&n,&m)){
		if(n<=1&&m<=1){
			printf("0\n");
			continue;
		}
		if(n<=2&&m<=2){
			printf("1\n");
			continue;
		}
		if(n==0)
			printf("%I64d\n",(m+1)/2);
		else 
			printf("%I64d\n",max(2LL,(m-n)/2+1));
	}	
	return 0;
}
