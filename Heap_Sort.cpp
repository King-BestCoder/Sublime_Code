#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

void Sort(int *num,int left,int right)
{
	
}
int main(int argc, char const *argv[])
{
	freopen("data1m.txt","r",stdin);
	freopen("Data_out_1m.txt","w",stdout);
	int n;
	scanf("%d",&n);
	int *num=new int[n];
	for(int i=0;i<n;i++)
		scanf("%d",&num[i]);
	Sort(num,0,n-1);
	for(int i=0;i<n-1;i++)
		printf("%d ",num[i]);
	printf("%d\n",num[n-1]);
	return 0;
}
