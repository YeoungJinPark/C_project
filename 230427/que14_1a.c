#include <stdio.h>

int SquareByValue(int num)
{
    return num*num;
}

void SquareByReference(int* num)
{
    *num *= *num;
}

int main(void)
{
    int num1=2;
    int num2=3;

    num1=SquareByValue(num1);
    printf("%d\n", num1);

    SquareByReference(&num2);
    printf("%d\n", num2);
    return 0;
}