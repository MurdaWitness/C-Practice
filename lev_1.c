#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define SIZE 2

void FillMassive(int [][SIZE]);
void ShowMassive(int [][SIZE]);
int PowAllMassives(int [][SIZE], int [][SIZE]);

int main()
{
    system("clear");
    srand(time(NULL));
    int M1[SIZE][SIZE], M2[SIZE][SIZE];
    printf("First massive:\n");
    FillMassive(M1);
    ShowMassive(M1);
    printf("Second massive:\n");
    FillMassive(M2);
    ShowMassive(M2);
    printf("Result: %ld\n", PowAllMassives(M1, M2));
    return 0; 
}

void FillMassive(int M[][SIZE])
{
    for(int i = 0; i < SIZE; i++)
    for(int j = 0; j < SIZE; j++)
    M[i][j] = rand()%5;
}

void ShowMassive(int M[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        printf("%-2d\t", M[i][j]);
        printf("\n");
    }
    printf("\n");
}

int PowAllMassives(int M1[][SIZE], int M2[][SIZE])
{
    long result = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        result += pow(M1[i][j], M2[i][j]);
    }
    return result;
}