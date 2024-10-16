#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int n,int i)
{
    int largest=i;
    int lson=i*2+1;
    int rson=i*2+2;

    if(lson<n&&a[largest]<a[lson])
    {
        largest=lson;
    }
    if(rson<n&&a[largest]<a[rson])
    {
        largest=rson;
    }
    if(largest!=i)
    {
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }
}
//下标为i节点的根节点的下标是(i-1)/2
void heap_sort(int a[],int n)
{
    //建堆
    for(int i=(n-1-1)/2;i>=0;i--)
    {
        heapify(a,n,i);
    }
    //排序
    for(int i=n-1;i>0;i--)
    {
        swap(a[i],a[0]);
        heapify(a,i,0);
    }
}
int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    heap_sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}