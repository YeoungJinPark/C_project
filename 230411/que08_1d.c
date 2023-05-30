//문제08-1의 문제2를 조건 연산자를 이용하는 형태로 변경.

#include <stdio.h>

int main(void)
{
	int num1, num2, result, sub;//subtraction

    printf("차이값을 구할 두 수를 입력: ");
    scanf("%d %d", &num1, &num2);

	sub=num1-num2;
	result = sub>0 ? sub : sub*(-1);

    printf("%d와 %d의 차이값은 %d입니다.\n", num1, num2, result);
    return 0;
}
