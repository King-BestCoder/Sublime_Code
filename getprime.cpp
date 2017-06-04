#include <stdio.h>
using namespace std;

const int maxn=5e7+6;
typedef long long LL;

int num[maxn];
bool su[maxn];
int cnt=0;

bool isPrime(int n){
	if(n==2) return true;
	if(n%2==0) return false;
	for(int i=3;i*i<=n;i++){
		if(n%i==0)
			return false;
	}
	return true;
}

void prime(){
	for(int i=0;i<maxn;i++)
		su[i]=1;
	su[0]=su[1]=0;
	for(int i=2;i<maxn;i++){
		if(su[i]){
			num[cnt++]=i;
			for(int j=i*2;j<maxn;j+=i){
				su[j]=0;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int t=0,n;
	prime();
	printf("%d\n",cnt);
	freopen("prime300.txt","w",stdout);
	for(int i=0;i<cnt;i++){
		printf("%10d,",num[i]);
	}
	while(~scanf("%d",&n)&&n){
		printf("Case %d: %d\n",++t,num[n-1]);
	}
	return 0;
}