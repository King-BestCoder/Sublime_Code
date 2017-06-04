#include<cstdio>
using namespace std;
struct point{
    double x, y;
};
bool f(point a, point b, point c, point d){
    double d1 = (a.x-c.x)*(d.y-c.y)-(a.y-c.y)*(d.x-c.x);
    double d2 = (b.x-c.x)*(d.y-c.y)-(b.y-c.y)*(d.x-c.x);
    if(d1*d2<=0) return 1;
    return 0;
}
bool check(point a, point b, point c, point d){
    if(!f(a,b,c,d)) return 0;
    if(!f(c,d,a,b)) return 0;
    return 1;
}
int main(){
    int t;
    point a, b, c, d;
    scanf("%d", &t);
    while(t--){
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);
        if(check(a,b,c,d))
            puts("Yes");
        else puts("No");
    }
    return 0;
}