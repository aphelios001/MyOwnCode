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
    if(left>=right)
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
Tree* insert(Tree*root,int value)
{
    if(root == NULL)
    {
        root = init(value);
        if(root==NULL)
        {
            cout<<"Fail to create!"<<endl;
        }
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
void displaytree_mid(Tree*node)
{
    if(node==NULL)
    {
        return;
    }
    if(node->lchild!=NULL)
    {
        displaytree_mid(node->lchild);
    }
    cout<<node->value<<' ';
    if(node->rchild!=NULL)
    {
        displaytree_mid(node->rchild);
    }
}
Tree*binarytree_search(Tree*node,int value)
{
    if(node->value==value)
    {
        return node;
    }
    else if(value>node->value)
    {
        if(node->rchild!=NULL)
        {
            return binarytree_search(node->rchild,value);
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        if(node->lchild!=NULL)
        {
            return binarytree_search(node->lchild,value);
        }
        else
        {
            return NULL;
        }
    }
}
int treemax(Tree*node)
{
    int value;
    value=node->value;
    if(node->rchild!=NULL)
    {
        return treemax(node->rchild);
    }
    else
    {
        return value;
    }
}
int treemin(Tree*node)
{
    int value;
    value=node->value;
    if(node->lchild!=NULL)
    {
        return treemin(node->lchild);
    }
    else
    {
        return value;
    }
}

Tree*deletenode(Tree*root,const int value)
{
    if(root==NULL)
    {
        return root;
    }
    if(!binarytree_search(root,value))
    {
        cout<<"未找到此值"<<endl;
        return root;
    }
    if(value==root->value)
    {
        if(root->lchild!=NULL&&root->rchild!=NULL)
        {
            if(diff(root)>0)
            {
                root->value=treemax(root->lchild);
                root->lchild = deletenode(root->lchild,root->value);
            }
            else
            {
                root->value=treemin(root->rchild);
                root->rchild=deletenode(root->rchild,root->value);
            }
        }
        else
        {
            Tree*temp=root;
            if(root->lchild)
            {
                root=root->lchild;
            }
            else
            {
                root=root->rchild;
            }
            delete temp;
            temp=NULL;
        }
    }
    else if(value<root->value)
    {
        root->lchild=deletenode(root->lchild,value);
        if(diff(root)<-1)
        {
            if(diff(root->rchild)>0)
            {
                root=RL_rotate(root);
            }
            else
            {
                root=RR_rotate(root);
            }
        }
    }
    else
    {
        root->rchild=deletenode(root->rchild,value);
        if(diff(root)>1)
        {
            if(diff(root->lchild)<0)
            {
                root=LR_rotate(root);
            }
            else
            {
                root=LL_rotate(root);
            }
        }
    }
    return root;
}
int main()
{   
    int n;
    cout<<"请输入数组长度:"<<endl;
    cin>>n;
    int *a=new int[n];
    cout<<"请输入数组元素:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    Tree*root=NULL;
    for(int i=0;i<n;i++)
    {
        root = insert(root,a[i]);
    }

    cout<<"AVL树的中序遍历结果:"<<endl;
    displaytree_mid(root);
    cout<<endl;

    int value;
    cout<<"请输入要查找的值:"<<endl;
    cin>>value;
    Tree*temp=binarytree_search(root,value);
    if(temp==NULL)
    {
        cout<<"AVL树中不存在"<<value<<endl;
    }
    else
    {
        cout<<"AVL树中存在"<<value<<endl;
    }
    int del;
    cout<<"请输入要删除值:"<<endl;
    cin>>del;
    if(!binarytree_search(root,del))
    {
        cout<<"该值不存在"<<endl;
    }
    else
    {
        deletenode(root,del);
    }
    cout<<"AVL树的中序遍历结果:"<<endl;
    displaytree_mid(root);
    cout<<endl;
    return 0;
} 
