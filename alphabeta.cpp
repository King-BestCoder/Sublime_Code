#include <time.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef int Map[15][15];

const int MIN = -1000000;
const int MAX = 1000000;
const int MAX_CHILDS = 10;
const int SEARCH_DEPTH = 3;
const int dir[4][2] = {{0,  1}, {-1, 0}, {0, -1}, {1,  0}};
const int level_score[18] = {0, 10,   50,   50,   100,    100,    200,   500, 1000, 1000, 2000,    2000,      5000 ,     5000,     5000,   10000, 10000, 80000};
                            // 活一，冲三，活二，多活二，双跳三，双死三，活三，冲四，跳4，双活三，跳四+活三，冲四+活三，冲四+跳四，双跳冲四，双冲4，活4，  成5
const double p_accept = 0.3;    // 在评估函数值相等时接受新的解的概率

struct TREE
{
    vector<TREE*> childs;   //记录子女节点
    TREE* father;           //记录父节点
    int depth;              //记录层次深度
    int value;              //记录当前计算的值
    Map map;                //这一步的棋形
    int first;              //记录当前节点首选的下一步的节点的名字
    int firstPoint[2];      //下一步走的坐标
    int point[2];           //处于这个节点时和上一步相比增加的走步
    bool cut;               //标记这个节点是否被剪枝
};

Map currentMap;             //记录当前的棋形,0表示还没有棋子，1表示人的棋子，2表示计算机的棋子
int whoseTurn;              //0表示到人走，1表示到计算机走
int win;                    //记录是不是已经分出胜负，0表示人赢了，1表示计算机赢了
int hand;                   //记录一共走了几手棋。
int cut;                    //记录一共剪了多少次枝

void initMap();
void playGame();
void drawMap(Map, int, int);
void addToMap(Map, int, int, int);
void computer_think();
void alpha_beta(TREE*);
void clear(TREE*);
void scanMap(TREE *&pTREE, int turn);

int POW(int s, int t);
int score_row(int i, int j, Map map);
int score_col(int i, int j, Map map);
int score_diag_45(int i, int j, Map map);
int score_diag_135(int i, int j, Map map);
int total_score(Map map, int turn);

int PriorityGet(int i, int j, int level, Map record);
int LinkSS4(int x,int y, Map map);
/*211110 or 211101 or 211011*/
/*210111 or 11110 or 11101 */
/* 11011 or 10111*/
int LinkSS3(int x,int y, Map map);
/*211100 or 211010 or 211001*/
/*210110 or 210101 or 21011*/
/*11100 or 10110 or 10011 */
/*10101*/
int LinkS5(int x,int y, Map map);   /*1011101*/
int LinkS4(int x,int y, Map map);   /*1010101*/
int LinkS3(int x,int y, Map map);   /*1010100*/
int LinkF5(int x,int y, Map map);   /*11111*/
int LinkF4(int x,int y, Map map);   /*11110*/
int LinkF3(int x,int y, Map map);   /*011100 or 010110*/
int LinkF2(int x,int y, Map map);   /*011000 or 010100 or 010010*/
int LinkF1(int x,int y, Map map);   /*1*/


//输出上一轮落子位置和棋形
void drawMap(Map map, char m_i, char m_j)
{
    cout << "这是第" << hand + 1 << "手棋" << endl;
    cout << endl;
    cout << "人的行棋位置：O\t计算机的行棋位置：X" << endl;
    if (m_i != '0' && m_j != '0')
        cout << "落子位置：(" << m_i << ',' << m_j << ')' << endl;
    cout << "   1  2  3  4  5  6  7  8  9  A  B  C  D  E  F" << endl;
    for (int i = 0; i < 15; i++)
    {
        if (i + 1 < 10)
            cout << i + 1 << "  ";
        else
            cout << (char)(i + 1 - 10 + 'A') << "  ";
        for (int j = 0; j < 15; j++)
        {
            switch (map[i][j])
            {
            case 0: cout << "." << "  "; break;
            case 1: cout << "O"  << "  "; break;
            case 2: cout << "X"  << "  "; break;
            }
        }
        cout << endl;
    }
    cout << endl;
}

//棋盘中加入一个棋子，加入成功，返回true，否则返回false
bool addToMap(Map &map, char m_i, char m_j, int whoseTurn)
{
    int i = m_i >= 'A' ? (int)(m_i - 'A' + 10) : m_i - '0';
    int j = m_j >= 'A' ? (int)(m_j - 'A' + 10) : m_j - '0';
    if ((i > 0 && i < 16 && j > 0 && j < 16) && map[i - 1][j - 1] == 0)
    {
        map[i - 1][j - 1] = whoseTurn + 1;
        return true;
    }
    else
        return false;
}

//初始化棋盘
void initMap()
{
    cout << "选择人先手（0），计算机先手（1）：";
    cin >> whoseTurn;
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            currentMap[i][j] = 0;
    if (whoseTurn == 1)
    {
        currentMap[7][7] = 2;
        whoseTurn = 0;
        drawMap(currentMap, '8', '8');
        hand++;
    }
    else
        drawMap(currentMap, '0', '0');
}

//整个程序的初始化
void init()
{
    srand((unsigned int)time(NULL));
    hand = 0;
    initMap();
    win = false;
}

//游戏的主过程
void playGame()
{
    while (win == 0)
    {
        if (whoseTurn == 0)
        {
            bool inputCorrect;
            char p_i; char p_j;
            do
            {
                cout << "请输入落子的坐标：(X,Y)" << endl;
                cout << "输入q退出游戏" << endl;
                cin >> p_i;
                if (p_i == 'q' || p_i == 'Q')
                {
                    cout << "退出游戏" << endl;
                    exit(0);
                }
                cin >> p_j;
                if (p_j == 'q' || p_j == 'Q')
                {
                    cout << "退出游戏" << endl;
                    exit(0);
                }

                inputCorrect = addToMap(currentMap, p_i, p_j, whoseTurn);
            }while (!inputCorrect);
            drawMap(currentMap, p_i, p_j);
            hand++;
            int pos_x, pos_y;
            pos_x = (('0' < p_i) && ('9' >= p_i)) ? p_i - 48 : p_i - 'A' + 10;
            pos_y = (('0' < p_j) && ('9' >= p_j)) ? p_j - 48 : p_j - 'A' + 10;
            if (LinkF5(pos_x - 1, pos_y - 1, currentMap))
            {
                win = 1;
                break;
            }
            whoseTurn = 1;
        }
        else
        {
            cout << "计算机在思考。。。" << endl;
            cut = 0;
            computer_think();
            cout << "cut = " << cut << endl;
            hand++;
            whoseTurn = 0;
        }
        if (hand > 100)
            win = 3;
    }
    switch (win)
    {
        case 1:cout << "人类赢了!" << endl; break;
        case 2:cout << "AI赢了!" << endl; break;
        case 3:cout << "百手和棋!" << endl; break;
    }
    char c;
    cin >> c;
}

void computer_think()
{
    TREE *thinkTREE = new TREE();
    thinkTREE->father = NULL;
    thinkTREE->depth = 0;
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            thinkTREE->map[i][j] = currentMap[i][j];
    thinkTREE->childs.clear();
    thinkTREE->value = MIN;
    thinkTREE->first = -1;
    thinkTREE->cut = false;
    alpha_beta(thinkTREE);
    if (thinkTREE->first != -1)
    {
        char x, y;
        x = thinkTREE->firstPoint[0] < 10 ? thinkTREE->firstPoint[0] + '0' : thinkTREE->firstPoint[0] - 10 + 'A';
        y = thinkTREE->firstPoint[1] < 10 ? thinkTREE->firstPoint[1] + '0' : thinkTREE->firstPoint[1] - 10 + 'A';
        addToMap(currentMap, x, y, whoseTurn);
        drawMap(currentMap, x, y);
        if (LinkF5(thinkTREE->firstPoint[0] - 1, thinkTREE->firstPoint[1] - 1, currentMap))
            win = 2;
    }
    else
    {
        cout << "找不到下棋的位置!" << endl;
        win = 1;
    }
    clear(thinkTREE);
}

void print(TREE* pTREE)
{
    cout << (int)pTREE->childs.size() << endl;
    int count = 0;
    for (vector<TREE*>::iterator it = pTREE->childs.begin(); it != pTREE->childs.end(); it++, count++)
    {
        cout << "\n---------------------------\n";
        cout << count << ":" << (*it)->point[0] << (*it)->point[1];
//      for (int i = 0; i < 15; i++)
//      {
//          for (int j = 0; j < 15; j++)
//              cout << (*it)->map[i][j] << ' ';
//          cout << endl;
//      }
    }
}

void alpha_beta(TREE* pTREE)
{
    //如果被剪枝，直接返回
    if (pTREE->cut)
        return;
    //如果达到了最大深度，则计算评估值
    if (pTREE->depth >= SEARCH_DEPTH)
    {
        pTREE->value = total_score(pTREE->map, 2 - pTREE->depth % 2);
        return;
    }

    //生成待扩展的子节点，最多扩展MAX_CHILDS个。
    scanMap(pTREE, 2 - pTREE->depth % 2);
    //print(pTREE);

    int count = 0;//和it对应的一个遍历量，记录下it的次序

    //遍历计算子节点，判断是否剪枝
    for (vector<TREE*>::iterator it = pTREE->childs.begin(); it != pTREE->childs.end(); it++, count++)
    {
        alpha_beta(*it);
        int v = (*it)->value;
        if (pTREE->first == -1)
        {
            pTREE->value = v;
            pTREE->first = count;
            pTREE->firstPoint[0] = (pTREE->childs.at(pTREE->first))->point[0];
            pTREE->firstPoint[1] = (pTREE->childs.at(pTREE->first))->point[1];
        }
        else if (pTREE->depth % 2 == 0 && v >= pTREE->value)
        {
            double p = (double)rand() / (double)(RAND_MAX);
            if (v > pTREE->value || p > p_accept)
            {
                pTREE->value = v;
                pTREE->first = count;
                pTREE->firstPoint[0] = (pTREE->childs.at(pTREE->first))->point[0];
                pTREE->firstPoint[1] = (pTREE->childs.at(pTREE->first))->point[1];
            }
        }
        else if (pTREE->depth % 2 != 0 && v <= pTREE->value)
        {
            double p = (double)rand() / (double)(RAND_MAX);
            if (v < pTREE->value || p > p_accept)
            {
                pTREE->value = v;
                pTREE->first = count;
                pTREE->firstPoint[0] = (pTREE->childs.at(pTREE->first))->point[0];
                pTREE->firstPoint[1] = (pTREE->childs.at(pTREE->first))->point[1];
            }
        }

        //以下开始判断是否可以剪枝
        TREE *pF = pTREE->father;
        while(pF != NULL)
        {
            if (((pTREE->depth % 2 == 0 && pTREE->value > pF->value) || (pTREE->depth % 2 == 1 && pTREE->value < pF->value))
                && pF->value != MIN && pF->value != MAX)
            {
                it++;

                //可以剪枝，标记剪枝的有关信息
                while (it != pTREE->childs.end())
                {
                    (*it)->cut = true;
                    cut++;
                    it++;
                }

                return; //疑问：其实直接return就行了，因为兄弟们就不用做了，也就不用标记了。
            }
            //之前的所有祖先节点都要进行判断
            pF = pF->father;
            if (pF != NULL)
                pF = pF->father;
            else
                break;
        }
    }
}

void clear(TREE* pTREE)
{
    for (vector<TREE*>::iterator it = pTREE->childs.begin(); it != pTREE->childs.end(); it++){
        if (it == pTREE->childs.end())
            delete *it;
    }
    delete pTREE;
}

void printMap(Map map)
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
            cout << map[i][j] << ' ';
        cout << endl;
    }
}

//统计出在棋盘上的得分
int total_score(Map map, int turn)
{
    //cout << "-----------score-----------\n";
    //printMap(map);
    int score = 0;
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (map[i][j] != 0)
            {
                int temp = 0;
                for (int level = 17; level > 0; level--)
                {
                    temp = PriorityGet(i, j, level, map) * level_score[level];
                    if (temp != 0)
                    {
                        score += (map[i][j] == 2) ?  temp : temp * (int)(-1);
                        break;
                    }
                }
            }
        }
    }
    return score;
}

void scanMap(TREE *&pTREE, int turn)
{
    Map record;
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            record[i][j] = pTREE->map[i][j];

    //按照优先级从高到低的顺序寻找MAX_CHILDS个子节点
    for(int level = 17; level > 0; level--)
    {
        //从中间开始扫描，i，j 为扫描到的坐标
        int i = 7;
        int j = 7;
        int step = 0;       //扫描过的步数
        int direct = 0;     //标记扫描的方向
        int direct_num = 1; //在该方向上要走的步数

        while(i < 15 && j < 15 && i >= 0 && j >= 0)
        {
            if(record[i][j] == 0)
            {
                bool flag = false;
                record[i][j] = turn;
                //如果满足优先级的要求就加入到子节点的向量中
                if(PriorityGet(i, j, level, record) == 1)
                {
                    flag = true;
                    TREE *child = new TREE();
                    for (int p_i = 0; p_i < 15; p_i++)
                        for (int p_j = 0; p_j < 15; p_j++)
                            child->map[p_i][p_j] = record[p_i][p_j];
                    child->depth = pTREE->depth + 1;
                    child->value = child->depth % 2 == 0 ? MIN : MAX;
                    child->first = -1;
                    child->cut = false;
                    child->father = pTREE;
                    child->point[0] = i + 1;
                    child->point[1] = j + 1;
                    pTREE->childs.push_back(child);
                    if (pTREE->childs.size() == MAX_CHILDS)
                        return;
                }

                //有些点对方占了就会有很大优势
                if (flag == false && level > 11)
                {
                    record[i][j] = 3 - turn;
                    if(PriorityGet(i, j, level, record) == 1)
                    {
                        record[i][j] = turn;
                        TREE *child = new TREE();
                        for (int p_i = 0; p_i < 15; p_i++)
                            for (int p_j = 0; p_j < 15; p_j++)
                                child->map[p_i][p_j] = record[p_i][p_j];
                        child->depth = pTREE->depth + 1;
                        child->value = child->depth % 2 == 0 ? MIN : MAX;
                        child->first = -1;
                        child->cut = false;
                        child->father = pTREE;
                        child->point[0] = i + 1;
                        child->point[1] = j + 1;
                        pTREE->childs.push_back(child);
                        if (pTREE->childs.size() == MAX_CHILDS)
                            return;
                    }
                }
                record[i][j] = 0;
            }

            step++;
            if(step > direct_num)
            {
                direct = (direct + 1) % 4;
                if(direct % 2 == 0)
                {
                    direct_num++;
                }
                step = 1;
            }

            i += dir[direct][0];
            j += dir[direct][1];
        }
    }
}

//判断各个优先级的位置
/*
int LinkSS4(int x,int y, Map map);  211110 or 211101 or 211011
                                    210111 or 11110 or 11101
                                    11011 or 10111
int LinkSS3(int x,int y, Map map);  211100 or 211010 or 211001
                                    210110 or 210101 or 21011
                                    11100 or 10110 or 10011
                                    10101
int LinkS5(int x,int y, Map map);   1011101
int LinkS4(int x,int y, Map map);   1010101
int LinkS3(int x,int y, Map map);   1010100
int LinkF5(int x,int y, Map map);   11111
int LinkF4(int x,int y, Map map);   11110
int LinkF3(int x,int y, Map map);   011100 or 010110
int LinkF2(int x,int y, Map map);   011000 or 010100 or 010010
int LinkF1(int x,int y, Map map);   1
30000,10000,10000,10000,5000,5000,5000,5000,500,200,200,100,100,100,50,50,10
成5，活4，双冲4，双跳冲四，冲四+跳四，冲四+活三，跳四+活三，双活三，跳4，冲四，活三，双死三，双跳三，多活二，活二，冲三，活一
*/
int PriorityGet(int i, int j, int level, Map map)
{
    switch(level)
    {
    case 17:
        if(LinkF5(i, j, map))//30000
        {
            return 1;
        }
        break;
    case 16:
        if(LinkF4(i, j, map))//10000
        {
            return 1;
        }
        break;
    case 15:
        if(LinkSS4(i, j, map) > 2)//10000
        {
            return 1;
        }
        break;
    case 14:
        if(LinkS5(i, j, map))//10000
        {
            return 1;
        }
        break;
    case 13:
        if(LinkSS4(i, j, map) && LinkS4(i, j, map))//5000
        {
            return 1;
        }
        break;
    case 12:
        if(LinkSS4(i, j, map) && LinkF3(i, j, map))//5000
        {
            return 1;
        }
        break;
    case 11:
        if(LinkS4(i, j, map) && LinkF3(i, j, map))//5000
        {
            return 1;
        }
        break;
    case 10:
        if(LinkF3(i, j, map) > 2)//5000
        {
            return 1;
        }
        break;
    case 9:
        if(LinkS4(i, j, map))//500
        {
            return 1;
        }
        break;
    case 8:
        if(LinkSS4(i, j, map))//200
        {
            return 1;
        }
        break;
    case 7:
        if(LinkF3(i, j, map))//200
        {
            return 1;
        }
        break;
    case 6:
        if(LinkSS3(i, j, map) > 1)//100
        {
            return 1;
        }
        break;
    case 5:
        if(LinkS3(i, j, map) > 1)//100
        {
            return 1;
        }
        break;
    case 4:
        if(LinkF2(i, j, map) > 2)//100
        {
            return 1;
        }
        break;
    case 3:
        if(LinkF2(i, j, map))//50
        {
            return 1;
        }
        break;
    case 2:
        if(LinkSS3(i, j, map))//50
        {
            return 1;
        }
        break;
    case 1:
        if(LinkF1(i, j, map))//10
        {
            return 1;
        }
        break;
    }
    return 0;
}

int LinkSS4(int x,int y, Map map)
{
    int a[8][6]={{2,1,1,1,1,0},{2,1,0,1,1,1},{2,1,1,0,1,1},
    {2,1,1,1,0,1},{1,2,2,2,2,0},{1,2,0,2,2,2},
    {1,2,2,0,2,2},{1,2,2,2,0,2}};
    int b[4][2]={{-1,0},{0,-1},{-1,-1},{-1,1}};
    int M_I,M_J,count=0,A_J,Old_x,Old_y,num;

    num=map[x][y];
    Old_x=x;
    Old_y=y;

    for(int i = 0; i < 8; i++)
    {
        if(num != a[i][1])continue;
        for(int j = 0; j < 2;j++)
        {
            for(int k = 0; k < 4; k++){
                x = Old_x;
                y = Old_y;
                while(x>=0&&y<15&&x<15&&y>=0)
                {
                    M_I = x;
                    M_J = y;
                    if(j % 2) A_J=5;
                    else A_J = 0;
                    while(M_I >= 0 && M_I < 15 && M_J >= 0 && M_J < 15
                        && (map[M_I][M_J] == a[i][A_J]) && (A_J >= 0 && A_J < 6))
                    {
                        M_I -= b[k][0];
                        M_J -= b[k][1];
                        if(j % 2)
                            A_J--;
                        else
                            A_J++;
                    }
                    if((A_J == 6 && j == 0)||(A_J < 0 && j == 1))
                        count++;
                    x += b[k][0];
                    y += b[k][1];
                }
            }
        }
    }

    for(int i = 0;i < 8; i++)
    {
        if(num != a[i][1])
            continue;
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                x=Old_x;
                y=Old_y;

                while(x >= 0 && y < 15 && x < 15 && y >= 0)
                {
                    M_I = x;
                    M_J = y;
                    if(j % 2) A_J = 5;
                    else A_J = 1;

                    while(M_I >= 0 && M_I < 15 && M_J >= 0 && M_J < 15
                        && (map[M_I][M_J] == a[i][A_J])
                        && (A_J > 0 && A_J < 6))
                    {
                        M_I -= b[k][0];
                        M_J -= b[k][1];
                        if(j % 2) A_J--;
                        else A_J++;
                    }

                    if((A_J == 6 && j == 0) || (A_J == 0 && j == 1))
                    {
                        if((y == 0 && M_J != 0) || (x == 0 && M_I != 0)
                            || (y == 14 && M_J < 14))count++;
                        if((M_I == 15 && x < 14)||(M_J == 15 && y < 14)) count++;
                    }
                    x += b[k][0];
                    y += b[k][1];

                }

            }
        }
    }

    return count;
}


int LinkSS3(int x,int y, Map map)
{
    int a[12][6] = {{2,1,1,1,0,0},{2,1,1,0,1,0},{2,1,1,0,0,1},
    {2,1,0,1,1,0},{2,1,0,1,0,1},{2,1,0,0,1,1},
    {1,2,2,2,0,0},{1,2,2,0,2,0},{1,2,2,0,0,2},
    {1,2,0,2,2,0},{1,2,0,2,0,2},{1,2,0,0,2,2}};
    int b[4][2]={{-1,0},{0,-1},{-1,-1},{-1,1}};
    int M_I,M_J,count=0,A_J,Old_x,Old_y,num;

    num=map[x][y];
    Old_x=x;
    Old_y=y;


    for(int i = 0; i < 12; i++)
    {
        if(num != a[i][1]) continue;
        for(int j = 0; j < 2;j++)
        {
            for(int k = 0;k < 4;k++)
            {
                x = Old_x;
                y = Old_y;
                while(x >= 0 && y < 15 && x <15 && y >= 0)
                {
                    M_I = x;
                    M_J = y;
                    if(j % 2) A_J = 5;
                    else A_J = 0;
                    while(M_I >= 0 && M_I < 15 && M_J >= 0 && M_J < 15
                        && (map[M_I][M_J] == a[i][A_J])
                        && (A_J >= 0 && A_J < 6))
                    {
                        M_I -= b[k][0];
                        M_J -= b[k][1];
                        if(j % 2) A_J--;
                        else A_J++;
                    }
                    if((A_J == 6 && j == 0) || (A_J < 0 && j == 1))count++;
                    x += b[k][0];
                    y += b[k][1];
                }
            }
        }
    }

    for(int i = 0;i < 12;i++)
    {
        if(num != a[i][1])continue;
        for(int j = 0;j < 2;j++)
        {
            for(int k = 0;k < 4; k++)
            {
                x = Old_x;
                y = Old_y;
                while(x >= 0 && y < 15 && x < 15 && y >= 0)
                {
                    M_I = x;
                    M_J = y;
                    if(j % 2) A_J = 5;
                    else A_J = 1;
                    while(M_I >= 0 && M_I < 15 && M_J >= 0 && M_J < 15
                        && (map[M_I][M_J] == a[i][A_J])
                        && (A_J>0 && A_J < 6))
                    {
                        M_I -= b[k][0];
                        M_J -= b[k][1];
                        if(j % 2) A_J--;
                        else A_J++;
                    }
                    if((A_J == 6 && j == 0) || (A_J == 0 && j == 1))
                    {
                        if((y == 0 && M_J != 0) || (x == 0 && M_I != 0)
                            || (y == 14 && M_J < 14)) count++;
                        if((M_I == 15 && x < 14) || (M_J == 15 && y < 14))count++;

                    }
                    x += b[k][0];
                    y += b[k][1];
                }
            }
        }
    }

    return count;

}


int LinkS5(int x,int y, Map map)
{
    int a[2][7]={{1,0,1,1,1,0,1},{2,0,2,2,2,0,2}};
    int b[4][2]={{-1,0},{0,-1},{-1,-1},{-1,1}};
    int M_I,M_J,count=0,A_J,Old_x,Old_y,num;
    num = map[x][y];
    Old_x = x;
    Old_y = y;
    for(int i = 0;i < 2; i++)
    {
        if(num != a[i][0]) continue;
        for(int j = 0;j < 2; j++)
        {
            for(int k = 0; k < 4; k++){
                x = Old_x;
                y = Old_y;
                while(x >= 0 && y < 15 && x < 15 && y >= 0
                    && (map[x][y] == 0 || map[x][y] == num))
                {
                    M_I = x;
                    M_J = y;
                    if(j % 2) A_J = 6;
                    else A_J = 0;
                    while(M_I >= 0 && M_I < 15 && M_J >= 0 && M_J < 15
                        && (map[M_I][M_J] == a[i][A_J]) && (A_J >= 0 && A_J < 7))
                    {
                        M_I -= b[k][0];
                        M_J -= b[k][1];
                        if(j % 2) A_J--;
                        else A_J++;
                    }
                    if((A_J == 7 && j == 0) || (A_J < 0 && j == 1)) count++;
                    x += b[k][0];
                    y += b[k][1];
                }
            }
        }
    }

    return count;
}

int LinkS4(int x,int y, Map map)
{
    int a[2][7]={{1,0,1,0,1,0,1},{2,0,2,0,2,0,2}};
    int b[4][2]={{-1,0},{0,-1},{-1,-1},{-1,1}};
    int M_I,M_J,count=0,A_J,Old_x,Old_y,num;
    num = map[x][y];
    Old_x = x;
    Old_y = y;
    for(int i = 0; i < 2; i++)
    {
        if(num != a[i][0]) continue;
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 4; k++){
                x = Old_x;
                y = Old_y;
                while(x >= 0 && y < 15 && x < 15 && y >= 0
                    && (map[x][y] == 0 || map[x][y] == num))
                {
                    M_I = x;
                    M_J = y;
                    if(j % 2) A_J = 6;
                    else A_J = 0;
                    while(M_I >= 0 && M_I < 15 && M_J >= 0 && M_J < 15
                        && (map[M_I][M_J] == a[i][A_J]) && (A_J >= 0&&A_J < 7))
                    {
                        M_I -= b[k][0];
                        M_J -= b[k][1];
                        if(j % 2) A_J--;
                        else A_J++;
                    }
                    if((A_J == 7 && j == 0) || (A_J < 0 && j == 1))count++;
                    x += b[k][0];
                    y += b[k][1];
                }
            }
        }
    }

    return count;
}


int LinkS3(int x,int y, Map map)
{
    int a[2][7]={{1,0,1,0,1,0,0},{2,0,2,0,2,0,0}};
    int b[4][2]={{-1,0},{0,-1},{-1,-1},{-1,1}};
    int M_I,M_J,count=0,A_J,Old_x,Old_y,num;
    num = map[x][y];
    Old_x = x;
    Old_y = y;
    for(int i = 0; i < 2; i++)
    {
        if(num != a[i][0]) continue;
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                x = Old_x;
                y = Old_y;
                while(x >= 0 && y < 15 && x < 15 && y >= 0
                    && (map[x][y] == 0 || map[x][y] == num))
                {
                    M_I = x;
                    M_J = y;
                    if(j % 2) A_J = 6;
                    else A_J = 0;
                    while(M_I >= 0 && M_I < 15 && M_J >= 0 && M_J < 15
                        && (map[M_I][M_J] == a[i][A_J]) && (A_J >= 0 && A_J < 7))
                    {
                        M_I -= b[k][0];
                        M_J -= b[k][1];
                        if(j % 2) A_J--;
                        else A_J++;
                    }
                    if((A_J == 7 && j == 0) || (A_J < 0 && j == 1))count++;
                    x += b[k][0];
                    y += b[k][1];
                }
            }
        }
    }

    return count;
}


int LinkF5(int x,int y, Map map)
{
    int a[2][6]={{1,1,1,1,1},{2,2,2,2,2}};
    int b[4][2]={{-1,0},{0,-1},{-1,-1},{-1,1}};
    int M_I,M_J,count=0,A_J,Old_x,Old_y,num;

    num = map[x][y];
    Old_x = x;
    Old_y = y;

    for(int i = 0; i < 2; i++)
    {
        if(num != a[i][1]) continue;
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                x = Old_x;
                y = Old_y;
                while(x >= 0&& y < 15 && x < 15 && y >= 0
                    && (map[x][y] == 0 || map[x][y] == num))
                {
                    M_I = x;
                    M_J = y;
                    if(j % 2) A_J=4;
                    else A_J = 0;
                    while(M_I >= 0 && M_I < 15 && M_J >= 0 && M_J < 15
                        && (map[M_I][M_J] == a[i][A_J]) && (A_J >= 0 && A_J < 6))
                    {
                        M_I -= b[k][0];
                        M_J -= b[k][1];
                        if(j % 2) A_J--;
                        else A_J++;
                    }
                    if((A_J == 5 && j == 0) || ( A_J < 0 && j == 1)) count++;
                    x += b[k][0];
                    y += b[k][1];
                }
            }
        }
    }
    return count;
}

int LinkF4(int x,int y, Map map)
{
    int a[2][6]={{0,1,1,1,1,0},{0,2,2,2,2,0}};
    int b[4][2]={{-1,0},{0,-1},{-1,-1},{-1,1}};
    int M_I,M_J,count=0,A_J,Old_x,Old_y,num;

    num = map[x][y];
    Old_x = x;
    Old_y = y;

    for(int i = 0; i < 2; i++)
    {
        if(num != a[i][1]) continue;
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                x = Old_x;
                y = Old_y;
                while(x >= 0 && y < 15 && x < 15 && y >= 0
                    && (map[x][y] == 0 || map[x][y] == num))
                {
                    M_I = x;
                    M_J = y;
                    if(j % 2) A_J = 5;
                    else A_J = 0;
                    while(M_I >= 0 && M_I < 15 && M_J >= 0 && M_J < 15
                        && (map[M_I][M_J] == a[i][A_J]) && (A_J >= 0 && A_J < 6))
                    {
                        M_I -= b[k][0];
                        M_J -= b[k][1];
                        if(j % 2) A_J--;
                        else A_J++;
                    }
                    if((A_J == 6 && j == 0) || (A_J < 0 && j == 1)) count++;
                    x += b[k][0];
                    y += b[k][1];
                }
            }
        }
    }
    return count;
}


int LinkF3(int x,int y, Map map)
{
    int a[4][6]={{0,1,1,0,1,0},{0,1,1,1,0,0},{0,2,2,0,2,0},{0,2,2,2,0,0}};
    int b[4][2]={{-1,0},{0,-1},{-1,-1},{-1,1}};
    int M_I,M_J,count=0,A_J,Old_x,Old_y,num;

    num = map[x][y];
    Old_x = x;
    Old_y = y;

    for(int i = 0; i < 4; i++)
    {
        if(num != a[i][1]) continue;
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                x = Old_x;
                y = Old_y;
                while(x >= 0 && y < 15 && x < 15 && y >= 0
                    && (map[x][y] == 0 || map[x][y] == num))
                {
                    M_I = x;
                    M_J = y;
                    if(j % 2) A_J = 5;
                    else A_J = 0;
                    while(M_I >= 0 && M_I < 15 && M_J >= 0 && M_J < 15
                        && (map[M_I][M_J] == a[i][A_J]) && (A_J >= 0 && A_J < 6))
                    {
                        M_I -= b[k][0];
                        M_J -= b[k][1];
                        if(j % 2) A_J--;
                        else A_J++;
                    }
                    if((A_J == 6 && j == 0) || (A_J < 0 && j == 1)) count++;
                    x += b[k][0];
                    y += b[k][1];
                }
            }
        }
    }
    return count;
}


int LinkF2(int x,int y, Map map)
{
    int a[6][6]={
        {0,1,1,0,0,0},
        {0,1,0,1,0,0},
        {0,1,0,0,1,0},
        {0,2,2,0,0,0},
        {0,2,0,2,0,0},
        {0,2,0,0,2,0}};
    int b[4][2]={
        {-1,0},
        {0,-1},
        {-1,-1},
        {-1,1}};
    int M_I,M_J,count=0,A_J,Old_x,Old_y,num;
    num = map[x][y];
    Old_x = x;
    Old_y = y;
    for(int i = 0; i < 6; i++)
    {
        if(num != a[i][1]) continue;
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                x = Old_x;
                y = Old_y;
                while(x >= 0 && y < 15 && x < 15 && y >= 0
                    && (map[x][y] == 0 || map[x][y] == num))
                {
                    M_I = x;
                    M_J = y;
                    if(j % 2) A_J = 5;
                    else A_J = 0;
                    while(M_I >= 0 && M_I < 15 && M_J >= 0 && M_J < 15
                        && (map[M_I][M_J] == a[i][A_J]) && (A_J >= 0 && A_J < 6))
                    {
                        M_I -= b[k][0];
                        M_J -= b[k][1];
                        if(j % 2) A_J--;
                        else A_J++;
                    }
                    if((A_J == 6 && j == 0) || (A_J < 0 && j == 1)) count++;
                    x += b[k][0];
                    y += b[k][1];
                }
            }
        }
    }
    return count;
}


int LinkF1(int x,int y, Map map)
{
    if(x < 15 && x >= 0 && y < 15 && y >= 0)
        return 1;
    return 0;
}

int main()
{
    init();
    playGame();
    return 0;
}

