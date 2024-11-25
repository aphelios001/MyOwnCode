#include<iostream>
#define Maxsize 10
typedef struct 
{
    int data[Maxsize];
    int front,rear;
    int size;
    int tag;
}Queue;
bool InitQueue(Queue &Q)
{
    Q.front = Q.rear = 0;
    Q.size = 0;
    return true;
}
bool isFull(Queue &Q)
{
    if((Q.rear+1)%Maxsize == Q.front)//Q.size == Maxsize
                                    //or front == rear &&tag==1
    {
        return true;
    }
    return false;
}
bool EnQueue(Queue &Q,int x)
{
    if(isFull(Q))
    {
        return false;
    }
    Q.data[Q.rear]=x;
    Q.rear = (Q.rear+1)%Maxsize;
    Q.size++;
    Q.tag=1;
    return true;
}
bool isEmpty(Queue &Q)
{
    return Q.front == Q.rear;//Q.size == 0 or front == rear && tag == 0

}
bool DeQueue(Queue &Q,int &x)
{
    if(isEmpty(Q))
    {
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front+1)%Maxsize;
    Q.size--;
    Q.tag = 0;
    return true;
}
int GetFront(Queue &Q)
{
    if(isEmpty(Q))
    {
        return -1;
    }
    return Q.data[Q.front];
}
int main()
{
    Queue Q;
    InitQueue(Q);
    EnQueue(Q,1);
    EnQueue(Q,2);
    int x;
    std::cout<<DeQueue(Q,x);
    EnQueue(Q,3);

}