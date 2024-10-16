#include<bits/stdc++.h>
using namespace std;
void shell_sort(int a[],int n)
{
    //希尔排序，插入排序外套一层循环，增量由1改为D即可，D=n/2。
    for(int D=n/2;D>=1;D=D/2)
    {
        for(int i=D;i<n;i++)//从第D+1个元素（下标为D）开始比较
        {
            if(a[i]<a[i-D])
            {
                int temp=a[i];//暂存a[i]值，防止后续移动元素时值被覆盖
                int j=i-D;
                while(j>=0&&temp<a[j]) //检查所有前面排好序的元素
                {
                    a[j+D]=a[j];//所有大于temp的元素都向后移动
                    j-=D;
                }
                a[j+D]=temp;//复制数据到插入位置，注意j因为在上面被减了D，这里加回来
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
    shell_sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}