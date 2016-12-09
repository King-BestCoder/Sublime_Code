#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=10005;
int num[maxn];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&num[i]);
	sort(num,num+n);
	printf("%d",num[0]);
	int t=num[0];
	for(int i=1;i<n;i++){
		if(t==num[i])
			continue;
		else{
			printf(" %d",num[i]);
			t=num[i];
		}
	}
	printf("\n");
	return 0;
}
