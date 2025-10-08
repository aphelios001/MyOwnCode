    #include<stdio.h>
    #include<stdlib.h>
    int main()
    {
        int m,n;
        scanf("%d %d",&n,&m);
        int *a=(int*)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int t=0;
        int min=100000;
        for(int i=0;i<n-m;i++)
        {
            t=0;
            for(int j=i;j<i+m;j++)
            {
                t=t+a[j];
            }
            if(t<min)
            {
                min=t;
            }
        }
        if(n==m)
        {
            min=0;
            for(int i=0;i<n;i++)
            {
                min=min+a[i];
            }
        }
        printf("%d",min);
    }