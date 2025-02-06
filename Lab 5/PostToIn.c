#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char *s[MAX];
int t = -1;

void push(char *v) {
    if (t < MAX - 1) {
        s[++t] = v;
    } else {
        printf("Overflow\n");
        exit(1);
    }
}

char *pop() {
    if (t >= 0) {
        return s[t--];
    } else {
        printf("Underflow\n");
        exit(1);
    }
}

void toInfix(char p[]) {
    int l = strlen(p);
    for (int i = 0; i < l; i++) {
        char x = p[i];
        if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9')) {
            char *op = (char *)malloc(2 * sizeof(char));
            op[0] = x;
            op[1] = '\0';
            push(op);
        } else {
            char *o2 = pop();
            char *o1 = pop();
            char *res = (char *)malloc(strlen(o1) + strlen(o2) + 4);
            sprintf(res, "(%s%c%s)", o1, x, o2);
            push(res);
        }
    }
    printf("%s\n", pop());
}

int main() {
    char p[MAX];
    printf("Enter the postfix expression: ");
    fgets(p, sizeof(p), stdin);
    p[strcspn(p, "\n")] = '\0';
    toInfix(p);
    return 0;
}
