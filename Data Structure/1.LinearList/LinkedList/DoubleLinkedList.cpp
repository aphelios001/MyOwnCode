#include<iostream>
typedef struct Dnode
{
    int data;
    Dnode *next;
    Dnode *prior;
}*LinkedList;
bool InitList(LinkedList &L)
{
    L = new Dnode();
    if(L==nullptr)
    {
        return false;
    }
    L->next = nullptr;
    L->prior = nullptr;
    return true;
}
bool InsertNextNode(Dnode *p,Dnode *s)
{
    if(p==nullptr||s==nullptr)
    {
        return false;
    }
    s->next = p->next;
    if(p->next!=nullptr)
    {
        p->next->prior = s;
    }
    p->next = s;
    s->prior = p;
    return true;
}
bool DeleteNextNode(Dnode *p)
{
    if(p==nullptr)
    {
        return false;
    }
    Dnode *q = p->next;
    if(q==nullptr)
    {
        return false;
    }
    p->next = q->next;
    if(q->next!=nullptr)
        q->next->prior = p;
    delete q;
    return true;
}
void DestoryList(LinkedList &L)
{
    while(L->next !=nullptr)
    {
        DeleteNextNode(L);
    }
    delete L;
    L=nullptr;
}

