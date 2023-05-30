#include <stdio.h>

int main(void)
{
    int arr[5];
    int max, min, sum;

    printf("5개의 정수 입력: ");

    for(int i=0; i<5; i++)  //입력받기
    {
        scanf("%d", &arr[i]);
    }
    max=arr[0];
    min=arr[0];
    sum=arr[0];

    for(int j=1; j<=5; j++)
    {
        if(max<=arr[j])
        max=arr[j];

        if(min>arr[j])
        min=arr[j];

        sum+=arr[j];
    }
    printf("최댓값: %d 최솟값: %d 총 합: %d \n", max, min, sum);
    return 0;
}