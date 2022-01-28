#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define C 9
#define T 7

void AllQuantity(int [][T]);
void PartOfQuantity(int [][T]);
void CheckQuantity(int [][T]);

int main()
{
    //очистка перед исспользованием
    system("clear");
    //объявление матрицы и её размерности
    int machines[C][T];

    FILE *file = fopen("input.txt", "r");
    if(file == NULL)
    {
        printf("Не удалось открыть файл.\n");
        exit(1);
    }

    for (int i = 0; i < C; i++) 
    {
        for (int j = 0; j < T; j++) 
        {
            fscanf(file, "%d", &machines[i][j]);
        }
    }
    fclose(file);

    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < T; j++)
        printf("%-4d", machines[i][j]);
        printf("\n");
    }
    printf("\n");

    AllQuantity(machines);
    PartOfQuantity(machines);
    CheckQuantity(machines);

    return 0; 
}

void AllQuantity(int M[][T])
{
    FILE *file = fopen("output.txt", "w");
    if(file == NULL)
    {
        printf("Не удалось создать файл.\n");
        exit(1);
    }

    int sum = 0;
    for (int i = 0; i < C; i++) 
    {
        for (int j = 0; j < T; j++) 
        {
            sum += M[i][j];
        }
    }

    fprintf(file, "Total machines: %d\n", sum);
    fclose(file);
}

void PartOfQuantity(int M[][T])
{
    FILE *file = fopen("output.txt", "a");
    if(file == NULL)
    {
        printf("Не удалось открыть файл.\n");
        exit(1);
    }

    int sum = 0;
    for(int i = 0; i < C; i++)
    {
        for(int j = 0; j < T; j+=2)
        {
            sum += M[i][j];
        }
    }

    fprintf(file, "Total tanks, SAUs, howitzers, SZOs: %d\n", sum);
    fclose(file);
}

void CheckQuantity(int M[][T])
{
    FILE *file = fopen("output.txt", "a");
    if(file == NULL)
    {
        printf("Не удалось открыть файл.\n");
        exit(1);
    }

    int mostQuantity[T] = {0};
    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < T; j++)
        {
            mostQuantity[j] += M[i][j];
        }
    }

    int max = mostQuantity[0];
    int index = 0;
    for (int i = 1; i < T; i++)
    {
        if (max < mostQuantity[i])
        {
            max = mostQuantity[i];
            index = i;
        }
    }

    switch (index)
    {
    case 0: 
    fprintf(file, "Quantity of Tanks is the biggest\n"); 
    break;

    case 1: 
    fprintf(file, "Quantity of BTR is the biggest\n"); 
    break;
    
    case 2: 
    fprintf(file, "Quantity of SAU is the biggest\n"); 
    break;
    
    case 3: 
    fprintf(file, "Quantity of ZRK is the biggest\n"); 
    break;  

    case 4: 
    fprintf(file, "Quantity of Howitzer is the biggest\n"); 
    break;
    
    case 5: 
    fprintf(file, "Quantity of BP is the biggest\n"); 
    break;
    
    case 6: 
    fprintf(file, "Quantity of SZO is the biggest\n"); 
    break;
    
    default:
        break;
    }
    /*
    max = mostQuantity[0];
    index = 0;
    for (int i = 1; i < T; i++)
    {
        if (max < mostQuantity[i])
        {
            max = mostQuantity[i];
            index = i;
        }
    }
    */
    fclose(file);
}