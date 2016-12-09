#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int num[3];
int main(int argc, char const *argv[])
{
	for(int i=0;i<3;i++)
		scanf("%d",&num[i]);
	sort(num,num+3);
	int sum=num[2]-num[1]+num[1]-num[0];
	printf("%d\n",sum);
	return 0;
}
