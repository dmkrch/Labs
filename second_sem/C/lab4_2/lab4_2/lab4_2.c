#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100


int ConvertLineToInt(char line[]);
double ArithmeticAverage(int array[], int length);

int main()
{
    int array[MAX];
    char singleLine[MAX];
    int counter = 0;
    double arithmeticAverage = 0;
    FILE* file;

    for (int i = 0; i < MAX; ++i)
        array[i] = 0;

    fopen_s(&file, "input.txt", "r");

    while (!feof(file))
    {
        fgets(singleLine, MAX, file);
        array[counter] = ConvertLineToInt(singleLine);

        ++counter;
    }


    arithmeticAverage = ArithmeticAverage(array, counter - 2);
    printf("Arethmetic average of is  %f", arithmeticAverage);

    getchar();

    fclose(file);
    return 0;
}

int ConvertLineToInt(char line[])
{
    bool state = true;
    int length = 0;
    int number = 0;

    for (int i = 0; line[i] != '\n'; ++i)
        ++length;


    for (int i = 0; line[i] != '\n'; ++i)
    {
        if (line[i] == '-')
        {
            --length;
            state = false;

            continue;
        }

        number += (line[i] - '0') * pow(10, --length);
    }

    if (state == true)
        return number;
    else
        return number * (-1);
}

double ArithmeticAverage(int array[], int length)
{
    double sum = 0;
    int positive_numbers = 0;

    for (int i = 0; i < length; ++i)
    {
        if (array[i] > 0)
        {
            sum += array[i];
            ++positive_numbers;
        }
    }

    return sum / positive_numbers;
}