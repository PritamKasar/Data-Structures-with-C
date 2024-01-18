#include<stdio.h>

int Merge(int a[],int lb,int mid,int ub)
{
    int i=lb;
    int j=mid+1;
    int k=lb;
    int b[k];
    
     
    while(i<=mid && j<=ub)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while (j<=ub)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else{
            while (i<=mid)
            {
                b[k]=a[i];
                i++;
                k++;
            }
            
        }
        for(k=lb;k<=ub;k++)
        {
            a[k]=b[k];
        }
        
        
        
        
};
int Mergesort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        Mergesort(a,lb,mid);
        Mergesort(a,mid+1,ub);
        Merge(a,lb,mid,ub);
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
    Mergesort(val_25,0,array_size-1);
    printf("\n\nArray After Mergesort :\n");
    for(int j=0;j<array_size;j++)
    {
        printf("%d ",val_25[j]);
    }
    return 0;
}
