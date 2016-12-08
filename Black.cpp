#include <bits/stdc++.h>
using namespace std;
int lowbit(int x) {
    return x & (-x);
}
int main(int argc, char const *argv[])
{
	int n;
	while(~scanf("%d",&n)){
		printf("%d\n",lowbit(n));
	}
	return 0;
}