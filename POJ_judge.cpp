#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int Max = 30; 
int kase;
int p,q;
int vis[Max][Max]; //标记数组 
//方向数组，按照字典序就好了 
 int dir[8][2] = {{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};//8个方向 
int path[Max*Max][2]; //用于记录DFS走过的路径
int flag; 

void dfs(int x, int y, int step)
{
	
	if(step == p*q) //走完了p*q格 
	{
		cout<<"Scenario #"<<++kase<<":"<<endl;
		for(int i=0; i<p*q; i++)
		{
			printf("%c%d",path[i][1]+'A',path[i][0]+1); //注意我们记录的路径下标都是从0开始的,按我这里的设计，先输出y值 
		}
		cout<<endl<<endl;
		flag = 1;
		return;
	}
		
	
	for(int d=0; d<8; d++)
	{
		int nx,ny; //只能做局部变量 
		nx = x + dir[d][0];
		ny = y + dir[d][1];
		if(!vis[nx][ny] && nx >= 0 && nx < p && ny >= 0 && ny < q) 
		{
			vis[nx][ny] = 1;
			path[step][0] = nx;
			path[step][1] = ny;
			dfs(nx, ny, step+1);
			vis[nx][ny] = 0; //取消标记
			if(flag)
				return; 
		}
	}
}

			
int main()
{
	int t;
	while(scanf("%d",&t) != EOF)
	{
		kase = 0;
		printf("sdfa\n");
		while(t--)
		{
			flag = 0;
			memset(vis, 0, sizeof(vis));
			scanf("%d %d",&p,&q);
			path[0][0] = 0;
			path[0][1] = 0;
			vis[0][0] = 1; 
			dfs(0,0,1);
			
			if(!flag)
			{
				cout<<"Scenario #"<<++kase<<":"<<endl;
				cout<<"impossible"<<endl<<endl;
			}
		}
	}
	return 0;
}