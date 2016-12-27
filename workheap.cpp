#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int maxn=1005;
typedef struct Node{
	int data;
	struct Node *left,*right;
	Node(int t){
		data=t;
		left=right=NULL;
	}
}node;
void siftdown(int *a,int i,int n){
	int j,t=a[i];
	while((j=i<<1|1)<n){
		if(j<n-1&&a[j]<a[j+1]) j++;
		if(t<a[j]){
			a[i]=a[j];
			i=j;
		}
		else break;
	}
	a[i]=t;
}
void heap_sort(int *a,int n){
	int i,t;
	for(i=(n-2)/2;i>=0;i--)
		siftdown(a,i,n);
	for(i=n-1;i>0;i--){
		t=a[0];
		a[0]=a[i];
		a[i]=t;
		siftdown(a,0,i);
	}
}
int main(int argc, char const *argv[])
{
	int a[maxn];
	for(int i=0;i<15;i++)
		a[i]=rand();
	heap_sort(a,15);
	for(int i=0;i<15;i++)
		printf("%d\n",a[i]);
	return 0;
}