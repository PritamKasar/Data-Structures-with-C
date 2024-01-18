#include<stdio.h>
int binary_search(int a[],int low,int high,int key)
{
    if(low==high)
    {
        if(a[low]==key)
        return low;                
    }
    if(low<high)
    {
        int mid=(high+low)/2;
        if(key==a[mid])
        return mid;
        if(key<a[mid])
        return binary_search(a,low,mid-1,key);
        else
        return binary_search(a,mid+1,high,key);
        
    }  
    return -1;
    
}
int main()
{
    int key;
    int array_size;
    printf("Enter Array size: ");
    scanf("%d",&array_size);
    int pritam[array_size];
    printf("Enter Element:\n");
    for(int loop=0;loop<array_size;loop++)
    {
        scanf("%d",&pritam[loop]);
    }
    printf("Given Search Space:\n");
    for(int disp=0;disp<array_size;disp++)
    {
        printf("%d\t",pritam[disp]);
    }
    printf("\nEnter An Element To Be Search: ");
    scanf("%d",&key);
    int element_found=binary_search(pritam,1,array_size,key);
    if(element_found==-1)
    {
        printf("Element Not Found");   
    }
    else
    {
        
         printf("Element Found At Index: %d",element_found);
    }
    
     return 0;
    
    
    
}