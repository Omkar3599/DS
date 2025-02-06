#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int st[100];
int top = -1;

void push(int v) {
    st[++top] = v;
}

int pop() {
    return st[top--];
}

int eval(char* s) {
    int len = strlen(s);
    for (int i = len - 1; i >= 0; i--) {
        if (isdigit(s[i])) {
            int num = 0, mult = 1;
            while (i >= 0 && isdigit(s[i])) {
                num += (s[i] - '0') * mult;
                mult *= 10;
                i--;
            }
            push(num);
        } else if (s[i] == ' ') {
            continue;
        } else {
            int op1 = pop();
            int op2 = pop();
            if (s[i] == '+') push(op1 + op2);
            else if (s[i] == '-') push(op1 - op2);
            else if (s[i] == '*') push(op1 * op2);
            else if (s[i] == '/') push(op1 / op2);
            else if (s[i] == '%') push(op1 % op2);
        }
    }
    return pop();
}

int main() {
    char s[100];
    printf("Enter the prefix expression: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
    int result = eval(s);
    printf("Result: %d\n", result);
    return 0;
}
