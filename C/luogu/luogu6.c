#include<stdio.h>
int main()
{
int k;
int i,ans=0;
int sub1,sub2,sub3;
scanf("%d",&k);
    for(i=10000;i<=30000;i++)
    {
        sub1=i/100;
        sub2=i%10000/10;
        sub3=i%1000;
        if((sub1%k==0)&&(sub2%k==0)&&(sub3%k==0))
        {
            printf("%d\n",i);
            ans=ans+1;
        }
    }
if(ans==0)
printf("No");    
}