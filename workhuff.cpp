#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
struct Heap {
    int *data, size;
    Heap(int length_input) {
        data = new int[length_input];
        size = 0;
    }
    void push(int value) {
        data[size] = value;
        int current = size;
        int father = (current - 1) / 2;
        while (data[current] < data[father]) {
            swap(data[current], data[father]);
            current = father;
            father = (current - 1) / 2;
        }
        size++;
    }
    int top() {
         return data[0];
    }
    void update(int pos, int n) {
        int lchild = 2 * pos + 1, rchild = 2 * pos + 2;
        int max_value = pos;
        if (lchild < n && data[lchild] < data[max_value]) {
            max_value = lchild;
        }
        if (rchild < n && data[rchild] < data[max_value]) {
            max_value = rchild;
        }
        if (max_value != pos) {
            swap(data[pos], data[max_value]);
            update(max_value, n);
        }
    }
    void pop() {
        swap(data[0], data[size - 1]);
        size--;
        update(0, size);
    }
    int heap_size() {
        return size;
    }
};
int main() {
    int n,value,ans=0;
    scanf("%d",&n);
    Heap heap(n);
    for(int i=1;i<=n;i++){
        scanf("%d",&value);
        heap.push(value);
    }
    if(n==1){
        ans=ans+heap.top();
    }
    while(heap.heap_size()>1){
        int a=heap.top();
        heap.pop();
        int b=heap.top();
        heap.pop();
        ans=ans+a+b;
        heap.push(a+b);
    }
    printf("%d\n",ans);
    return 0;
}
