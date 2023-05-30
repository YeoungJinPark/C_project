#include <stdio.h>

int main(void)
{
    int arr1[2][4]={
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };
    int arr2[4][2];
    int i, j;

    for(j=0; j<4; j++)
    {
        for(i=0; i<2; i++)
        arr2[j][i]=arr1[i][j];
    }
    
    for(j=0; j<4; j++)
    {
        for(i=0; i<2; i++)
        printf("%d\n", arr2[j][i]);
    }
    return 0;
}