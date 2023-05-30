//입력받은 정수의 평균 출력
//조건1. 정수를 입력받을 횟수를 입력받고, 그 수만큼 정수를 입력받는다.
//조건2. 평균 값은 소수점 이하까지 계산해서 출력한다.
#include <stdio.h>

int main(void)
{
	int num1, num2=0;
	float num3, ave=0;//average

	printf("정수를 입력할 횟수: ");
	scanf("%d", &num1);

	while(num1>num2)
	{
		printf("정수 입력: ");
		scanf("%f", &num3);
		ave+=num3;
		num2++;
	}
	printf("평균: %.2f\n", ave/num1);
	return 0;
}
