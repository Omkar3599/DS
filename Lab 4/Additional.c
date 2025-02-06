#include <stdio.h>

#define MAX 100

typedef struct {
    int r;
    int c;
    int v;
} Elem;

void transpose(Elem in[], Elem out[]) {
    int n = in[0].v;
    int k = 1;
    out[0].r = in[0].c;
    out[0].c = in[0].r;
    out[0].v = in[0].v;

    for (int i = 0; i < in[0].c; i++) {
        for (int j = 1; j <= n; j++) {
            if (in[j].c == i) {
                out[k].r = in[j].c;
                out[k].c = in[j].r;
                out[k].v = in[j].v;
                k++;
            }
        }
    }
}

void printM(Elem mat[]) {
    int n = mat[0].v;
    printf("Row  Col  Val\n");
    for (int i = 0; i <= n; i++) {
        printf("%d    %d    %d\n", mat[i].r, mat[i].c, mat[i].v);
    }
}

int main() {
    Elem in[MAX], out[MAX];
    int n;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &in[0].r, &in[0].c);

    printf("Enter number of non-zero elements: ");
    scanf("%d", &in[0].v);

    printf("Enter elements (row col value):\n");
    for (int i = 1; i <= in[0].v; i++) {
        scanf("%d %d %d", &in[i].r, &in[i].c, &in[i].v);
    }

    transpose(in, out);

    printf("\nOriginal Matrix:\n");
    printM(in);

    printf("\nTransposed Matrix:\n");
    printM(out);

    return 0;
}
