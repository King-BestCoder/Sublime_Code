#include <bits/stdc++.h>
using namespace std;
int n;
int main()  
{  
    int n, cct=0;  
    long long sum;  
    while(scanf("%d", &n) && n)  
    {  
        printf("Case %d: ", ++cct);  
        int m = sqrt((double)n)+2;  
        int tn = n, flagct = 0;  
        sum = 0;  
        for(int i=2; i<=m; i++) // 分解质因子  
            if(tn%i == 0)  
            {  
                ++flagct; // 记录质因子个数  
                int tem = 1;  
                while(tn%i == 0)  
                {  
                    tem *= i;  
                    tn /= i;  
                }  
                sum += tem;  
            }  
        if(n == tn) // 本身为素数的情况  
            sum = (long long)n + 1; // n也必须是long long  
        else if(flagct == 1 || tn != 1) // 单质因子或是剩下一个大于sqrt（n）的质因子的情况（注：很容易证明，剩下的质因子个数最多为一个）  
            sum += tn; // 单质因子情况下tn为1，剩余质因子情况下tn为剩余质因子数  
        printf("%lld\n", sum);  
    }  
    return 0;  
}  