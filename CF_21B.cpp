#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int a1,a2,b1,b2,c1,c2;
	while(~scanf("%d %d %d %d %d %d",&a1,&b1,&c1,&a2,&b2,&c2)){
		// int flag=0;
		int sum=0;
		if((a1==0&&b1==0&&c1==0)&&(a2==0&&b2==0&&c2==0))
			sum=-1;
		else if((a1==0&&b1==0&&c1!=0)||(a2==0&&b2==0&&c2!=0))
			sum=0;
		else if(b1==0&&b2==0&&(a1*c2==a2*c1))
			sum=-1;
		else if(a1==0&&a2==0&&(b1*c2==b2*c1))
			sum=-1;
		else if(a1*b2==a2*b1&&a1*c2==a2*c1&&b1*c2==b2*c1)
			sum=-1;
		else{
			if((a1==a2&&b1==b2&&c1==c2)||(a1*b2==a2*b1&&c1==0&&c2==0))
				sum=-1;
			else if(a1*b2==a2*b1) 
				sum=0;
			else 
				sum=1;
		}
		printf("%d\n",sum);
	}
	return 0;
}
