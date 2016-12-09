#include <bits/stdc++.h>
using namespace std;
//插入操作insert   binarytree.insert(value)
//删除操作remove   binarytree.remove(value)
//查询操作selectda selectxiap binary.select...
const int maxn=1000005;
class SBTNode
{
public:
    int data, size, value;
    SBTNode * lchild, * rchild, * father;
    SBTNode(int init_data, int init_size = 0, SBTNode * init_father = NULL);
    ~SBTNode();
    // void print(SBTNode *p);
    void insert(int value);
    SBTNode * search(int value);
    SBTNode * predecessor();
    SBTNode * successor();
    void remove_node(SBTNode * delete_node);
    bool remove(int value);
    int selectda(int k);
    int selectxiao(int k);
};

class BinaryTree
{
private:
    SBTNode * root;
public:
    BinaryTree();
    ~BinaryTree();
    void insert(int value);
    void print();
    void print(SBTNode *p);
    bool find(int value);
    bool remove(int value);
    int selectda(int k);
    int selectxiao(int k);
};

SBTNode ZERO(0);
SBTNode * ZPTR = &ZERO;

SBTNode::SBTNode(int init_data, int init_size, SBTNode * init_father){
    data = init_data;
    size = init_size;
    lchild = ZPTR;
    rchild = ZPTR;
    father = init_father;
}

SBTNode::~SBTNode(){
    if (lchild != ZPTR){
        delete lchild;
    }
    if (rchild != ZPTR){
        delete rchild;
    }
}

SBTNode * left_rotate(SBTNode * node){
    SBTNode * temp = node->rchild;
    node->rchild = temp->lchild;
    temp->lchild->father = node;
    temp->lchild = node;
    temp->father = node->father;
    node->father = temp;
    temp->size = node->size;
    node->size = node->lchild->size + node->rchild->size + 1;
    return temp;
}

SBTNode * right_rotate(SBTNode * node){
    SBTNode * temp = node->lchild;
    node->lchild = temp->rchild;
    temp->rchild->father = node;
    temp->rchild = node;
    temp->father = node->father;
    node->father = temp;
    temp->size = node->size;
    node->size = node->lchild->size + node->rchild->size + 1;
    return temp;
}

SBTNode * maintain(SBTNode * node, bool flag){
    if (flag == false){
        if (node->lchild->lchild->size > node->rchild->size){
            node = right_rotate(node);
        }
        else if (node->lchild->rchild->size > node->rchild->size){
            node->lchild = left_rotate(node->lchild);
            node = right_rotate(node);
        }
        else{
            return node;
        }
    }
    else{
        if (node->rchild->rchild->size > node->lchild->size){
            node = left_rotate(node);
        }
        else if (node->rchild->lchild->size > node->lchild->size){
            node->rchild = right_rotate(node->rchild);
            node = left_rotate(node);
        }
        else{
            return node;
        }
    }
    node->lchild = maintain(node->lchild, false);
    node->rchild = maintain(node->rchild, true);
    node = maintain(node, false);
    node = maintain(node, true);
    return node;
}

SBTNode * insert(SBTNode * node, int value){
    if (value == node->data){
        return node;
    }
    else{
        node->size++;
        if (value > node->data){
            if (node->rchild == ZPTR){
                node->rchild = new SBTNode(value, 1, node);
            }
            else{
                node->rchild = insert(node->rchild, value);
            }
        }
        else{
            if (node->lchild == ZPTR){
                node->lchild = new SBTNode(value, 1, node);
            }
            else{
                node->lchild = insert(node->lchild, value);
            }
        }
    }
    return maintain(node, value > node->data);
}

SBTNode * SBTNode::search(int value){
    if (data == value){
        return this;
    }
    else if (value > data){
        if (rchild == ZPTR){
            return ZPTR;
        }
        else{
            return rchild->search(value);
        }
    }
    else{
        if (lchild == ZPTR){
            return ZPTR;
        }
        else{
            return lchild->search(value);
        }
    }
}

SBTNode * SBTNode::predecessor()
{
    SBTNode * temp = lchild;
    while (temp != ZPTR && temp->rchild != ZPTR){
        temp = temp->rchild;
    }
    return temp;
}

SBTNode * SBTNode::successor()
{
    SBTNode * temp = rchild;
    while (temp != ZPTR && temp->lchild != ZPTR){
        temp = temp->lchild;
    }
    return temp;
}

void SBTNode::remove_node(SBTNode * delete_node)
{
    SBTNode * temp = ZPTR;
    if (delete_node->lchild != ZPTR){
        temp = delete_node->lchild;
        temp->father = delete_node->father;
        delete_node->lchild = ZPTR;
    }

    if (delete_node->rchild != ZPTR){
        temp = delete_node->rchild;
        temp->father = delete_node->father;
        delete_node->rchild = ZPTR;
    }
    if (delete_node->father->lchild == delete_node){
        delete_node->father->lchild = temp;
    }
    else{
        delete_node->father->rchild = temp;
    }
    temp = delete_node;
    while (temp != NULL){
        temp->size--;
        temp = temp->father;
    }
    delete delete_node;
}

bool SBTNode::remove(int value)
{
    SBTNode * delete_node, * current_node;
    current_node = search(value);
    if (current_node == ZPTR){
        return false;
    }
    size--;
    if (current_node->lchild != ZPTR){
        delete_node = current_node->predecessor();
    }
    else if (current_node->rchild != ZPTR){
        delete_node = current_node->successor();
    }
    else{
        delete_node = current_node;
    }
    current_node->data = delete_node->data;
    remove_node(delete_node);
    return true;
}

int SBTNode::selectda(int k)
{
    int rank=rchild->size+1;
    if(k==rank){
        return data;
    }
    else if(k<rank){
        return rchild->selectda(k);
    }
    else{
        return lchild->selectda(k-rank);
    }
}
int SBTNode::selectxiao(int k){
    //查找第k小的元素
    int rank=lchild->size+1;
    if(k==rank){
        return data;
    }
    else if(k<rank){
        return lchild->selectxiao(k);
    }
    else {
        return rchild->selectxiao(k-rank);
    }
}

BinaryTree::BinaryTree(){
    root = NULL;
}

BinaryTree::~BinaryTree(){
    if (root != NULL){
        delete root;
    }
}

void BinaryTree::insert(int value){
    //插入元素value
    if (root == NULL){
        root = new SBTNode(value, 1);
    }
    else{
        root = ::insert(root, value);
    }
}

bool BinaryTree::find(int value){
    //查找元素value是否存在
    if (root->search(value) == NULL){
        return false;
    }
    else{
        return true;
    }
}

bool BinaryTree::remove(int value){
    //删除元素value
    return root->remove(value);
}

int BinaryTree::selectda(int k){
    //查找第k大的数
    return root->selectda(k);
}

int BinaryTree::selectxiao(int k){
    //查找第k小的数
    return root->selectxiao(k);
}
void BinaryTree::print(SBTNode *p){
    if(p!=ZPTR){
        // printf("ys\n");
        if(p->lchild!=ZPTR)
            print(p->lchild);
        printf("%d\n",p->data);
        if(p->rchild!=ZPTR)
            print(p->rchild);
    }
}
void BinaryTree::print(){
    print(root);
}
int main()
{
    BinaryTree binarytree;
    int n,t;
    // freopen("data1m.txt","r",stdin);
    // freopen("outputs.txt","w",stdout);
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>t;
        binarytree.insert(t);
    }
    binarytree.print();
    return 0;
}
