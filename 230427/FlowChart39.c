//배열a 요소 배열b에 거꾸로 저장하기
#include <stdio.h>

int main(void)
{
    int arr1[10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr2[10];

    for(int i=0; i<=9; i++)
    arr2[i]=arr1[9-i];

    for(int j=0; j<=9; j++)
    printf("%d ", arr2[j]);
    printf("\n");
    return 0;
}