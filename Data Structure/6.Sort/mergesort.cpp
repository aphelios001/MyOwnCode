#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int temp[],int left,int mid,int right)
{
    int l=left;
    int r=mid+1;
    int current=left;
    while(l<=mid&&r<=right)
    {
        if(a[l]<a[r])
        {
            temp[current]=a[l];
            current++;
            l++;
        }
        else
        {
            temp[current]=a[r];
            current++;
            r++;
        }
    }
    while(l<=mid)
    {
        temp[current]=a[l];
        current++;
        l++;
    }
    while(r<=right)
    {
        temp[current]=a[r];
        current++;
        r++;
    }
    for(int i=left;i<=right;i++)
    {
        a[i]=temp[i];
    }
}
void msort(int a[],int temp[],int left,int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        msort(a,temp,left,mid);
        msort(a,temp,mid+1,right);
        merge(a,temp,left,mid,right);
    }
}
void merge_sort(int a[],int n)
{
    int *temp=new int[n];
    if(temp)
    {
        msort(a,temp,0,n-1);
    }
    else
    {
        cout<<"内存不足!"<<endl;
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
    merge_sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}