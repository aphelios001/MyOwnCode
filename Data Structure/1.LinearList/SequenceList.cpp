#include<iostream>
#define InitSize 10
typedef struct
{
    int *data;
    int length;
    int MaxSize;
}SeqList;
void InitList(SeqList &L)
{
    L.data = new int[InitSize];
    L.length = 0;
    L.MaxSize = InitSize;
}
void ExpandList(SeqList &L,int size)
{
    int *temp = L.data;
    L.data = new int[L.MaxSize+size];
    for(int i = 0;i < L.length;i++)
    {
        L.data[i] = temp[i];
    }
    L.MaxSize += size;
    delete[] temp;
}
bool InsertElem(SeqList &L,int i,int e)
{
    if(i<1||i>L.length+1)
    {
        return false;
    }
    if(L.length>=L.MaxSize)
    {
        return false;//也可ExpandList
    }
    
    for(int j = L.length-1;j>=i;j--)
    {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}
int GetElem(SeqList &L,int i)
{
    if(i<1||i>L.length)
    {
        return -1;
    }
    return L.data[i-1];
}
bool DeleteElem(SeqList &L,int i,int &e)
{
    if(i<1||i>L.length)
    {
        return false;
    }
    e = GetElem(L,i);

    for(int j=i;j<L.length;j++)
    {
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;

}

int LocateElem(SeqList &L,int e)
{
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i]==e)
        {
            return i+1;
        }
    }
    return -1;
}
void PrintList(SeqList &L)
{
    for(int i=0;i<L.length;i++)
    {
        printf("%d ",L.data[i]);
    }
    printf("\n");
}
int main()
{
    SeqList L;
    InitList(L);
    InsertElem(L,1,1);
    InsertElem(L,2,2);
    ExpandList(L,10);
    std::cout<<GetElem(L,2)<<' '<<LocateElem(L,1)<<std::endl;
    int e = -1;
    std::cout<<DeleteElem(L,1,e)<<std::endl;
    PrintList(L);
    return 0;
}
