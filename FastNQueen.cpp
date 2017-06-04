#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef long long LL;
LL *queen;    // 解
LL N;               // 皇后个数
LL NumCollisions; // 当前解的冲突总数
// 正对角线, 同一条对角线上 i - queen[i] 为常数，下标范围 -(N-1) ~ (N-1),映射到 0 ~ (2N-2) [通过 + (N-1)]
LL *pPosDiagonal;
// 负对角线, 同一条对角线上 i + queen[i] 为常数，下标范围 0 ~ (2N-2)
LL *pNegDiagonal;
//对结果进行打印
void print(){
    printf("解决方案如下:\n");
    for(LL i=0;i<N;i++)
        printf("(%I64d %I64d)\n",queen[i],i);
}
//本函数交换两个单元

inline void Swap(LL &a,LL &b){
    LL temp;
    temp=a;
    a=b;
    b=temp;
}
//随机数产生
LL Random(LL a,LL b){
    return rand()%(b-a+1)+a;
}
//对两个皇后进行交换，并对他们的对角线进行更新
void Swap_Queens(LL i,LL j){
    pNegDiagonal[i+queen[i]]--;
    pPosDiagonal[i-queen[i]+N-1]--;
    pNegDiagonal[j+queen[j]]--;
    pPosDiagonal[j-queen[j]+N-1]--;

    Swap(queen[i],queen[j]);

    pNegDiagonal[i+queen[i]]++;
    pPosDiagonal[i-queen[i]+N-1]++;
    pNegDiagonal[j+queen[j]]++;
    pPosDiagonal[j-queen[j]+N-1]++;
}
//计算左半边的皇后冲突数
LL Partial_Collisions(LL t){
    LL ans=0;
    LL target1=t-queen[t]+N-1,target2=t+queen[t];
    for(LL i=0;i<t;i++){
        if(i-queen[i]+N-1==target1||i+queen[i]==target2)
            ans++;
    }
    return ans;
}
//计算所产生的总的冲突数
LL Total_Collisions(){
    LL ans=0;
    LL cnt=2*N-1;
    for(LL i=0;i<cnt;i++){
        ans+=pNegDiagonal[i]>1?pNegDiagonal[i]-1:0;
        ans+=pPosDiagonal[i]>1?pPosDiagonal[i]-1:0;
    }
    return ans;
}

LL Initial_Search(){
    memset(queen,0,sizeof(LL)*(N));
    memset(pNegDiagonal,0,sizeof(LL)*(2*N-1));
    memset(pPosDiagonal,0,sizeof(LL)*(2*N-1));
    LL i,j=1,m;
    for(i=0;i<N;i++){//初始化
        queen[i]=i;
        pNegDiagonal[i+queen[i]]++;
        pPosDiagonal[i-queen[i]+N-1]++;
    }
    LL cnt=(LL)(3.08*N);
    for(i=1;i<=cnt;i++){
        m=Random(j,N-1);
        if(m==j) continue;
        Swap_Queens(j,m);
        if(Partial_Collisions(j)==0){
            j++;
        }
        else{
            Swap_Queens(j,m);
        }
    }
    for(i=j;i<N;i++){
        m=Random(i,N-1);
        Swap_Queens(i,m);
    }
    return j;
}

//本函数计算冲突的个数
LL CountCollisions()
{
    LL max = 2 * N - 1;

    NumCollisions = 0;

    for (LL i = 0; i < max; i++)
    {
        NumCollisions += pPosDiagonal[i] > 1 ? pPosDiagonal[i] - 1: 0;
        NumCollisions += pNegDiagonal[i] > 1 ? pNegDiagonal[i] - 1: 0;
    }

    return NumCollisions;
}

//本函数根据解，设置两条对角线对应的皇后数的数组

void SetDiagonals()
{
    // 首先给两个对角线的数组赋初始值 0
    memset(pPosDiagonal,0,sizeof(LL)*(2*N-1));
    memset(pNegDiagonal,0,sizeof(LL)*(2*N-1));
    for (LL i = 0; i < N; i++)
    {
        pPosDiagonal[i - queen[i] + N -1]++;
        pNegDiagonal[i + queen[i]]++;
    }
}

//本函数检查一下：如果交换 queen[i], queen[j], 冲突是否会减少？
LL SwapEvaluate(LL i, LL j)
{
    LL ret = 0;
    // 两个解在同一个条正对角线上
    if (i - queen[i] == j - queen[j])
    {
        ret = (pPosDiagonal[i - queen[i] + N -1] > 2 ? 2: 1) + (pNegDiagonal[i + queen[i]] > 1 ? 1 : 0) +
               (pNegDiagonal[j + queen[j]] > 1 ? 1 : 0) -
               (pNegDiagonal[i + queen[j]] > 0 ? 2 : 1) -
               (pPosDiagonal[i - queen[j] + N -1] > 0 ? 1: 0) - (pPosDiagonal[j - queen[i] + N -1] > 0 ? 1: 0);

        return ret;
    }
    // 两个解在同一条负对角线上
    if (i + queen[i] == j + queen[j])
    {
        ret = (pNegDiagonal[i + queen[i]] > 2 ? 2: 1) + (pPosDiagonal[i - queen[i] + N -1] > 1 ? 1 : 0) +
              (pPosDiagonal[j - queen[j] + N -1] > 1 ? 1 : 0) -
              (pPosDiagonal[i - queen[j] + N -1] > 0 ? 2 : 1) -
              (pNegDiagonal[i + queen[j]] > 0 ? 1: 0) - (pNegDiagonal[j + queen[i]] > 0 ? 1: 0);

        return ret;
    }
    // 一般情况，即两个解在不同的对角线上
    ret = (pPosDiagonal[i - queen[i] + N -1] > 1 ? 1 : 0) + (pNegDiagonal[i + queen[i]] > 1 ? 1 : 0) +
          (pPosDiagonal[j - queen[j] + N -1] > 1 ? 1 : 0) + (pNegDiagonal[j + queen[j]] > 1 ? 1 : 0) -
          (pPosDiagonal[i - queen[j] + N -1] > 0 ? 1 : 0) - (pNegDiagonal[i + queen[j]] > 0 ? 1 : 0) -
          (pPosDiagonal[j - queen[i] + N -1] > 0 ? 1 : 0) - (pNegDiagonal[j + queen[i]] > 0 ? 1 : 0);

    return ret; // ret > 0 表明冲突减少，ret < 0 表示冲突增加
}

void SwapQueens(LL i, LL j, LL gain)
{
    pPosDiagonal[i - queen[i] + N -1] --;
    pNegDiagonal[i + queen[i]] --;
    pPosDiagonal[j - queen[j] + N -1] --;
    pNegDiagonal[j + queen[j]] --;

    Swap(queen[i], queen[j]);

    pPosDiagonal[i - queen[i] + N -1] ++;
    pNegDiagonal[i + queen[i]] ++;
    pPosDiagonal[j - queen[j] + N -1] ++;
    pNegDiagonal[j + queen[j]] ++;

    NumCollisions -= gain;
}

int main(int argc, char* argv[])
{
    clock_t start, finish;
    while(~scanf("%I64d",&N)){
        if(N==2||N==3){
            printf("No solution!\n");
        }
        else{
            start = clock();
            // 分配解的空间
            queen = new LL[N]; // 使用下标 0 - (N-1)
            // 分配正对角线上的数组空间，并赋初始值为0
            pPosDiagonal = new LL[2*N-1];
            // 分配负对角线上的数组空间，并赋初始值为0
            pNegDiagonal = new LL[2*N-1];
            do {
                Initial_Search();
                CountCollisions();
                bool flag = true;
                LL gain;
                while (flag)
                {
                    flag = false;
                    for (LL i = 0; i < N; i++){
                        for (LL j = i; j < N; j++){
                            // 若queen[i] 或 queen[j]对应的对角线有冲突
                            if (pPosDiagonal[i - queen[i] + N -1] > 1 || pNegDiagonal[i + queen[i]] > 1 ||
                                pPosDiagonal[j - queen[j] + N -1] > 1 || pNegDiagonal[j + queen[j]] > 1)
                            {
                                // 判断一下，如果交换queen[i]和queen[j]，是否可以降低冲突总数
                                gain = SwapEvaluate(i, j);
                                // 若交换会带来冲突的减少，则值得交换
                                if ( gain > 0)
                                {
                                    flag = true; // 标记，证明本轮迭代做了交换
                                    SwapQueens(i, j, gain); // 交换 2个皇后，并更新冲突总数
                                }
                            }
                        }
                    }
                }
            }while(NumCollisions > 0);
            finish = clock();
            double period = (double) (finish-start)/CLOCKS_PER_SEC;
            printf("%I64d Queens cost time:%f seconds\n",N, period);
        }
    }
    return 0;
}
