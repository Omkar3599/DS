#include <stdio.h>

void multiplyMatrices(int A[][100], int B[][100], int C[][100], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void addMatrices(int A[][100], int B[][100], int C[][100], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int isMagicSquare(int mat[][100], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += mat[0][i];

    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        int colSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += mat[i][j];
            colSum += mat[j][i];
        }
        if (rowSum != sum || colSum != sum) return 0;
    }

    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < n; i++) {
        diag1 += mat[i][i];
        diag2 += mat[i][n - i - 1];
    }

    if (diag1 != sum || diag2 != sum) return 0;

    return 1;
}

int main() {
    int r1, c1, r2, c2, n;

    printf("Enter rows and columns for matrix A: ");
    scanf("%d %d", &r1, &c1);
    int A[r1][100];
    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter rows and columns for matrix B: ");
    scanf("%d %d", &r2, &c2);
    int B[r2][100];
    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    if (c1 != r2) {
        printf("Matrix multiplication not possible.\n");
    } else {
        int C[r1][100];
        multiplyMatrices(A, B, C, r1, c1, c2);
        printf("Matrix C (result of multiplication):\n");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                printf("%d ", C[i][j]);
            }
            printf("\n");
        }
    }

    if (r1 != r2 || c1 != c2) {
        printf("Matrix addition not possible.\n");
    } else {
        int D[r1][100];
        addMatrices(A, B, D, r1, c1);
        printf("Matrix D (result of addition):\n");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                printf("%d ", D[i][j]);
            }
            printf("\n");
        }
    }

    printf("Enter the size of square matrix: ");
    scanf("%d", &n);
    int E[n][100];
    printf("Enter elements of the square matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &E[i][j]);
        }
    }

    if (isMagicSquare(E, n)) {
        printf("The matrix is a magic square.\n");
    } else {
        printf("The matrix is not a magic square.\n");
    }

    return 0;
}

