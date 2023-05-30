#include <stdio.h>

void PrintEven(int *num, int len)
{
    int i;
    printf("짝수 출력: ");
    for(i=0; i<len; i++)
    {
        if(num[i]%2==0)
        {
            printf("%d", num[i]);
            if(i==len-1)
            break;
            else
            printf(", ");
        }
    }
    printf("\n");
}

void PrintOdd(int *num, int len)
{
    int i;
    printf("홀수 출력: ");
    for(i=0; i<len; i++)
    {
        if(num[i]%2!=0)
        {
            printf("%d", num[i]);
            if(i==len-2)
            break;
            else
            printf(", ");
        }
    }
    printf("\n");
}

int main(void)
{
    int arr[10];

    printf("10개의 정수 입력\n");
    for(int i=0; i<10; i++)
    {
        printf("입력: ");
        scanf("%d", &arr[i]);
    }
    PrintOdd(arr, 10);
    PrintEven(arr, 10);
    return 0;
}