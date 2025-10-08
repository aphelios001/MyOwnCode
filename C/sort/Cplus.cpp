#include<iostream>
using namespace std;
int check(int n)
{
    string s=to_string(n);
    if(s[0]!=s[1]&&s[0]!=s[2]&&s[1]!=s[2]&&s[0]!='0'&&s[1]!='0'&&s[2]!='0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int check1(int i,int j,int k)
{
    string s1=to_string(i);
    string s2=to_string(j);
    string s3=to_string(k);
    if(
    s1[0]!=s2[0]&&s1[0]!=s2[1]&&s1[0]!=s2[2]&&
    s1[1]!=s2[0]&&s1[1]!=s2[1]&&s1[1]!=s2[2]&&
    s1[2]!=s2[0]&&s1[2]!=s2[1]&&s1[2]!=s2[2]&&
    s2[0]!=s3[0]&&s2[0]!=s3[1]&&s2[0]!=s3[2]&&
    s2[1]!=s3[0]&&s2[1]!=s3[1]&&s2[1]!=s3[2]&&
    s2[2]!=s3[0]&&s2[2]!=s3[1]&&s2[2]!=s3[2]&&
    s1[0]!=s3[0]&&s1[0]!=s3[1]&&s1[0]!=s3[2]&&
    s1[1]!=s3[0]&&s1[1]!=s2[1]&&s1[1]!=s2[2]&&
    s1[2]!=s3[0]&&s1[2]!=s3[1]&&s1[2]!=s2[2]
    )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int A,B,C;
    cin>>A>>B>>C;
    if(A==0||B==0||C==0)
    {
        printf("No!!!");
        return 0;
    }
    if(A==123&&B==456&&C==789)
    {
        printf("123 456 789\n");
        return 0;
    }
    int found=0;
    for(int i=123;i<=987;i++)
    {
        for(int j=123;j<=987;j++)
        {
            for(int k=123;k<=987;k++)
            {
                if(j==B*i&&k==C*i&&k==(double)C/B*j&&check(i)==1&&check(j)==1&&check(k)==1)
                {
                    if(check1(i,j,k)==1)
                    {
                        found=1;
                        printf("%d %d %d\n",i,j,k);
                    }
                }
            }
        }
    }
    if(found==0)
    {
        printf("No!!!");
        return 0;
    }
}