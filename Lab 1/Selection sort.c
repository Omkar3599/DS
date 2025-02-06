#include <stdio.h>

int main()
{
    int i,j,n,min,arr[50],temp;
    printf("Enter the total number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d" ,&arr[i]);
    }
        for(i=0;i<n-1;i++)
        {
            min = i;
            for(j=i+1;j<n;j++)
            {
                if(arr[j]<arr[min])
                {   min = j;}
                
                if (min != i)
                {
                    temp = arr[i];
                    arr[i] = arr[min];
                    arr[min] = temp;
                }
            }
        }
        printf("The elements after sorting are:\n ");
    for(i=0;i<n;i++)
    {
        printf("%d\t" ,arr[i]);
    }
}

