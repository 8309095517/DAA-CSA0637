#include <stdio.h>

#define N 4 // Size of matrices

void strassen(int A[N][N], int B[N][N], int C[N][N]) {
    // Base case: if the matrix is 1x1
    if (N == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    // Dividing the matrices into submatrices
    int a[N/2][N/2], b[N/2][N/2], c[N/2][N/2], d[N/2][N/2];
    int e[N/2][N/2], f[N/2][N/2], g[N/2][N/2], h[N/2][N/2];
    int temp1[N/2][N/2], temp2[N/2][N/2];

    // Dividing matrix A into 4 submatrices
    for (int i = 0; i < N/2; i++) {
        for (int j = 0; j < N/2; j++) {
            a[i][j] = A[i][j];
            b[i][j] = A[i][j + N/2];
            c[i][j] = A[i + N/2][j];
            d[i][j] = A[i + N/2][j + N/2];
        }
    }

    // Dividing matrix B into 4 submatrices
    for (int i = 0; i < N/2; i++) {
        for (int j = 0; j < N/2; j++) {
            e[i][j] = B[i][j];
            f[i][j] = B[i][j + N/2];
            g[i][j] = B[i + N/2][j];
            h[i][j] = B[i + N/2][j + N/2];
        }
    }

    // Calculating the 7 intermediate matrices recursively
    strassen(a, e, temp1);
    strassen(b, g, temp2);
    for (int i = 0; i < N/2; i++) {
        for (int j = 0; j < N/2; j++) {
            C[i][j] = temp1[i][j] + temp2[i][j];
        }
    }

    strassen(a, f, temp1);
    strassen(b, h, temp2);
    for (int i = 0; i < N/2; i++) {
        for (int j = 0; j < N/2; j++) {
            C[i][j + N/2] = temp1[i][j] + temp2[i][j];
        }
    }

    strassen(c, e, temp1);
    strassen(d, g, temp2);
    for (int i = 0; i < N/2; i++) {
        for (int j = 0; j < N/2; j++) {
            C[i + N/2][j] = temp1[i][j] + temp2[i][j];
        }
    }

    strassen(c, f, temp1);
    strassen(d, h, temp2);
    for (int i = 0; i < N/2; i++) {
        for (int j = 0; j < N/2; j++) {
            C[i + N/2][j + N/2] = temp1[i][j] + temp2[i][j];
        }
    }
}

void printMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[N][N] = { {1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12},
                    {13, 14, 15, 16} };

    int B[N][N] = { {17, 18, 19, 20},
                    {21, 22, 23, 24},
                    {25, 26, 27, 28},
                    {29, 30, 31, 32} };

    int C[N][N]; // Result matrix

    strassen(A, B, C);

    printf("Result matrix C:\n");
    printMatrix(C);

    return 0;
}
