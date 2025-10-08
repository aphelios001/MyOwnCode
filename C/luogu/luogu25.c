#include<stdio.h>
int main()
{
    int a0=0,a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,a9=0;
    int M,N;
    scanf("%d %d",&M,&N);
    int temp;
    int t;
    for(int i=M;i<=N;i++)
    {
        temp=i;
        while(temp!=0)
        {
            t=temp%10;
            temp=temp/10;
            if(t==0)
            {
                a0++;
            }
            else if(t==1)
            {
                a1++;
            }
            else if(t==2)
            {
                a2++;
            }
            else if(t==3)
            {
                a3++;
            }
            else if(t==4)
            {
                a4++;
            }
            else if(t==5)
            {
                a5++;
            }
            else if(t==6)
            {
                a6++;
            }
            else if(t==7)
            {
                a7++;
            }
            else if(t==8)
            {
                a8++;
            }
            else if(t==9)
            {
                a9++;
            }
        }
    }
    printf("%d %d %d %d %d %d %d %d %d %d",a0,a1,a2,a3,a4,a5,a6,a7,a8,a9);  
}