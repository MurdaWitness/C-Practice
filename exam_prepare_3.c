#include <stdio.h>
#define M 9
#define N 7

int GetAllQuantity(int quantity[M][N]) {
    int sum = 0;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            sum += quantity[i][j];
        }
    }

    return sum;
}

int GetQuantity(int quantity[M][N]) {
    int sum = 0;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j == 0 || j == 2 || j == 4 || j == 6) {
                sum += quantity[i][j];
            }
        }
    }

    return sum;
}

void GetMostQuantity(int quantity[M][N]) {

    int sum[N];
    int transposed_matrix[N][M];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            transposed_matrix[i][j] = quantity[j][i];
        }
    }

    for (int i = 0; i < N; ++i) {
        int string_sum = 0;
        for (int j = 0; j < M; ++j) {
                string_sum += transposed_matrix[i][j];
        }
        sum[i] = string_sum;
    }

    int tmp = 0;
    for (int i = 1; i < N; ++i) {
        if (sum[i] > sum[tmp]) {
            tmp = i;
        }
    }

    int sum_BP[M];

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j == 5) {
                sum_BP[i] = quantity[i][j];
            }
        }
    }

    tmp = 0;
    for (int i = 1; i < M; ++i) {
        if (sum_BP[i] > sum_BP[tmp]) {
            tmp = i;
        }
    }

}