#include<iostream>
typedef struct Snode
{
    int data;
    Snode *next;
}*Stack;
bool InitStack(Stack &S)
{
    S = nullptr;
    return true;
}
bool Push(Stack &S,int x)
{
    if(S == nullptr)
    {
        S = new Snode();
        if(S==nullptr)
        {
            return false;
        }
        S->data = x;
        S->next = nullptr;
    }
    else
    {
        Snode *newnode = new Snode();
        if(newnode == nullptr)
        {
            return false;
        }
        newnode->data = x;
        newnode->next = S;
        S=newnode;
    }
    return true;
}
bool Pop(Stack &S,int &x)
{
    if(S==nullptr)
    {
        return false;
    }
    Snode *t = S;
    x = t->data;
    S=S->next;
    delete t;
    return true;
}
int GetTop(Stack &S)
{
    if(S==nullptr)
    {
        return -1;
    }
    return S->data;
}
int main()
{
    Stack S;
    int d;
    InitStack(S);
    Push(S,2);
    Pop(S,d);
    Push(S,7);
    Push(S,100);
    Pop(S,d);
    std::cout<<d<<std::endl;
    std::cout<<GetTop(S)<<std::endl;
    return 0;
}

