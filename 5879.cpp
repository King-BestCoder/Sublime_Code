#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
const int maxn=100005;
double sum[maxn];
#define PI 3.1415926535897932

double val[15000];
void init() {
    double res = 0;
    for (int i = 1; i < 15000; i++) {
        res += 1.0 / i / i;
        val[i] = res;
    }
}

int main() {
    //freopen("Input.txt", "r", stdin);
    init();
    double n;
    while (scanf("%lf", &n) != EOF) {
        if (n >= 110292)
            printf("1.64493\n");
        else if (n >= 52447)
            printf("1.64492\n");
        else if (n >= 34403)
            printf("1.64491\n");
        else if (n >= 25597)
            printf("1.64490\n");
        else if (n >= 20380)
            printf("1.64489\n");
        else if (n >= 16930)
            printf("1.64488\n");
        else if (n >= 14479)
            printf("1.64487\n");
        else 
            printf("%.5lf\n", val[(int)n]);
    }
    return 0;
}