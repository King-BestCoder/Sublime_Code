#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <vector>
#define GRAPENUM 55//葡萄总数
#define TYPENUM 2//目标类个数
#define DIVITIME 10000//划分次数阈值，超过该值后自动停止
#define MAX_INT 2147483647
#define DISTTHRE 0.0000001//类差别阈值，小于该值认为前后两次划分没有很大改变，不再继续划分
#define ATTRNUM 6
#define PRECISION 10000//测试机器随机数范围为0~32757，对第一个第三个和第四个属性需要特殊处理
using namespace std;
struct MyUnit
{
	int type;               //类的标号
	double centr[ATTRNUM];  //类的中心数组
	double total_dist;      //类中各个元素到中心的总距离
	int memb[GRAPENUM];     //1表示出现在该集合中，0表示不出现在该集合中
	int memcnt;             //类中元素总个数
	void init()             //类的初始化
	{
		memset(memb, 0, sizeof(memb));
		memset(centr, 0, sizeof(centr));
		total_dist = MAX_INT;
		memcnt = 0;
	}
};
class Grape
{
public:
	double Attr[ATTRNUM];
	void setGrapeAttr(double attr[])
	{
		for (int i = 0; i < ATTRNUM; i++)
			Attr[i] = attr[i];
	}
	void getGrapeAttr()
	{
		cout << ID << " ";
		for (int i = 0; i < ATTRNUM; i++)
			cout << Attr[i] << " ";
		cout << Type << endl;
	}
	int getID()
	{
		return ID;
	}
	void setID(int id)
	{
		ID = id;
	}
	int getType()
	{
		return Type;
	}
	void setType(int t)
	{
		Type = t;
	}
private:
	int ID;
	int Type;//初始为-1，红葡萄为0，白葡萄为1
};
Grape G[GRAPENUM];//读入的葡萄
MyUnit U[TYPENUM];//划分的两类
double MaxAttr[ATTRNUM];//各个属性的最大值
double MinAttr[ATTRNUM];//各个属性的最小值
double Diff[ATTRNUM];//Diff[i] = MaxAttr[i] - MinAttr[i]
void calc_dist(int type)
{
	U[type].total_dist = 0;
	for (int i = 0; i<GRAPENUM; i++)
	if (U[type].memb[i] == 1)
	for (int j = 0; j<ATTRNUM; j++)
		U[type].total_dist += fabs(G[i].Attr[j] - U[type].centr[j]);
}
void reset_centr(int type)
{
	if (U[type].memcnt == 0)
		return;
	memset(U[type].centr, 0, sizeof(U[type].centr));
	double dist[ATTRNUM];
	memset(dist, 0, sizeof(dist));
	for (int i = 0; i < GRAPENUM; i++)
	{
		if (U[type].memb[i] == 1)
		{
			for (int j = 0; j < ATTRNUM; j++)
				dist[j] += G[i].Attr[j];
		}
	}
	for (int i = 0; i<ATTRNUM; i++)
		U[type].centr[i] = dist[i] / U[type].memcnt;
	calc_dist(type);
}
void random_centr(int type)
{
	int i = 0;
	U[type].centr[i] = double(rand() % ((int)(Diff[i] * 100) + 1)) / 100 + MinAttr[i];
	for (i = 1; i < ATTRNUM; i++)
	{
		if (i == 2 || i == 3)
			U[type].centr[i] = double(rand() % ((int)(Diff[i] * 1000) + 1)) / 1000 + MinAttr[i];
		else
			U[type].centr[i] = double(rand() % ((int)(Diff[i] * PRECISION) + 1)) / PRECISION + MinAttr[i];
	}

}
void Normalize()
{
	for (int i = 0; i<GRAPENUM; i++)
		for (int j = 0; j<ATTRNUM; j++)
			G[i].Attr[j] = (G[i].Attr[j] - MinAttr[j]) / Diff[j];
}
double CosDist(int gpos, int utype)
{
	double nume = 0, deno = 0, gdeno = 0, udeno = 0;
	for (int i = 0; i < ATTRNUM; i++)
	{
		nume += G[gpos].Attr[i] * U[utype].centr[i];
		gdeno += pow(G[gpos].Attr[i], 2);
		udeno += pow(U[utype].centr[i], 2);
	}
	deno = sqrt(gdeno) * sqrt(udeno);
	return nume / deno;
}
void ChooseUnit(int pos)
{
	double dist[TYPENUM], dist_min = -1;
	int min_dist_unit = 0;
	memset(dist, 0, sizeof(dist));
	for (int i = 0; i < TYPENUM; i++)
	{
		U[i].memb[pos] = 0;
		dist[i] = CosDist(pos, i);
		if (dist_min < dist[i])//越接近1越相似
		{
			dist_min = dist[i];
			min_dist_unit = i;
		}
	}
	U[min_dist_unit].memb[pos] = 1;
	U[min_dist_unit].memcnt += 1;
	U[min_dist_unit].total_dist += dist[min_dist_unit];
	G[pos].setType(min_dist_unit);
}
void Kmeans()
{
	int DiviTime = DIVITIME;
	double Distin = MAX_INT;
	for (int i = 0; i < TYPENUM; i++)
		random_centr(i);
	while (DiviTime-- && Distin > DISTTHRE)
	{
		Distin = 0;//两次划分之间的差
		double LastDist[TYPENUM];
		for (int i = 0; i < TYPENUM; i++)
		{
			U[i].memcnt = 0;
			LastDist[i] = U[i].total_dist;
			U[i].total_dist = 0;
		}
		for (int i = 0; i<GRAPENUM; i++)
			ChooseUnit(i);
		for (int i = 0; i < TYPENUM; i++)
		{
			reset_centr(i);
			Distin += fabs(LastDist[i] - U[i].total_dist);
		}
	}
}
int main()
{
	srand((unsigned)time(NULL));
	freopen("Data.txt", "r", stdin);
	memset(MaxAttr, 0, sizeof(MaxAttr));
	memset(MinAttr, 0x7F, sizeof(MinAttr));
	for (int i = 0; i < GRAPENUM; i++)
	{
		int id;
		double tmp[ATTRNUM];
		cin >> id;
		for (int j = 0; j<ATTRNUM; j++)
		{
			cin >> tmp[j];
			MaxAttr[j] = max(MaxAttr[j], tmp[j]);
			MinAttr[j] = min(MinAttr[j], tmp[j]);
		}
		G[i].setGrapeAttr(tmp);
		G[i].setID(id);
		G[i].setType(-1);
	}
	for (int i = 0; i<TYPENUM; i++)
	{
		U[i].type = i;
		U[i].init();
	}
	for (int i = 0; i<ATTRNUM; i++)
		Diff[i] = MaxAttr[i] - MinAttr[i];
	Normalize();
	Kmeans();
	//freopen("K_meansResult(cos).txt","w",stdout);
	for (int i = 0; i < GRAPENUM; i++)
		G[i].getGrapeAttr();
/*********************ClusterPaint*************************/
//	freopen("CP.txt","w",stdout);
	double maxdist1=0,maxdist2=0;
	double mindist1=0x7FFFFFFF,mindist2=0x7FFFFFFF;
	double dist1[GRAPENUM],dist2[GRAPENUM];
	memset(dist1,0,sizeof(dist1));
	memset(dist2,0,sizeof(dist2));
	for(int i = 0; i < GRAPENUM; i++)
	{
		dist1[i]=CosDist(i,0);
		dist2[i]=CosDist(i,1);
		if(dist1[i]>maxdist1)
			maxdist1=dist1[i];
		if(dist2[i]>maxdist2)
			maxdist2=dist2[i];
		if(dist1[i]<mindist1)
			mindist1=dist1[i];
		if(dist2[i]<mindist2)
			mindist2=dist2[i];
	}
	cout<<maxdist1<<" "<<maxdist2<<endl;
	cout<<mindist1<<" "<<mindist2<<endl;
	for (int i = 0; i < GRAPENUM; ++i)
		cout<<G[i].getType()<<" "<<dist1[i]<<" "<<dist2[i]<<endl;
	fclose(stdin);
//	fclose(stdout);
	return 0;
}
