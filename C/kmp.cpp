#include<iostream>
using namespace std;
string s1;
string s2;
int prefix[100005];
void getnext()
{
    int j=-1;
    int i=0;
    prefix[0]=-1;
    while(i<s2.length()-1)
    {
        if(j==-1||s2[i]==s2[j])
        {
            i++;
            j++;
            prefix[1]=j;
        }
    }
}
int main()
{
    cin>>s1;
    cin>>s2;
    
}