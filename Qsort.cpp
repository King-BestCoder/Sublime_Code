#include <stdio.h>
#include <string.h>
using namespace std;

int partition(int *a, int l, int h)
{
    int x = a[l];
    int i = l;
    int j = h+1;
    int temp;
    while (i<j)
    {
        while (a[++i]<x&&i<h);
        while(a[--j]>x);
        if (i<j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    a[l] = a[j];
    a[j] = x;
    return j;
}

void qsort(int *a, int l, int h)
{
    if (l>=h)
        return;
    int *s = new int[h-l+1];
    int p = 0;
    s[p++] = l;
    s[p++] = h;
    int low,high,q;
    while (p>0)
    {
        high = s[--p];
        low = s[--p];
        if (low>=high)
            break;
        q = partition(a, low, high);
        if (q-low > high-q)
        {
            s[p++] = low;
            s[p++] = q-1;
            if (high > q)
            {
                s[p++] = q+1;
                s[p++] = high;
            }
        }
        else
        {
            s[p++] = q+1;
            s[p++] = high;
            if (q > low)
            {
                s[p++] = low;
                s[p++] = q-1;
            }
        }
    }
    delete []s;
}

int main()
{
    int a[9] = {9,8,7,6,5,4,3,2,1};
//int a[9] = {1,2,3,4,5,6,7,8,9};
    qsort(a,0,8);
    for (int i=0; i<9; i++)
        printf("%d\n",a[i]);
    return 0;
}
