#include <stdio.h>

int main(void)
{
    int num=10;
    int num1=15;
    int *arr1[5];
    int *arr2[3][5]={{&num, &num1}};

    int **ptr1 = arr1;
    int *(*ptr2)[5]=arr2;

    printf("%d\n", *(*ptr2+1)[0]);
    return 0;
}