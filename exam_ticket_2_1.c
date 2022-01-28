#include <stdio.h>
#define M 10

int global_array[M];

int GetSum(int var, int local_array[M]) {
    int sum = 0;

    for (int i = 0; i < M; ++i) {
        local_array[i] += var;
    }

    for (int i = 0; i < M; ++i) {
        sum += (local_array[i] + global_array[i]);
    }

    return sum;
}