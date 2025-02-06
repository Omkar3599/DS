#include <stdio.h>

#define MAX 100

typedef struct {
    int r;
    int c;
    int v;
} Elem;

void fastT(Elem in[], int n, Elem out[]) {
    int rowCnt[MAX] = {0}, rowStart[MAX] = {0};

    for (int i = 0; i < n; i++) {
        rowCnt[in[i].c]++;
    }

    rowStart[0] = 0;
    for (int i = 1; i < MAX; i++) {
        rowStart[i] = rowStart[i - 1] + rowCnt[i - 1];
    }

    for (int i = 0; i < n; i++) {
        int r = in[i].r;
        int c = in[i].c;
        int idx = rowStart[c] + rowCnt[c] - 1;
        out[idx].r = c;
        out[idx].c = r;
        out[idx].v = in[i].v;
        rowCnt[c]--;
    }
}

void printM(Elem mat[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Row: %d, Col: %d, Val: %d\n", mat[i].r, mat[i].c, mat[i].v);
    }
}

int main() {
    Elem in[MAX], out[MAX];
    int n;

    printf("Enter number of non-zero elements: ");
    scanf("%d", &n);

    printf("Enter elements (row col value):\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d %d %d", &in[i].r, &in[i].c, &in[i].v);
    }

    fastT(in, n, out);

    printf("\nTransposed Matrix:\n");
    printM(out, n);

    return 0;
}
