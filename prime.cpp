#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
// #define test TEST
using namespace std;
const int maxn=50000001;
bool su[maxn];
int num[4000001],cnt;

//欧式筛法
void prime () {
	cnt=0;
	memset(su,1,sizeof(su));
    for( int i = 2 ; i <= maxn; ++i ){
        if( su[ i ] )
            num[ cnt++ ]=i; //将这句话放在下面的循环前以保证cnt和num值的完整性
        for(int j=0;j<cnt;++j){
            if( i*num[ j ] > maxn)
                break; //当过大了就跳出
            su[ i * num[ j ] ] = 0;
            if( i % num[ j ] == 0 ) break;
        }
    }
} 

void fastprime(){
	cnt=0;
	memset(su,1,sizeof(su));
	num[cnt++]=2;
	for(int i=3;i<maxn;i+=2){
		if(su[i]) 
			num[cnt++]=i;
		
		for(int j=0;j<cnt;j++){
			if(i*num[j]>maxn) break;
			su[i*num[j]]=0;
			if(i%num[j]==0) break;
		}
	}
}

int main(int argc, char const *argv[])
{
	#ifdef test
	freopen("test.txt","r",stdin); 
	#endif
	prime();
	int n,t=1;
	while(~scanf("%d",&n)&&n){
		printf("Case %d: %d\n",t++,num[n-1]);
	}
	return 0;
}