// 实验4：中国邮递员问题
// 输入：中国144个城市数据
// 输出：最短路径序列及路径长度
// 4.1 采用局部搜索算法实现

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=144;
const double E=2.718281828459;
double len=0,temperature=1,recent_len[2]={1e12,1e12};
struct Point{
    int num,x,y;
    double dist(Point &r){
        return sqrt((x-r.x)*(x-r.x)+(y-r.y)*(y-r.y));
    }
}point[144];

inline double rand0_1(){
    return 1.0*rand()/RAND_MAX;
}

double get_receive_rate(){
    int receive=0,times=300,t=300;
    while(t--){
        int pos1=rand()%MAXN,pos2=rand()%MAXN;
        if(pos1>pos2) swap(pos1,pos2);
        if(pos1==pos2 || (pos1==0 && pos2==MAXN-1)){
            ++receive;
            continue;
        }
        double offset=point[pos1].dist(point[(pos2+1)%MAXN])+point[pos2].dist(point[(pos1-1+MAXN)%MAXN])-point[pos1].dist(point[(pos1-1+MAXN)%MAXN])-point[pos2].dist(point[(pos2+1)%MAXN]);
        if(offset<=0 || pow(E,-offset*1.0/temperature)>=rand0_1())
            ++receive;
    }
    return 1.0*receive/times;
}


// 生成一个随机解作为初始解,并计算一个合适的初始温度（使得接受概率大于0.9）
void init(){
    len=0;
    // 生成全排列
    for(int i=0;i<MAXN;++i){
        int pos=rand()%MAXN;
        swap(point[pos],point[i]);
    }
    for(int i=0;i<MAXN-1;++i)
        len+=point[i].dist(point[i+1]);
    len+=point[0].dist(point[MAXN-1]);
    while(get_receive_rate()<0.9) temperature*=1.05;
}


void readData(){
    freopen("Cities(144).txt","r",stdin);
    for(int i=0;i<144;++i)
        scanf("%d%d%d",&point[i].num,&point[i].x,&point[i].y);
    double ans=0;
}

void anneal(){
    int times=1e4;
    while(temperature>0.001){
        times*=1.01;
        int t=times;
//      printf("temperature=%f\ttimes=%d\tlen=%f\n",temperature,t,len);
        while(t--){
            int pos1=rand()%MAXN,pos2=rand()%MAXN;
            if(pos1>pos2) swap(pos1,pos2);
            if(pos1==pos2 || (pos1==0 && pos2==MAXN-1)) continue;
            double offset=point[pos1].dist(point[(pos2+1)%MAXN])+point[pos2].dist(point[(pos1-1+MAXN)%MAXN])-point[pos1].dist(point[(pos1-1+MAXN)%MAXN])-point[pos2].dist(point[(pos2+1)%MAXN]);
            if(offset<=0 || pow(E,-offset*1.0/temperature)>=rand0_1()){
                len+=offset;
                while(pos1<pos2) swap(point[pos1++],point[pos2--]);
            }
        }
        if(len==recent_len[0] && len==recent_len[1]) break;
        temperature*=0.98;
        recent_len[0]=recent_len[1];
        recent_len[1]=len;
    }
}
void debug(){
}

int main(){
    srand((unsigned int)time(NULL));
    readData();
    init();
    debug();
    anneal();
    printf("len:\n%f\npath:\n",len);
    for(int i=0;i<MAXN;++i)
        printf("%d ",point[i].num);
    printf("\n");
    return 0;
}
