#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void convertToBase(int decimalNumber, int base) {
    char stack[MAX];
    int top = -1;

    char digits[] = "0123456789ABCDEF";
    if (base < 2 || base > 16) {
        printf("Base out of range (2-16)\n");
        return;
    }

    if (decimalNumber == 0) {
        printf("0\n");
        return;
    }

    while (decimalNumber > 0) {
        int remainder = decimalNumber % base;
        stack[++top] = digits[remainder];
        decimalNumber /= base;
    }

    printf("The number in base %d is: ", base);
    while (top >= 0) {
        printf("%c", stack[top--]);
    }
    printf("\n");
}

int main() {
    int decimalNumber, base;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    printf("Enter the base to convert to (2-16): ");
    scanf("%d", &base);

    convertToBase(decimalNumber, base);

    return 0;
}
