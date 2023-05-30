//두 개의 실수를 입력 받아서 double형 변수에 저장하고 사칙연산 결과를 출력

#include <stdio.h>

int main(void)
{
	double num1, num2;

	printf("두 실수를 입력: ");
	scanf("%lf %lf", &num1, &num2);

	printf("덧셈: %g \n", num1+num2);
	printf("뺄셈: %g \n", num1-num2);
	printf("곱셈: %g \n", num1*num2);
	printf("나눗셈 몫: %g \n", num1/num2);

	return 0;
}
