#include <stdio.h>  //배열 90도 돌리기

int main(void)
{
    int arr1[5][5]={
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int arr2[5][5];
    int j, i;
    
    for(j=0; j<5; j++)
    {
        for(i=0; i<5; i++)
        arr2[j][i]=arr1[4-i][j];
    }

    printf("90도\n");
    for(j=0; j<5; j++)
    {
        for(i=0; i<5; i++)
        printf("%d ", arr2[j][i]);

        printf("\n");
    }

    for(j=0; j<5; j++)
    {
        for(i=0; i<5; i++)
        arr1[j][i]=arr2[4-i][j];
    }

    printf("180도\n");
    for(j=0; j<5; j++)
    {
        for(i=0; i<5; i++)
        printf("%d ", arr1[j][i]);

        printf("\n");
    }
    return 0;
}