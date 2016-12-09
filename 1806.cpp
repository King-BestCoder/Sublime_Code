#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int pivot(int *num,int left,int right){
	int x=num[left];
	int p=left;
	for(int  j=left+1;j<=right;j++){
		if(num[j]<x){
			p++;
			swap(num[p],num[j]);		
		}
	}
	swap(num[p],num[left]);
	return p;
}

void Sort(int *num,int left,int right){
	if (left<right)
	{
		int mid=pivot(num,left,right);
		Sort(num,left,mid-1);
		Sort(num,mid+1,right);
	}
	return ;
}

int main()
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