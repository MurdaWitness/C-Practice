#include <stdio.h>
#include "math.h"
#define M 5
#define N 4

double GetResult(double matrix1[M][N], double matrix2[M][N]);

int main() {

    double matrix1[M][N], matrix2[M][N];

    printf("result is:\n%lf", GetResult(matrix1, matrix2));

    return 0;
}

double GetResult(double matrix1[M][N], double matrix2[M][N]) {
    double result = 0;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            result += pow(matrix1[i][j], matrix2[i][j]);
        }
    }

    return result;
}