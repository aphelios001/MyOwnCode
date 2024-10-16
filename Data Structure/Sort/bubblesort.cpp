#include<bits/stdc++.h>
using namespace std;
void bubble_sort(int a[],int n)
{
    //冒泡排序：分别比较相邻的两个数
    for(int i=0;i<n-1;i++)//因为n个数据只需要将最大的n-1个数排到最后就行了
    {
        for(int j=0;j<n-1-i;j++)//因为一次循环后就会有一个最大的数到达正确位置，所以只循环n-1-i次
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
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
    bubble_sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<' ';
    }
}