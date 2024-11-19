#include<iostream>
using namespace std;
const int N = 100100;
int element[N],nxt[N],index,head;
void Add(int x)
{
    element[index]=x;
    nxt[index]=head;
    head = index;
    index++;
}
void Delete(int k)
{
    
}
void Insert(int k, int x) 
{
}
void Print()
{
    for(int i=head;i!=-1;i=nxt[i])
    {
        cout<<element[i]<<" ";
    }
    cout<<endl;
}
int main() 
{
    index = 0;
    head = -1;
    int m;
    cin>>m;
    for(int i=0;i<m;i++) 
    {
        char command;
        int x,k;
        cin>>command;
        switch(command)
        {
            case 'H':cin>>x;Add(x);break;
            case 'D':
            cin>>k;
            if(k==0)
            {
                head = nxt[head];
            }
            else 
            {
                Delete(k-1);
            }
            break;
            case 'I':cin>>k>>x;Insert(k-1,x);break;
            default:break;
        }
    }
    Print();
}
