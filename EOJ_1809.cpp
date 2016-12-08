#include <stdio.h>
#include <string.h>
#define maxn 1000001
int num[maxn];
int n,k;

int pivot(int left,int right){
	int x=num[left];
	int t,j,p=left;
	for(j=left+1;j<=right;j++){
		if(num[j]<x){
			p++;
			t=num[p],num[p]=num[j],num[j]=t;
		}
	}
	t=num[p],num[p]=num[left],num[left]=t;
	return p;
}

void Sort(int left,int right){
	if(left<right){
		int mid=pivot(left,right);
		Sort(left,mid-1);
		Sort(mid+1,right);
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d %d",&n,&k);
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);
	Sort(0,n-1);
	for(i=0;i<k-1;i++)
		printf("%d ",num[i]);
	printf("%d\n",num[i]);
	return 0;
}