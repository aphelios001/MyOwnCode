#include<bits/stdc++.h>
using namespace std;
unsigned long long a,b;
int a1[1000];
int b1[1000];
int c1[1000];
string s1;
string s2;
void plus()
{
    cin>>s1>>s2;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    for(int i=0;i<s1.length();i++)
    {
        a1[i]=s1[i]-'0';
    }
    for(int i=0;i<s2.length();i++)
    {
        b1[i]=s2[i]-'0';
    }
    int len=max(s1.length(),s2.length());
    for(int i=0;i<len;i++)
    {
        c1[i]=a1[i]+b1[i];
    }
    for(int i=0;i<len;i++)
    {
        if(c1[i]>=10)
        {
            c1[i+1]=c1[i+1]+c1[i]/10;
            c1[i]=c1[i]%10;
        }
    }
    if(c1[len]!=0)
    {
        len++;
    }
    for(int i=len-1;i>=0;i--)
    {
        cout<<c1[i];
    }
}
void sub()
{
    cin>>s1>>s2;
    int flag=1;
    if(s1.length()==s2.length())
    {
        if(s2>s1)
        {
            swap(s1,s2);
            flag=0;
        }
    }
    else if(s1.length()<s2.length())
    {
        swap(s1,s2);
        flag=0;
    }
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    for(int i=0;i<s1.length();i++)
    {
        a1[i]=s1[i]-'0';
    }
    for(int i=0;i<s2.length();i++)
    {
        b1[i]=s2[i]-'0';
    }
    int len=max(s1.length(),s2.length());
    for(int i=0;i<len;i++)
    {
        if(a1[i]<b1[i])
        {
            a1[i]=a1[i]+10;
            a1[i+1]=a1[i+1]-1;
        }
        c1[i]=a1[i]-b1[i];
    }
    if(flag==0)
    {
        cout<<'-';
    }
    int index=0;
    for(int i=s1.length()-1;i>=0;i--)
    {
        if(c1[i]!=0)
        {
            index=i;
            break;
        }
    }
    for(int i=index;i>=0;i--)
    {
        cout<<c1[i];
    }
}
void multiply()
{
    cin>>s1>>s2;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    if(s2.length()>s1.length())
    {
        swap(s1,s2);
    }
    for(int i=0;i<s1.length();i++)
    {
        a1[i]=s1[i]-'0';
    }
    for(int i=0;i<s2.length();i++)
    {
        b1[i]=s2[i]-'0';
    }
    int len=s1.length()+s2.length();
    for(int i=0;i<s1.length();i++)
    {
        for(int j=0;j<s2.length();j++)
        {
            c1[i+j]+=a1[i]*b1[j];
            c1[i+j+1]+=c1[i+j]/10;
            c1[i+j]=c1[i+j]%10;
        }
    }
    if(c1[len]==0&&len>0)
    {
        len--;
    }
    for(int i=len-1;i>=0;i--)
    {
        cout<<c1[i];
    }

}
int main()
{
    multiply();
}
