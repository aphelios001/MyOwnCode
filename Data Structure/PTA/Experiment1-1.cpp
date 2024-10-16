#include<bits/stdc++.h>
using namespace std;
#define ElementType int
#define MAXSIZE 10000
struct SequentialList
{
    ElementType Data[MAXSIZE]={};
    int length=0;
    
};
void Insert(SequentialList *L,int x,int pos)
{   
    if(pos<=0||pos>L->length+1)
    {
        return;
    }
    if(L->length==MAXSIZE-1)
    {
        return;
    }
    for(int i=L->length;i>=pos;i--)
    {
        L->Data[i]=L->Data[i-1];
    }
    L->Data[pos-1]=x;
    L->length++;
}
void Delete(SequentialList *L,int pos)
{
    if(pos<=0||pos>L->length)
    {
        return;
    }
    for(int i=pos-1;i<L->length;i++)
    {
        L->Data[i]=L->Data[i+1];
    }
    L->length--;
}
int Find(SequentialList *L,int x)
{
    for(int i=0;i<L->length;i++)
    {
        if(L->Data[i]==x)
        {
            return i;
        }
    }
    return -1;
}
void Print(SequentialList *L)
{
    for(int i=0;i<L->length;i++)
    {
        cout<<L->Data[i];
        if(i<L->length-1)
        {
            cout<<' ';            
        }
    }
}   
int main()
{
    SequentialList SeqList;
    int n;
    cin>>n;
    int res=-1;
    while(n--)
    {   
        int command;
        cin>>command;
        int pos;
        if(command==1)
        {
            int x;
            cin>>x>>pos;
            Insert(&SeqList,x,pos);
        }
        else if(command==2)
        {
            cin>>pos;
            Delete(&SeqList,pos);
        } 
        else if(command==3)
        {
            int x;
            cin>>x;
            res=Find(&SeqList,x);
        }

    }
    cout<<res<<endl;
    Print(&SeqList);
}