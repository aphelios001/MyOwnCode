#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int low,int high)
{
    int pivot=a[low];
    while(low<high)
    {
        while(low<high&&a[high]>=pivot)
        {
            --high;
        }
        a[low]=a[high];
        while(low<high&&a[low]<=pivot)
        {
            ++low;
        }
        a[high]=a[low];
    }
    a[low]=pivot;
    return low;
}
void qsort(int a[],int low,int high)
{
    if(low<high)
    {
        int ploc=partition(a,low,high);
        qsort(a,low,ploc-1);
        qsort(a,ploc+1,high);
    }
}
void quick_sort(int a[],int n)
{
    qsort(a,0,n-1);
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
    quick_sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}