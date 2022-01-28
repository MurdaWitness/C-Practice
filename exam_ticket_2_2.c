#include <stdio.h>
#define M 8
#define N 6
#define INPUT "C:\\Users\\Public\\Documents\\exam\\5\\input.txt"
#define OUTPUT "C:\\Users\\Public\\Documents\\exam\\5\\output.txt"

void CopyMatrixFromFile(int quantity[M][N]) {
    FILE* file;
    file = fopen(INPUT, "r");

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            fscanf(file, "%d", &quantity[i][j]);
        }
    }

    fclose(file);
}

void PrintMatrix(int quantity[M][N]) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", quantity[i][j]);
        }
        printf("\n");
    }
}

void QuantityDestroyed(int quantity[M][N]) {
    FILE* file;
    file = fopen(OUTPUT, "a");

    int all_sum[M];

    for (int i = 0; i < M; ++i) {
        int sum = 0;
        for (int j = 0; j < N; ++j) {
            if (j == 1 || j == 2 || j == 4) {
                sum += quantity[i][j];
            }
        }
        all_sum[i] = sum;
    }

    for (int i = 0; i < M; ++i) {
        fprintf(file, "%d ", all_sum[i]);
    }
    fprintf(file, "\n");

    fclose(file);
}

void QuantityDestroyedSearchBig(int quantity[M][N]) {
    FILE* file;
    file = fopen(OUTPUT, "a");

    int all_sum[M];

    for (int i = 0; i < M; ++i) {
        int sum = 0;
        for (int j = 0; j < N; ++j) {
            if (j == 0 || j == 3 || j == 5) {
                sum += quantity[i][j];
            }
        }
        all_sum[i] = sum;
    }

    int tmp = 0;
    for (int i = 1; i < M; ++i) {
        if (all_sum[i] > all_sum[tmp]) {
            tmp = i;
        }
    }
    fprintf(file, "The biggest:\n");
    switch (tmp) {
        case 0: fprintf(file, "Russia"); break;
        case 1: fprintf(file, "France"); break;
        case 2: fprintf(file, "Giorgia"); break;
        case 3: fprintf(file, "Turkey"); break;
        case 4: fprintf(file, "China"); break;
        case 5: fprintf(file, "England"); break;
        case 6: fprintf(file, "USA"); break;
        case 7: fprintf(file, "Japan"); break;
        default: break;
    }
    fprintf(file, "\n");

    fclose(file);
}

void QuantityDestroyedSearchSmall(int quantity[M][N]) 
{
	FILE* file;
	file = fopen(OUTPUT, "a");

	int all_sum[M];

	for (int i = 0; i < M; ++i) 
	{
		int sum = 0;
		for (int j = 0; j < N; ++j) 
		{
			sum += quantity[i][j];
		}
		all_sum[i] = sum;
	}

	int tmp = 0;
	for (int i = 1; i < M; ++i) 
	{
		if (all_sum[i] < all_sum[tmp]) 
		{
			tmp = i;
		}
	}

	fprintf(file, "The smallest:\n");
	switch (tmp) {
	case 0: fprintf(file, "Russia"); break;
	case 1: fprintf(file, "France"); break;
	case 2: fprintf(file, "Giorgia"); break;
	case 3: fprintf(file, "Turkey"); break;
	case 4: fprintf(file, "China"); break;
	case 5: fprintf(file, "England"); break;
	case 6: fprintf(file, "USA"); break;
	case 7: fprintf(file, "Japan"); break;
	default: break;
	}
	fprintf(file, "\n");

	fclose(file);
}

int main() {
    int quantity[M][N];

    CopyMatrixFromFile(quantity);

    PrintMatrix(quantity);

    QuantityDestroyed(quantity);

    QuantityDestroyedSearchBig(quantity);

    QuantityDestroyedSearchSmall(quantity);

    return 0;
}