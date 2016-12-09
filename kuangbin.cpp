#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
const int maxn=50005;
struct Node{
    int p,r;
}node;
node num[maxn];
int n,m;
int a,b,c;
void init(){
    for(int i=1;i<=n;i++){
        num[i].p=i;
        num[i].r=0;
    }
}
void merge(){

}
int main(int argc, char const *argv[])
{
    scanf("%d %d",&n,&m);
    init();
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&c,&a,&b);
        if(c==1){

        }
        else{

        }
    }
    return 0;
}