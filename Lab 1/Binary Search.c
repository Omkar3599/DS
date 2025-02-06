#include <stdio.h>

int main(){
 int low = 0, high,mid, n,arr[100],i,key;
 printf("Enter the total no. of elements: ");
 scanf("%d", &n);
 printf("Enter the elements in ascending order: ");
 for(i=0;i<n;i++)
 {
     scanf("%d" , &arr[i]);
 }
 printf("Enter the element to search: ");
 scanf("%d" ,&key);
 high = n-1;
 do {
    mid = (low + high)/2;
    if(key<arr[mid])
    {
       high= mid - 1;
    }
    else if(key > arr[mid])
    {
       low = mid + 1;
    }
    }while (key!= arr[mid] && low<=high);
    if(key == arr[mid])
    {
        printf("Successful search, Element found in position %d" , mid+1);
    }
    else
    {
         printf("Element not found ");
    }

}

