#include<bits/stdc++.h>
using namespace std;
//归并排序（非递归）
/*
将一个数组 ，通过gap分为几组进行合并，gap每次扩大2倍,gap<n
合并方式与递归相同
第一个数组的 begin1 改为 i
第一个数组的 end1 改为 i+gap-1
第二个数组 的 begin2改为 i+gap
第二个数组的 end2 改为 i+2*gap-1
*/
void merge(int a[],int temp[],int left,int mid,int right)//合并函数不变
{
    int l_pos=left;
    int r_pos=mid+1;
    int current=left;
    while(l_pos<=mid&&r_pos<=right)
    {
        if(a[l_pos]<a[r_pos])
        {
            temp[current++]=a[l_pos++];
        }
        else
        {
            temp[current++]=a[r_pos++];
        }
    }
    while(l_pos<=mid)
    {
        temp[current++]=a[l_pos++];
    }
    while(r_pos<=right)
    {
        temp[current++]=a[r_pos++];
    }
    while(left<=right)
    {
        a[left]=temp[left];
        left++;
    }
}
void msort(int a[],int temp[],int n,int gap)
{
    for(int i=0;i<n;i+=2*gap)
    {
        int left=i;
        int mid=i+gap-1;
        int r_pos=i+gap;
        int right=i+2*gap-1;
        
        //防止越界
        //右半区间不存在，这个时候前面都排完了，然后左半区间本来就是有序的，所以进行下一轮即可
        if(r_pos>=n)
        {
            break;
        }
        //左半区间八个值，但是右半区间值少于八个
        if(right>=n)
        {
            right=n-1;
        }
        //左半区间不够gap个，这个不够gap区间的内容本来就是有序的，所以不用拷回去，直接拷贝到前一个right的内容就可以
		//必须要是拷贝到right,因为上面几行right可能被修正过，右半区间少了，不能拷贝到i+2*gap-1的内容
        merge(a,temp,left,mid,right);
    }
}
void merge_sortNoR(int a[],int n)
{
    int *temp=new int[n];
    if(!temp)
    {
        cout<<"内存不足!"<<endl;
        exit(-1);
    }

    int gap=1;//gap表示每一次归并，一组数据的数据个数
    while(gap < n)
    {
        msort(a,temp,n,gap);
        gap*=2;
    }
    delete temp;
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
    merge_sortNoR(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}