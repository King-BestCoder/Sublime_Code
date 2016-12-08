#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
const int maxn=505;
char s[]="abcdefghijklmnopqrstuvwxyz";
int main(int argc, char const *argv[])
{
	char t[maxn];
	scanf("%s",t);
	int ans=0;
	int now=0;
	for(int i=0;i<strlen(t);i++){
		int temp=t[i]-'a';
		ans+=min(abs(now-temp),26-abs(now-temp));
		now=temp;
	}
	printf("%d\n",ans);
	return 0;
}
