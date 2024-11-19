#include<bits/stdc++.h>
using namespace std;
//基数排序
int getmaxbit(int a[],int n)
{
    int digit=1;
    int p=10;
    for(int i=0;i<n;i++)
    {
        while(a[i]>=p)
        {
            p*=10;
            digit++;
        }
    }
    return digit;
}
void radix_sort(int a[],int n)
{
    int digit=getmaxbit(a,n);//获取最大位数
    vector<int> temp(n);//临时数组
    vector<int> count(10);//统计数组，统计某一位数字相同的个数
    vector<int> start(10);//起始索引数组，某一位数字相同数字的第一个的位置

    int radix=1;
    while(digit--)//最大位数为几就进行几次
    {
        //清空
        for(int i=0;i<10;i++)
        {
            count[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            int index=a[i]/radix %10;//获取当前位数的值

            count[index]++;//计有当前位数的值的数有几个
        }

        //清空
        for(int i=0;i<10;i++)
        {
            start[i]=0;
        }
        for(int i=1;i<10;i++)
        {
            start[i]=count[i-1]+start[i-1];
            //较难理解，类似于前缀和（不过是从1开始的，这样才对的上temp的下标（下标从0开始）），
            //start数组存放的数可以理解为个(十、百)位数为i的数放在temp数组的第几个位置
        }

        //清空
        for(int i=0;i<n;i++)
        {
            temp[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            int index=a[i]/radix %10;//获取当前位数的值

            temp[start[index]]=a[i];//按顺序，将原数组的元素，放到temp数组对应的位置上

            start[index]++;
            //如果有多个数的个(十、百)位数的值为1（举例），
            //此操作可以让原数组中个（十、百）位数为1的元素，按照原数组的顺序在temp数组中排列
        }

        for(int i=0;i<n;i++)
        {
            a[i]=temp[i];//temp数组的值赋值给原数组
        }

        radix*=10;//(个位->十位->百位->...)       
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
    radix_sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}