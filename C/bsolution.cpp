#include<bits/stdc++.h>
using namespace std;
int L,N,M;
int a[100005];
bool check(int x)//二分枚举X，假设最短跳跃距离（最小值）(答案)为X，如果两个石头之间的距离小于X，因为最短距离就是X，不可能比X更短，就把石头移除，石头移除数量加一
//在这个答案下，统计移除石头的数量，如果移除的石头数量大于M，则不是答案（非法），如果数量小于等于M，则为答案（合法）
{
    int i=0;
    int now=0;
    int cnt=0;
    while(i!=N+1)
    {
        i++;
        if(a[i]-a[now]<x)
        {
            cnt++;
        }
        else
        {
            now=i;
        }
    }
    if(cnt>M)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    cin>>L>>N>>M;
    for(int i=1;i<=N;i++)
    {
        cin>>a[i];
    }
    a[N+1]=L;
    int l=0,r=L+1;
    while(l+1<r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    cout<<l;//最小值的最大值，即合法答案的最大值
}