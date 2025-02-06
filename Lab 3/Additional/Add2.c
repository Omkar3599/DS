#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}

int checkParentheses(char *exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1 || !isMatching(pop(), exp[i])) {
                return 0;
            }
        }
    }
    return top == -1;
}

int main() {
    char exp[MAX];
    printf("Enter an expression: ");
    fgets(exp, sizeof(exp), stdin);
    exp[strcspn(exp, "\n")] = '\0';

    if (checkParentheses(exp)) {
        printf("Parentheses are matched.\n");
    } else {
        printf("Parentheses are not matched.\n");
    }
    return 0;
}
