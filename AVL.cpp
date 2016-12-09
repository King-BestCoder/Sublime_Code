#include <bits/stdc++.h>
using namespace std;

class avltree
{
    struct avlnode
    {
        int data;
        avlnode *left;
        avlnode *right;
        int height;
        avlnode(const int &element,avlnode *lt,avlnode *rt,int h=0)
            :data(element),left(lt),right(rt),height(h){}
    };

    avlnode *root;

public:
    avltree(avlnode *t=NULL){root=t;}
    ~avltree(){makeEmpty(root);}
    bool find(const int &x)const;
    void insert(const int &x){insert(x,root);}
    void erase(const int &x){erase(x,root);}
    void print();
private:
    void insert(const int &x,avlnode *&t);
    bool erase(const int &x,avlnode* &t);
    void makeEmpty(avlnode *&t);
    int height(avlnode *t) const {return t==NULL?-1:t->height;}
    void LL(avlnode *&t);
    void LR(avlnode* &t);
    void RL(avlnode* &t);
    void RR(avlnode* &t);
    void print(const avlnode *t);
    int max(int a,int b){return (a>b)?a:b;}
};

bool avltree::find(const int &x) const
{
    avlnode *t=root;
    while(t!=NULL&&t->data!=x)
        if(t->data>x) t=t->left; else t=t->right;
    if(t==NULL) return false;
    else return true;
}

void avltree::insert(const int &x,avlnode* &t)
{
    if(t==NULL)
        t=new avlnode(x,NULL,NULL);
    else if(x<t->data)
    {
        insert(x,t->left);
        if(height(t->left)-height(t->right)==2) //t失衡
            if(t->left->data>x) LL(t);
                else LR(t);
    }
    else if(x>t->data)
    {
        insert(x,t->right);
        if(height(t->right)-height(t->left)==2)
            if(t->right->data<x) RR(t);
                else RL(t);
    }

    t->height=max(height(t->left),height(t->right))+1;
}

void avltree::LL(avlnode* &t)
{
    avlnode *t1=t->left;
    t->left=t1->right;
    t1->right=t;
    t->height=max(height(t->left),height(t->right))+1;
    t1->height=max(height(t1->left),height(t))+1;
    t=t1;
}

void avltree::RR(avlnode* &t)
{
    avlnode *t1=t->right;
    t->right=t1->left;
    t1->left=t;
    t->height=max(height(t->left),height(t->right))+1;
    t1->height=max(height(t1->right),height(t))+1;
    t=t1;
}

void avltree::LR(avlnode* &t)
{
    RR(t->left);
    LL(t);
}

void avltree::RL(avlnode* &t)
{
    LL(t->right);
    RR(t);
}

bool avltree::erase(const int &x,avlnode* &t)
{
    bool stop=false;
    int subtree;
    if(t==NULL) return true;
    if(x<t->data)
    {
        stop=erase(x,t->left);subtree=1;
    }
    else if(x>t->data)
    {
        stop=erase(x,t->right);subtree=2;
    }
    else if(t->left!=NULL&&t->right!=NULL)
    {
        avlnode *tmp=t->right;
        while(tmp->left!=NULL) tmp=tmp->left;
        t->data=tmp->data;
        stop=erase(t->data,t->right);
        subtree=2;
    }
    else
    {
        avlnode *oldnode=t;
        t=(t->left!=NULL)?t->left:t->right;
        delete oldnode;
        return false;
    }
    if(stop) return true;
    int bf;
    switch(subtree)
    {
        case 1:bf=height(t->left)-height(t->right)+1;
        if(bf==0) return true;
        if(bf==1) return false;
        if(bf==-1)
        {
            int bfr=height(t->right->left)-height(t->right->right);
            switch(bfr)
            {
                case 0:RR(t);return true;
                case -1:RR(t);return false;
                default:RL(t);return false;
            }
        }
        break;
        case 2:bf=height(t->left)-height(t->right)-1;
        if(bf==0) return true;
        if(bf==-1) return false;
        if(bf==1)
        {
            int bfl=height(t->right->left)-height(t->right->right);
            switch(bfl)
            {
                case 0:LL(t);return true;
                case 1:LL(t);return false;
                default: LR(t);return false;
            }
        }
    }
}

void avltree::makeEmpty(avlnode* &t)
{
    if(t!=NULL)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        free(t);
    }
}

void avltree::print()
{
    return print(root);
}
void avltree::print(const avlnode *t)
{
    if(t!=NULL)
    {
        print(t->left);
        cout<<t->data<<endl;
        print(t->right);
    }
}

int main()
{
    freopen("data1w.txt","r",stdin);
//    freopen("data1w.txt","r",stdin);
    freopen("output1w.txt","w",stdout);
    int n,t;
    scanf("%d",&n);
    avltree tree;
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        tree.insert(t);
    }
    printf("%.2f\n",(double)clock()/CLOCKS_PER_SEC);
    tree.print();
    return 0;
}