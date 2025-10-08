#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n<=1)
    {
        return 0;
    }
    int p;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            p=i;
            break;
        }
    }
    printf("%d",n/p);
    return 0;

   

    
}