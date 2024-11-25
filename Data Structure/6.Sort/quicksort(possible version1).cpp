#include<iostream>
using namespace std;
#define maxn 100000
int a[maxn];
int n;
void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int x = a[(low+high)/2];
        int i = low-1;
        int j = high+1;
        while(i<j)
        {
            while(a[++i]<x);//直到a[i]>=x;
            while(a[--j]>x);//直到a[j]<=x;  
            if(i<j)
            {
                swap(a[i],a[j]);
            }
        }
        quicksort(a,low,j);
        quicksort(a,j+1,high);
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}