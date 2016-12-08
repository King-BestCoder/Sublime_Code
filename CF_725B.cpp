#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
const int maxn=200006;
int n;
int num[maxn];

int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&num[i]);
	int flag2=0;
	int sum2=0;
	int t;
	// int a,b;
	for(int i=0;i<n;i++){
		t=num[i];
		if(t==0&&flag2==1){
			break;
		}
		if(flag2==1){
			t-=sum2;
			flag2=0;
		}
		t=t%2;
		// printf("%d\n",t);
		if(t){
			flag2=1;
			sum2=t;
		}
	}
	if(flag2)
		printf("NO\n");
	else 
		printf("YES\n");
	return 0;
}