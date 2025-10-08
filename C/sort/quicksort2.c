#include<stdio.h>
#include<stdlib.h>
void printfarr(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
        if(i<n-1)
        {
            printf(" ");
        }
    }
    printf("\n");
}
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
        int pivotloc=partition(a,low,high);
        quicksort(a,low,pivotloc-1);
        quicksort(a,pivotloc+1,high);
    }
}
void quick_sort(int a[],int n)
{
    quicksort(a,0,n-1);
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
    printfarr(a,n);
    quick_sort(a,n);
    printfarr(a,n);
    free(a);
}