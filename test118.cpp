//A�����Ƚ��Ӽ�Ԫ�ط��࣬��Ϊ1��Ԫ�ص��Ӽ���2��Ԫ�ص��Ӽ���3��Ԫ�ص��Ӽ�...
//Ȼ��������dfs������������������ɡ�
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[10],n,k,pr[10];
void dfs(int pos,int num,int cnt) //pos��ʾ��a�����е�λ�ã�num��ʾ��Ҫ���ٸ�Ԫ�ز����㣬cnt��ʾ���������������±�
{
	if(num<=1)  //��Ϊ��dfs֮ǰ�����Ѿ�ȡ��һ��Ԫ���ˣ����Դ�ʱ�ж�num<=1
	{
		for(int p=0;p<cnt;p++)
			p==0?printf("%d",pr[p]):printf(" %d",pr[p]);
		printf("\n");
		return ;
	}
	for(int j=pos+1;j<n;j++)  //˵������Ҫ�Ӽ��л���Ҫ���Ԫ��
	{
		pr[cnt]=a[j];    //��Ԫ�ط������������������
		dfs(j,num-1,cnt+1); //��������dfs
	}
	return ;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		printf("\n");
		for(k=1;k<=n;k++)  //�����Ӽ�Ԫ�ظ��������
		{
			memset(pr,0,sizeof(pr));  //�������������������
			for(int j=0;j<n-k+1;j++)
			{
				pr[0]=a[j];
				dfs(j,k,1);  //dfs
			}
		}
	}
	return 0;
}
//������Ȼ�ǵݹ��д���������漰����������Ҫ�������ݣ��������������dfs����
//���Դ�Ҿ����������뿴����Ȼ���Լ���һ������Ϥdfs�������������ѧϰ��