#include <stdio.h>
#define M 9
#define N 7
#define PATH "C:\\Users\\Public\\Documents\\exam\\2\\output.txt"

void GetAllQuantity(int quantity[M][N]);
void GetQuantity(int quantity[M][N]);
void GetMostQuantity(int quantity[M][N]);


int main() {
    // открыли файл
    FILE* input = fopen("C:\\Users\\Public\\Documents\\exam\\2\\input.txt", "r");
    // инициализировали матрицу
    int quantity[M][N];
    // ввели матрицу из файла
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            fscanf(input, "%d", &quantity[i][j]);
        }
    }
    // выводим матрицу на экран
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", quantity[i][j]);
        }
        printf("\n");
    }
    // вызов функции для получения  общего количества техники
    GetAllQuantity(quantity);
    // получение выбранного количества техники
    GetQuantity(quantity);

    GetMostQuantity(quantity);

    return 0;
}

void GetAllQuantity(int quantity[M][N]) {
    FILE* file;
    file = fopen(PATH, "a");
    int sum = 0;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            sum += quantity[i][j];
        }
    }

    fprintf(file, "%d\n", sum);

    fclose(file);
}

void GetQuantity(int quantity[M][N]) {
    FILE* file;
    file = fopen(PATH, "a");
    int sum = 0;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j == 0 || j == 2 || j == 4 || j == 6) {
                sum += quantity[i][j];
            }
        }
    }

    fprintf(file, "%d\n", sum);

    fclose(file);
}

void GetMostQuantity(int quantity[M][N]) {
    FILE* file;
    file = fopen(PATH, "a");

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

    switch (tmp) {
        case 0: fprintf(file, "Quantity of Tanks is the biggest\n"); break;
        case 1: fprintf(file, "Quantity of BTR is the biggest\n"); break;
        case 2: fprintf(file, "Quantity of SAU is the biggest\n"); break;
        case 3: fprintf(file, "Quantity of ZRK is the biggest\n"); break;
        case 4: fprintf(file, "Quantity of G is the biggest\n"); break;
        case 5: fprintf(file, "Quantity of Artillery is the biggest\n"); break;
        case 6: fprintf(file, "Quantity of System is the biggest\n"); break;
        default: break;
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

    switch (tmp) {
        case 0: fprintf(file, "USA\n"); break;
        case 1: fprintf(file, "England\n"); break;
        case 2: fprintf(file, "German\n"); break;
        case 3: fprintf(file, "France\n"); break;
        case 4: fprintf(file, "Belgiya\n"); break;
        case 5: fprintf(file, "Canada\n"); break;
        case 6: fprintf(file, "Norway\n"); break;
        case 7: fprintf(file, "Greece\n"); break;
        case 8: fprintf(file, "Turkey\n"); break;
        default: break;
    }

    fclose(file);

}