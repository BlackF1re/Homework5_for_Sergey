#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void print(int len, int* arr)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", arr[i]);
    }
}

double A10(int len, int* arr)
{
    double sumOfSqrts = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > 0)
            sumOfSqrts += sqrt(arr[i]);
    }
    return sumOfSqrts;
}

double A8(int len, int* arr)
{
    int sumOfPositives = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > 0)
            sumOfPositives += arr[i];
    }
    return sqrt(sumOfPositives);
}

int M5(int len, int* arr, float a8)
{
    int counter = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > a8)
            counter++;
    }
    return counter;
}

int main()
{
    system("chcp 1251");
    printf("Выполнено Лебедевым Сергеем, группа 423-2\nВариант 10.\n");
    int xlength, yLength, isDigit;

    printf("\nВведите количество элементов массива X:\t");
    isDigit = scanf_s("%d", &xlength);
    if (xlength < 1 || isDigit != 1)
    {
        printf("error");
        exit(1);
    }
    printf("\nВведите количество элементов массива Y:\t");
    isDigit = scanf_s("%d", &yLength);
    if (yLength < 1 || isDigit != 1)
    {
        printf("error");
        exit(1);
    }
    srand(time(0));

    int* X = calloc(xlength, sizeof(int));
    for (int i = 0; i < xlength; i++)
    {
        X[i] = rand() % 20 - 10;
    }
    printf("\nМассив X:\n");
    print(xlength, X);
    printf("\n");

    int* Y = calloc(yLength, sizeof(int));
    for (int i = 0; i < yLength; i++)
    {
        Y[i] = rand() % 20 - 10;
    }
    printf("\nМассив Y:\n");
    print(yLength, Y);

    double a8x = A8(xlength, X);
    int m5x = M5(xlength, X, a8x);

    if (m5x <= 2)
    {
        int a10y = A10(yLength, Y);
        double a8y = A8(yLength, Y);
        int m5y = M5(yLength, Y, a8y);
        double a10x = A10(xlength, X);

        double z1 = a10y + m5y * cos(a10x);
        printf("\nZ1 = %f", z1);
    }
    else printf("\n\nZ1: не было выполнено условие: M5(X) <= 2\n");

    if (m5x > 2)
    {
        int a10y = A10(yLength, Y);

        double z2 = 33.51 * sin(pow(a10y, 2));
        printf("\nZ2 = %f", z2);
    }
    else printf("\n\nZ2: не было выполнено условие: M5(X) > 2\n");
    free(X);
    free(Y);
    return 0;

}