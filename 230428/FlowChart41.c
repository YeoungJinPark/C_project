#include <stdio.h>

int main(void)  //배열 최댓값 구하기
{
    int arr[10]={0, 1, 2, 3, 4, 5, 6, 7 , 8, 9};
    int max=arr[0];
    int i;

    for(i=1; i<=9; i++)
    {
        if(max < arr[i])
        max = arr[i];
    }
    printf("최댓값: %d\n", max);
    return 0;
}