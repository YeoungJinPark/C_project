//양의 정수를 입력받아 그 수만큼 Hello world 출력

#include <stdio.h>

int main(void)
{
	int num1, num2=1;

	printf("양의 정수 입력: ");
	scanf("%d", &num1);
	while(num2 <= num1)//반복횟수가 입력받은 값 미만이면 종료
	{
		printf("Hello world!\n");
		num2++;
	}
	return 0;
}
