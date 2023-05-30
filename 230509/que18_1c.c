#include <stdio.h>

void SimpleFuncOne(int **str1, int *(*str2)[5])
{
    printf("성공!\n");
}

void SimpleFuncTwo(int ***str3, int ***(*str4)[5])
{
    printf("성공2\n");
}

int main(void)
{
    int* arr1[3];
    int* arr2[3][5];
    int** arr3[5];
    int*** arr4[3][5];
    
    SimpleFuncOne(arr1, arr2);
    SimpleFuncTwo(arr3, arr4);
    return 0;
}