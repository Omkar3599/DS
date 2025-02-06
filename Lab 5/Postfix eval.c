#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int s[MAX];
int t = -1;

void push(int v) {
    if (t < MAX - 1) {
        s[++t] = v;
    } else {
        printf("Overflow\n");
        exit(1);
    }
}

int pop() {
    if (t >= 0) {
        return s[t--];
    } else {
        printf("Underflow\n");
        exit(1);
    }
}

int evaluate(char *exp) {
    int i = 0, n;

    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            n = 0;
            while (isdigit(exp[i])) {
                n = n * 10 + (exp[i] - '0');
                i++;
            }
            push(n);
        } else if (exp[i] == ' ') {
            i++;
        } else {
            int b = pop();
            int a = pop();
            switch (exp[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/':
                    if (b == 0) {
                        printf("Divide by zero\n");
                        exit(1);
                    }
                    push(a / b);
                    break;
                case '%':
                    if (b == 0) {
                        printf("Divide by zero\n");
                        exit(1);
                    }
                    push(a % b);
                    break;
            }
            i++;
        }
    }

    return pop();
}

int main() {
    char exp[MAX];

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);
    exp[strcspn(exp, "\n")] = '\0';

    int res = evaluate(exp);
    printf("Result: %d\n", res);

    return 0;
}
