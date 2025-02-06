#include <stdio.h>

int main()
{
    int i,j,n,key,arr[50];
    printf("Enter the total number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d" ,&arr[i]);
    }
    for(j=1;j<n;j++)
    {
        key=arr[j];
        for(i=j-1;i>=0&&arr[i]>key;i--)
        {
            arr[i+1]=arr[i];
        }
        arr[i+1]=key;
    }
    printf("The elements are\n ");
    for(i=0;i<n;i++)
    {
        printf("%d\t" ,arr[i]);
    }
}

