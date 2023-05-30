//  함수 이용해서 세 수 중 큰 수 찾기
#include <stdio.h>

int FindMax(int num1, int num2, int num3)
{
    int result=0;

    if(num1>num2)
    {
        if(num1>num3)
        result=num1;
        else
        result=num3;
    }
    else
    {
        if(num2>num3)
        result=num2;
        else
        result=num3;
    }
    return result;
}

int main(void)
{
    int num1, num2, num3;
    int result=0;

    printf("가장 큰 수를 구할 세 정수 입력: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    result=FindMax(num1, num2, num3);
    printf("%d\n", result);
    return 0;
}