#include <stdio.h>
#include <string.h>
#define maxn 1100
int num[maxn];
int main(int argc, char const *argv[])
{
	int n,i,j,t,index;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);
	for(i=0;i<n;i++){
		index=i;
		for(j=i+1;j<n;j++){
			if(num[index]>num[j])
				index=j;
		}
		if(index!=i){
			t=num[index],num[index]=num[i],num[i]=t;
		}
	}
	for(i=0;i<n-1;i++)
		printf("%d ",num[i]);
	printf("%d\n",num[i]);
	return 0;
}