#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n;
    int count=0;
    scanf("%d",&n);
    int temp=n;
    int reverse=0;
    while(temp!=0)
    {
        temp=temp/10;
        count++;
    }
    int *a=(int *)malloc(sizeof(int)*count+1);
    temp=n;
    for(int i=0;i<count;i++)
    {
        a[i]=(int)(temp/(pow(10,i)))%10;
    }
    for(int i=0;i<count;i++)
    {  
        reverse=reverse*10+a[i];
    }
    printf("%d",reverse);
}