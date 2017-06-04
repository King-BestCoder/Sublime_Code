#include <bits/stdc++.h>
using namespace std;
const int maxn=10;

int main(int argc, char const *argv[])
{
	srand(time(0));
	for(int i=0;i<maxn;i++)
		printf("%d%c",rand(),i==maxn-1?'\n':' ');
	return 0;
}