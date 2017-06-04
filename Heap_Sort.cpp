#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;  

void heapRebuild(int arr[],int root,int size)  
{  
    int child=2*root+1;  
    if(child<=size-1)  
    {  
        int rightChild=child+1;  
        if(rightChild<=size-1)  
            if(arr[child]<arr[rightChild])  
                child=rightChild;  
        if(arr[root]<arr[child])  
        {  
            int temp=arr[child];  
            arr[child]=arr[root];  
            arr[root]=temp;  
            heapRebuild(arr,child,size);  
        }  
    }  
}  
void Sort(int arr[],int size)  
{  
    for(int i=size-1;i>=0;i--)  
    {  
        heapRebuild(arr,i,size);  
    }  
    int last=size-1;  
    for(int i=1;i<=size;i++,last--)  
    {  
        int temp=arr[0];  
        arr[0]=arr[last];  
        arr[last]=temp;  
        heapRebuild(arr,0,last);  
          
    }  
  
}  
  
int main(int argc, char const *argv[])
{
	// freopen("data1m.txt","r",stdin);
	// freopen("Data_out_1m.txt","w",stdout);
	int n;
	scanf("%d",&n);
	int *num=new int[n];
	for(int i=0;i<n;i++)
		scanf("%d",&num[i]);
	Sort(num,n);
	for(int i=0;i<n-1;i++)
		printf("%d ",num[i]);
	printf("%d\n",num[n-1]);
	return 0;
}
