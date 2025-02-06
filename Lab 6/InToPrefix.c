#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char stack[MAX];
    int top;
} Stack;

void initialize(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, char c) {
    if (isFull(s)) {
        printf("\nStack is full!\n");
        return;
    }
    s->stack[++s->top] = c;
}

char pop(Stack* s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->stack[s->top--];
}

char peek(Stack* s) {
    if (isEmpty(s)) {
        return '\0';
    } else {
        return s->stack[s->top];
    }
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int getPriority(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int isRightAssociative(char c) {
    return c == '^';
}

void infixToPostfix(char* infix, char* output) {
    int k = 0;
    int l = strlen(infix);
    Stack s;
    initialize(&s);

    for (int i = 0; i < l; i++) {
        char current = infix[i];

        if (isalnum(current)) {
            output[k++] = current;
        } else if (current == '(') {
            push(&s, current);
        } else if (current == ')') {
            while (peek(&s) != '(') {
                output[k++] = pop(&s);
            }
            pop(&s);
        } else if (isOperator(current)) {
            if (isRightAssociative(current)) {
                while (getPriority(current) <= getPriority(peek(&s))) {
                    output[k++] = pop(&s);
                }
            } else {
                while (getPriority(current) < getPriority(peek(&s))) {
                    output[k++] = pop(&s);
                }
            }
            push(&s, current);
        }
    }

    while (!isEmpty(&s)) {
        output[k++] = pop(&s);
    }
    output[k] = '\0';
}

void reverse(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void infixToPrefix(char* infix, char* result) {
    reverse(infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    char postfix[MAX];
    infixToPostfix(infix, postfix);

    reverse(postfix);
    strcpy(result, postfix);
}

int main() {
    char infix[MAX];
    char result[MAX];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, result);
    printf("Prefix Expression: %s\n", result);
    return 0;
}
