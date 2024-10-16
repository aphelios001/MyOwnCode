#include<bits/stdc++.h>
using namespace std;
void select_sort(int a[],int n)
{
    for(int i=0;i<n-1;i++)//选择排序：固定一个数，和别的数都比较一次
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                swap(a[i],a[j]);
            }
        }
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
    select_sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}