#include<iostream>
#define Maxsize 10
typedef struct 
{
    int data[Maxsize];
    int top;
}Stack;
bool InitStack(Stack &S)
{
    S.top = -1;// or S.top = 0;
    return true;
}
bool isFull(Stack &S)
{
    if(S.top == Maxsize-1)
    {
        return true;
    }
    return false;
}
bool isEmpty(Stack &S)
{
    if(S.top == -1)
    {
        return true;
    }
    return false;
}
bool Push(Stack &S,int x)
{
    if(isFull(S))
    {
        return false;
    }
    S.top++;
    S.data[S.top]=x;
    return true;
}
bool Pop(Stack &S,int &x)
{
    if(isEmpty(S))
    {
        return false;
    }
    x = S.data[S.top];
    S.top--;
    return true;
}
int GetTop(Stack &S)
{
    if(isEmpty(S))
    {
        return -1;
    }
    return S.data[S.top];
}
bool DestoryStack(Stack &S) 
{
    S.top = -1;
    return true;
}
int main()
{
    Stack S;
    InitStack(S);
    Push(S,1);
    Push(S,100);
    int x = 0;
    Pop(S,x);
    std::cout<<x<<std::endl;
    std::cout<<GetTop(S)<<std::endl;
    return 0;
}
