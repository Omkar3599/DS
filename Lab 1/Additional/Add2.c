#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == key) return mid;
    if (arr[mid] > key) return binarySearch(arr, low, mid - 1, key);
    return binarySearch(arr, mid + 1, high, key);
}

void selectionSort(int arr[], int n, int start) {
    if (start >= n - 1) return;
    int minIndex = start;
    for (int i = start + 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) minIndex = i;
    }
    int temp = arr[start];
    arr[start] = arr[minIndex];
    arr[minIndex] = temp;
    selectionSort(arr, n, start + 1);
}

int multiply(int a, int b) {
    if (b == 0) return 0;
    return a + multiply(a, b - 1);
}

int main() {
    int n, key, a, b;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    printf("Enter two numbers to multiply:\n");
    scanf("%d %d", &a, &b);

    selectionSort(arr, n, 0);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int index = binarySearch(arr, 0, n - 1, key);
    if (index != -1) {
        printf("Element %d is at index %d\n", key, index);
    } else {
        printf("Element %d not found\n", key);
    }

    printf("Multiplication of %d and %d is %d\n", a, b, multiply(a, b));

    return 0;
}
