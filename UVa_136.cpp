#include <bits/stdc++.h>
using namespace std;
int num[]={2,3,5};
typedef long long LL;
int main(int argc, char const *argv[])
{
	priority_queue<LL,vector<LL>,greater<LL>>que;
	que.push(1);
	map<LL,LL>cnt;
	cnt[1]++;
	for(LL i=1;;i++){
		LL t=que.top();
		que.pop();
		if(i==1500){
			printf("The 1500'th ugly number is %lld.\n",t);
			return 0;
		}
		for(LL j=0;j<3;j++){
			LL temp=t*num[j];
			if(!cnt[temp]){
				que.push(temp);
				cnt[temp]++;
			}
		}
	}
	return 0;
}