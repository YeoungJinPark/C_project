//  함수 이용해서 두 수중 큰 수 찾기
#include <stdio.h>

int FindMax(int num1, int num2)
{
    int result=0;
    if(num1>num2)
    result=num1;
    else
    result=num2;

    return result;
}

int main(void)
{
    int num1, num2;
    int result=0;

    printf("둘 중 큰 수를 찾을 두 수 입력: ");
    scanf("%d %d", &num1, &num2);
    result=FindMax(num1, num2);
    
    printf("%d \n", result);
    return 0;
}