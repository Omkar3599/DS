#include<stdio.h>

int main()
{
    int i,key,n,arr[50],pos,found=0;
    printf("Enter the number of elements: ");
    scanf("%d" ,&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d" ,&arr[i]);
    }
    printf("Enter the number to be found: ");
    scanf("%d", &key);
    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            found = 1;
            pos=i+1;
            break;
        }
    }
    if(found==1)
    {
        printf("Element found at position %d" , pos);
    }
    else
    {
        printf("Element not found");
    }
}
