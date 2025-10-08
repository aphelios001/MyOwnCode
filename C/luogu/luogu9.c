#include<stdio.h>
int main()
{
    int L,R;
    scanf("%d %d",&L,&R);
    int a[7];
    int count=0;
    for(int i=L;i<=R;i++)
    {
        if(i<10)
        {
            a[1]=i/1%10;
            for(int j=1;j<=1;j++)
            {
                if(a[j]==2)
                {
                    count++;
                }
            }
        }
        else if(i>=10&&i<100)
        {
            a[1]=i/10%10;
            a[2]=i/1%10;
            for(int j=1;j<=2;j++)
            {
                if(a[j]==2)
                {
                    count++;
                }
            }
        }
        else if(i>=100&&i<1000)
        {
            a[1]=i/100%10;
            a[2]=i/10%10;
            a[3]=i/1%10;
            for(int j=1;j<=3;j++)
            {
                if(a[j]==2)
                {
                    count++;
                }
            }
        }
        else if(i>=1000&&i<10000)
        {
            a[1]=i/1000%10;
            a[2]=i/100%10;
            a[3]=i/10%10;
            a[4]=i/1%10;
            for(int j=1;j<=4;j++)
            {
                if(a[j]==2)
                {
                    count++;
                }
            }
        }
        else if(i>=10000&&i<100000)
        {
            a[1]=i/10000%10;
            a[2]=i/1000%10;
            a[3]=i/100%10;
            a[4]=i/10%10;
            a[5]=i/1%10;
            for(int j=1;j<=5;j++)
            {
                if(a[j]==2)
                {
                    count++;
                }
            }
        }
    }
    printf("%d",count);
}