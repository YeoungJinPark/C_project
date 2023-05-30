#include <stdio.h>

int Sum(int num)
{
    int result=0;

    if(num<=1)
    result=1;
    else
    result=num+Sum(num-1);

    return result;
}

int main(void)
{
    int num=0, result=0;

    printf("1부터 n수까지의 합을 구하는 프로그램\n");
    printf("n값을 입력: ");
    scanf("%d", &num);

    result=Sum(num);
    printf("%d\n", result);
    return 0;
}