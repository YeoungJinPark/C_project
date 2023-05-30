//조별 스터디 문제 정답
//재귀 함수를 이용해 n의 k승의 값을 출력한다. 이때, n과 k의 값을 사용자에게 입력받는다.
#include <stdio.h>

int ToThePower(int n, int k)
{
    if(k==0)
    return 1;
    else
    return n*ToThePower(n, k-1);
}

int main(void)
{
    int n, k, result;

    printf("n의 k승 값을 구합니다.\nn과 k값을 입력해주세요: ");
    scanf("%d %d", &n, &k);

    result=ToThePower(n, k);
    printf("%d의 %d승은 %d\n", n, k, result);
    return 0;
}