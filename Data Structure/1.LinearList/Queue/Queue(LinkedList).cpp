#include<iostream>
typedef struct Qnode
{
    int data;
    Qnode *next;
}Qnode;
typedef struct
{
    Qnode *front,*rear;
}Queue;
bool InitQueue(Queue &Q)
{
    Q.front = Q.rear = new Qnode();
    Q.front->next=nullptr;
}
bool isEmpty(Queue &Q)
{
    return Q.front == Q.rear;
}
bool EnQueue(Queue &Q,int x)
{
    Qnode *s = new Qnode();
    s->data = x;
    s->next = nullptr;
    Q.rear->next = s;
    Q.rear = s;
    return true;
}
bool DeQueue(Queue &Q,int &x)
{
    if(isEmpty(Q))
    {
        return false;
    }
    Qnode *p = Q.front->next;
    x=p->data;
    Q.front->next = p->next;
    if(Q.rear==p)
    {
        Q.rear = Q.front;
    }
    delete p;
    return true;
}