#include<bits/stdc++.h>
using namespace std;
typedef struct AVLnode
{
    int depth;
    AVLnode*lchild;
    AVLnode*rchild;
    AVLnode*parent;
    int value;
}AVLtree,Tree;

Tree* init(int value)
{
    Tree*root=new Tree();
    root->parent=NULL;
    root->depth=0;
    root->lchild=root->rchild=NULL;
    root->value=value;
    return root;
}

//左旋
//(1)root节点的右孩子替代此节点位置 (2)root右孩子的左子树变为该节点的右子树 (3)root节点本身变为右孩子的左子树
//冲突的左孩变右孩
Tree* RR_rotate(Tree*root)
{
    Tree*temp;
    temp=root->rchild;
    root->rchild=temp->lchild;
    temp->lchild=root;
    return temp;
}

//右旋
//（1）root节点的左孩子代表此节点 （2）root节点的左孩子的右子树变为节点的左子树 （3）root将此节点作为左孩子节点的右子树
//冲突的右孩变左孩
Tree* LL_rotate(Tree*root)
{
    Tree*temp;
    temp=root->lchild;
    root->lchild=temp->rchild;//root节点的左孩子的右子树变为节点的左子树
    temp->rchild=root;
    return temp;
}

//左旋左孩子，然后右旋
Tree* LR_rotate(Tree*root)
{
    Tree*temp;
    temp=root->lchild;
    root->lchild=RR_rotate(temp);
    return LL_rotate(root);
}
//右旋右孩子，然后左旋
Tree* RL_rotate(Tree*root)
{
    Tree*temp;  
    temp=root->rchild;
    root->rchild=LL_rotate(temp);
    return RR_rotate(root);
}

//获取左/右子树的高
int getheight(Tree*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int max=0;
    int left=getheight(root->lchild);
    int right=getheight(root->rchild);
    if(left>right)
    {
        max=left;
    }
    else
    {
        max=right;
    }
    return max+1;
}
//平衡因子，即当前节点左、右子树高度的差
int diff(Tree*root)
{
    return getheight(root->lchild)-getheight(root->rchild);
}
Tree*balance(Tree*root)
{
    int factor=diff(root);
    if(factor>1)//L_的情况
    {
        if(diff(root->lchild)>0)//LL
        {
            root=LL_rotate(root);
        }
        else//LR
        {
            root=LR_rotate(root);
        }
    }
    else if(factor<-1)//R_的情况
    {
        if(diff(root->rchild)>0)//RL
        {
            root=RL_rotate(root);
        }
        else//RR
        {
            root=RR_rotate(root);
        }
    }
    return root;
}
Tree* BSTinsert(Tree*root,int value)
{
    if(root == NULL)
    {
        root = init(value);
    }
    else if(value < root->value)
    {
        root->lchild=BSTinsert(root->lchild,value);
    }
    else if(value > root->value)
    {
        root->rchild=BSTinsert(root->rchild,value);
    }
    return root;
}
Tree* insert(Tree*root,int value)
{
    if(root == NULL)
    {
        root = init(value);
        return root;
    }
    else if(value < root->value)
    {
        root->lchild=insert(root->lchild,value);
        root = balance(root);
    }
    else if(value > root->value)
    {
        root->rchild=insert(root->rchild,value);
        root = balance(root);
    }
    return root;
}

int getSearchCount(Tree* T, int data) 
{
    int searchCount = 0;
    while (T) 
    {
        searchCount++;
        if (T->value > data)
            T = T->lchild;
        else if (T->value < data)
            T = T->rchild;
        else
            break;
    }
    return searchCount;
}
int main()
{   
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    Tree*AVLroot=NULL;
    Tree*BSTroot=NULL;
    for(int i=0;i<n;i++)
    {
        AVLroot = insert(AVLroot,a[i]);
        BSTroot = BSTinsert(BSTroot,a[i]);
    }
    int avlsum = 0;
    int bstsum = 0;
    for(int i=0;i<n;i++)
    {
        avlsum += getSearchCount(AVLroot,a[i]);
        bstsum += getSearchCount(BSTroot,a[i]);
    }
    cout<<bstsum<<'\n'<<avlsum<<endl;
    return 0;
} 
