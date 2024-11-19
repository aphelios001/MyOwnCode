#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector <int> a;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        a.push_back(t);
    }
    int length=0;
    int maxlength=0;
    int start=0,end=0,stemp=0;
    for(int i=0;i<n-1;i++)
    {
        length++;
        if(length>maxlength)//如果当前子序列的长度比已经记录的最长子序列的长度长，使用两个指针start和end来记录当前找到的最长递增子序列的起始和结束位置
        {
            maxlength=length;
            start=stemp;
            end=i;
        }
        if(a[i]>=a[i+1])//递增子序列结束，重置length和stemp;
        {
            length=0;
            stemp=i+1;
        }
    }
    for(int i=start;i<=end;i++)
    {
        cout<<a[i];
        if(i<end)
        {
            cout<<' ';
        }
    }
    cout<<endl;
    cout<<maxlength;
}