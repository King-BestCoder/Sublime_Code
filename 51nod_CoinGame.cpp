#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
typedef long long LL;

int main(int argc, char const *argv[])
{
	string s,str;
	getline(cin,s);
	istringstream sin(s);
	int sum=0;
	sin>>str;
	for(int i=0;i<str.length();i++)
		sum=sum*10+(str[i]-'0');
	while(sin>>str);
	// cout<<str<<endl;
	if(str=="month"){
		if(sum<=29)
			printf("12\n");
		if(sum==30)
			printf("11\n");
		if(sum==31)
			printf("7\n");
	}
	else if(str=="week"){
		// printf("yes\n");
		if(sum==5||sum==6)
			printf("53\n");
		else
			printf("52\n");
	}
	return 0;
}