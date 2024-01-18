#include<stdio.h>
int partition(int a[],int lb,int ub)
{
    int pivot=a[lb];
    int start=lb;
    int end=ub;
    while(start<end)
    {
        while(a[start]<=pivot && start<end)
        {
            start=start+1;
        }
        while(a[end]>pivot)
        {
            end=end-1;
        }
        if(start<end)
        {
            int temp=a[start];
            a[start]=a[end];
            a[end]=temp;
        }
    }
    a[lb]=a[end];
    a[end]=pivot;
    return end;
}
int quicksort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        int loc=partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);

    }
};
int main() 
{
    int array_size;
    printf("Enter an Array size :");
    scanf("%d",&array_size);
    printf("Enter Elements :\n");
    int val_25[array_size];
    for(int k=0;k<array_size;k++)
    {
        scanf("%d",&val_25[k]);
    }
    printf("\nUnsorted Array :\n");
    for(int i=0;i<array_size;i++)
    {
        printf("%d ",val_25[i]);
    }
    quicksort(val_25,0,array_size-1);
    printf("\n\nArray After QuickSort :\n");
    for(int j=0;j<array_size;j++)
    {
        printf("%d ",val_25[j]);
    }
    return 0;
}
    

