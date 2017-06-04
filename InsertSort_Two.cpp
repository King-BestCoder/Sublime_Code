#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int mid_find(int *num,int left,int right,int t){
	while(left<=right){
		int mid=(right-left)/2+left;
		if(num[mid]==t){
			return mid;
		}
		else if(num[mid]>t){
			right=mid-1;
		}
		else{
			left=mid+1;
		}
	}
	return left;
}

void insert_sort(int *num,int n){
	for(int i=1;i<n;i++){
		int temp=mid_find(num,0,i-1,num[i]);
		// printf("%d\n",temp);
		if(temp<i){
			int v=num[i];
			for(int j=i;j>temp;j--)
				num[j]=num[j-1];
			num[temp]=v;
		}
	}
}

int main(int argc, char const *argv[])
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	int *num=new int[n];
	for(int i=0;i<n;i++)
		scanf("%d",&num[i]);
	insert_sort(num,n);
	for(int i=0;i<n;i++){
		printf("%d%c",num[i],i==n-1?'\n':' ');
	}
	return 0;
}