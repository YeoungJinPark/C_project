//  배열 요소 거꾸로 뒤집기
#include <stdio.h>

int main(void)
{
    int arr[10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int temp=0;

    for(int i=0; i<=4; i++)
    {
        temp=arr[i];
        arr[i]=arr[9-i];
        arr[9-i]=temp;
    }

    for(int j=0; j<10; j++)
    printf("%d ", arr[j]);
    printf("\n");
    return 0;
}