#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

int isEmpty() {
    return front == -1;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full.\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear) {
        front =rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    return value;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\t2. Dequeue\t3. Display\t4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}
