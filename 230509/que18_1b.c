#include <stdio.h>

void Func1(int *str1, int *str2)
{
    printf("성공1\n");
}

void Func2(int (*str3)[4], int (*str4)[4])
{
    printf("성공2\n");
}

int main(void)
{
    int arr1[3];
    int arr2[4];
    int arr3[3][4];
    int arr4[2][4];

    Func1(arr1, arr2);
    Func2(arr3, arr4);
    return 0;
}