#include<iostream>
typedef struct Lnode
{
    int data;
    Lnode *next;
}Lnode,*LinkedList;
//带头节点的单链表
bool InitList(LinkedList &L)
{
    //L = (LinkedList)malloc(sizeof(Lnode));
    L = new Lnode();
    if(L==nullptr)
    {
        return false;
    }
    else
    {
        L->next = nullptr;
        return true;
    }
}
void CreateListToHead(LinkedList &L,int n)//n是要插入的元素的数量
{
    int x;
    Lnode *newnode;
    for(int i = 0;i<n;i++)
    {
        std::cin>>x;
        newnode = new Lnode();
        newnode->data = x;
        newnode->next = L->next;
        L->next=newnode;
    }
}
void CreateListToTail(LinkedList &L,int n)
{
    int x;
    Lnode *newnode,*tail=L;
    for(int i=0;i<n;i++)
    {
        std::cin>>x;
        newnode = new Lnode();
        newnode->data = x;
        tail->next = newnode;
        tail=newnode;
    }
    tail->next = nullptr;
}
bool InsertElem(LinkedList &L,int i,int e)//带头节点，i是位序，e是待插入的元素
{
    if(i<1)
    {
        return false;
    }
    int j = 0;
    Lnode *current=L;
    
    while(current!=nullptr)
    {
        if(j==i-1)//找到第i-1个节点
        {
            break;
        }
        current=current->next;
        j++;
    }
    if(current==nullptr)
    {
        return false;
    }
    Lnode *newnode = new Lnode();
    newnode->data = e;
    newnode->next = current->next;
    current->next = newnode;
    //可按需改成下列函数
    //InsertNextNode(current,e);
    //InsertPriorNode(current,e);
    return true;
}
Lnode *GetElem(LinkedList &L,int i)
{
    if(i<1)
    {
        return nullptr;
    }
    Lnode *current = L;//头节点是第0个节点
    int j = 0;
    while(current!=NULL)
    {
        if(j==i)//找到第i个节点就停下来
        {
            break;
        }
        current = current->next;
        j++;
    }
    return current;
}
Lnode *LocateElem(LinkedList &L,int e)
{
    Lnode *current = L;
    while(current!=nullptr)
    {
        if(current->data==e)
        {
            break;
        }
        current = current->next;
    }
    return current;
}
bool InsertPriorNode(Lnode *p,int e)
{
    if(p==nullptr)
    {
        return false;
    }
    Lnode *newnode = new Lnode();
    if(newnode==nullptr)
    {
        return false;
    }
    newnode->next = p->next;
    p->next = newnode;
    newnode->data = p->data;
    p->data = e;
    return true;

}
bool InsertNextNode(Lnode *p,int e)
{
    if(p==nullptr)
    {
        return false;
    }
    Lnode *newnode = new Lnode();
    if(newnode==nullptr)
    {
        return false;
    }
    newnode->data = e;
    newnode->next = p->next;
    p->next = newnode;
    return true;
}
bool DeleteNode(Lnode *p)
{
    if(p==nullptr)
    {
        return false;
    }
    Lnode *t = p->next;
    p->data = p->next->data;
    p->next = t->next;
    free(t);
    return true;
}
void PrintList(LinkedList &L)
{
    Lnode *current = L->next;
    while(current!=nullptr)
    {
        std::cout<<current->data<<' ';
        current = current->next;
    }

}
int main()
{
    LinkedList L;
    int n;
    std::cin>>n;
    InitList(L);
    CreateListToHead(L,n);
    DeleteNode(GetElem(L,1));
    InsertElem(L,2,10);
    PrintList(L);
    return 0;
}