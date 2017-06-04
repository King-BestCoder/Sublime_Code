#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
	int x,y,z;
}node;
node num[4];
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while(T--){
		for(int i=0;i<4;i++){
			scanf("%d %d %d",&num[i].x,&num[i].y,&num[i].z);
		}
		node vec[3];
		for(int i=1;i<=3;i++){
			vec[i-1].x=num[i].x-num[0].x;
			vec[i-1].y=num[i].y-num[0].y;
			vec[i-1].z=num[i].z-num[0].z;
		}
		int ans=vec[0].x*(vec[1].y*vec[2].z-vec[2].y*vec[1].z)
		        -vec[0].y*(vec[1].x*vec[2].z-vec[2].x*vec[1].z)
		        +vec[0].z*(vec[1].x*vec[2].y-vec[2].x*vec[1].y);
		if(ans==0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}