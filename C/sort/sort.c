#include<stdio.h>
#include<stdlib.h>
int partition(int a[],int low,int high)
{
    int pivot = a[low];
    while(low<high)
    {
        while(low<high&&a[high]>=pivot)
        {
            --high;
        }
        a[low]=a[high];
        while(low<high&&a[low]<=pivot)
        {
            ++low;
        }
        a[high]=a[low];
        
    }
    a[low]=pivot;
    return low;
}
void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int pivotloc = partition(a,low,high);
        quicksort(a,low,pivotloc-1);
        quicksort(a,pivotloc+1,high);
    }
}
void insertsort(int a[],int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            key=a[i];
            for(j=i-1;j>=0&&a[j]>key;j--)
            {
                a[j+1]=a[j];
            }
            a[j+1]=key;
        }
    }
}
void shellsort(int a[],int n)
{
    int i,j,key,inc;
    for(inc = n/2;inc>0;inc = inc/2)
    {
        for(i=inc;i<n;i++)
        {
            if(a[i]<a[i-inc])
            {
                key=a[i];
                for(j=i-inc;j>=0&&a[j]>key;j=j-inc)
                {
                    a[j+inc]=a[j];
                }
                a[j+inc]=key;
            }

        }
    }
}
void printArray(int arr[], int size) 
{
    printf("[");
    for (int i = 0; i < size; i++) 
    {
        printf("%d", arr[i]);
        if (i < size - 1) 
        {
            printf(", ");
        }
    }
    printf("]\n");
}
int main()
{
    int n;
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    //shellsort(a,n);
    //quicksort(a,0,n-1);
    //insertsort(a,n);
    printArray(a,n);
}