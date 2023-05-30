//  1부터 10까지의 수 저장하고 출력하기
#include <stdio.h>

int main(void)
{
    int arr[10];
    for(int i=1; i<=10; i++)
    arr[i-1]=i;

    for(int j=1; j<=10; j++)
    printf("%d ", arr[j-1]);

    printf("\n");
    return 0;
}