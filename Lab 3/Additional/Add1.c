#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stacks[MAX];
int top[10], base[10], size[10];

void initializeStacks(int num) {
    int i;
    int eachSize = MAX / num;
    for (i = 0; i < num; i++) {
        base[i] = i * eachSize;
        top[i] = base[i] - 1;
        size[i] = eachSize;
    }
}

int isFull(int stackNum) {
    return top[stackNum] == base[stackNum] + size[stackNum] - 1;
}

int isEmpty(int stackNum) {
    return top[stackNum] == base[stackNum] - 1;
}

void push(int stackNum, int value) {
    if (isFull(stackNum)) {
        printf("Stack %d is full.\n", stackNum);
    } else {
        stacks[++top[stackNum]] = value;
    }
}

int pop(int stackNum) {
    if (isEmpty(stackNum)) {
        printf("Stack %d is empty.\n", stackNum);
        return -1;
    } else {
        return stacks[top[stackNum]--];
    }
}

void display(int stackNum) {
    if (isEmpty(stackNum)) {
        printf("Stack %d is empty.\n", stackNum);
    } else {
        printf("Stack %d elements: ", stackNum);
        for (int i = base[stackNum]; i <= top[stackNum]; i++) {
            printf("%d ", stacks[i]);
        }
        printf("\n");
    }
}

int main() {
    int num, choice, stackNum, value;
    printf("Enter number of stacks: ");
    scanf("%d", &num);

    initializeStacks(num);

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter stack number (0 to %d): ", num - 1);
                scanf("%d", &stackNum);
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stackNum, value);
                break;
            case 2:
                printf("Enter stack number (0 to %d): ", num - 1);
                scanf("%d", &stackNum);
                value = pop(stackNum);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                printf("Enter stack number (0 to %d): ", num - 1);
                scanf("%d", &stackNum);
                display(stackNum);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}
