#include <stdio.h>

int Fibo(int num)
{
    int result=0;

    if(num<=2)
    result=1;
    else
    result=Fibo(num-1)+Fibo(num-2);

    return result;
}

int main(void)
{
    int num=0, result=0;

    printf("피보나치 수열 구하기\n");
    printf("정수값 입력: ");
    scanf("%d",&num);

    result = Fibo(num);

    printf("%d\n", result);
    return 0;
}