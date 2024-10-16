#include<bits/stdc++.h>
using namespace std;
#define maxn 500
string sa;
string sb;
int a[maxn],b[maxn];
int res[2*maxn];
void highaccuratemultiply()
{
    for(int i=0;i<sa.length();i++)
    {
        for(int j=0;j<sb.length();j++)
        {
            res[i+j]+=a[i]*b[j];
            res[i+j+1]+=res[i+j]/10;
            res[i+j]%=10;
        }
    }
} 
int main()
{
    cin>>sa>>sb;
    for(int i=0;i<sa.length();i++)
    {
        a[i]=sa[sa.length()-1-i]-'0';
    }
    for(int i=0;i<sb.length();i++)
    {
        b[i]=sb[sb.length()-1-i]-'0';
    }
    int len=sa.length()+sb.length();
    highaccuratemultiply();
    while(res[len]==0 && len>0)
    {
        len--;
    }
    for(int i=len;i>=0;i--)
    {
        cout<<res[i];
    }
    return 0;
}