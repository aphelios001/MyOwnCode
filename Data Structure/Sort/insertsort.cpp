#include<bits/stdc++.h>
using namespace std;
void insert_sort(int a[],int n)
{
    //插入排序
    for(int i=1;i<n;i++)//从第2个元素（下标为1）开始比较
    {
        if(a[i]<a[i-1])
        {
            int temp=a[i];//暂存a[i]值，防止后续移动元素时值被覆盖
            int j=i-1;
            while(j>=0&&temp<a[j]) //检查所有前面排好序的元素
            {
                a[j+1]=a[j];//所有大于temp的元素都向后移动
                j--;
            }
            a[j+1]=temp;//复制数据到插入位置，注意j因为在上面被减了1，这里加回来
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
    insert_sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}