//  10, 20, 30, ... , 100 저장하고 거꾸로 출력하기
#include <stdio.h>

int main(void)
{
    int arr[10]={0, };
    int j, i;
    for(i=1; i<=10; i++)
    arr[i-1] = i*10;

    for(i=9; i>=0; i--)
    printf("%d ", arr[i]);
    printf("\n");
    return 0;
}