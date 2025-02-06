#include<stdio.h>

int main()
{
    int i,n,arr[50],j,temp;
    printf("Enter the number of elements: ");
    scanf("%d" ,&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d" ,&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("The elements after sorting are:\n ");
    for(i=0;i<n;i++)
    {
        printf("%d\t" ,arr[i]);
    }

}

