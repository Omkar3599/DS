#include <stdio.h>

#define MAX 100

void readMatrix(int mat[MAX][MAX], int r, int c, char name) {
    printf("Enter the elements of matrix %c (%dx%d):\n", name, r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void displayMatrix(int mat[MAX][MAX], int r, int c, char name) {
    printf("Matrix %c (%dx%d):\n", name, r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void createMaxMatrix(int matA[MAX][MAX], int matB[MAX][MAX], int matC[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            matC[i][j] = (matA[i][j] > matB[i][j]) ? matA[i][j] : matB[i][j];
        }
    }
}

int main() {
    int r, c;
    int matA[MAX][MAX], matB[MAX][MAX], matC[MAX][MAX];

    printf("Enter the number of rows and columns of the matrices: ");
    scanf("%d %d", &r, &c);

    if (r > MAX || c > MAX) {
        printf("Error: The maximum size of the matrices is %dx%d.\n", MAX, MAX);
        return 1;
    }


    readMatrix(matA, r, c, 'A');
    readMatrix(matB, r, c, 'B');

    createMaxMatrix(matA, matB, matC, r, c);


    displayMatrix(matA, r, c, 'A');
    displayMatrix(matB, r, c, 'B');
    displayMatrix(matC, r, c, 'C');

    return 0;
}
