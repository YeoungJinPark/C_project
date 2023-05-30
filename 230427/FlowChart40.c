//  배열 요소 왼쪽으로 한칸씩 원형으로 이동하기
#include <stdio.h>

int main(void)
{
    int arr[10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int temp=arr[0];

    for(int i=0; i<=8; i++)
    arr[i]=arr[i+1];

    arr[9]=temp;

    for(int j=0; j<=9; j++)
    printf("%d ", arr[j]);
    printf("\n");
    return 0;
}