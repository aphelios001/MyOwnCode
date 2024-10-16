#include<bits/stdc++.h>
using namespace std;
long long quickpow(int a,int n)
{
    long long ans=1;
    while(n>0)
    {
        if(n&1==1)//即if(n%2==1),如果为奇数,则
        {
            ans=ans*a;
        }
        a=a*a;
        n=n>>1;
    }
    return ans;
}
int main()
{
    int a,n;
    cin>>a>>n;
    long long ans = quickpow(a,n);
    cout<<ans<<endl;
}