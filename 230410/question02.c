//3의 배수를 출력할 횟수를 입력받아 횟수만큼 3의 배수 출력.

#include <stdio.h>

int main(void)
{
	int num1, num2=1, num3=3;

	printf("양의 정수 입력: ");
	scanf("%d", &num1);
	
	while(num2<=num1)
	{
		printf("%d\n", num3);
		num3 += 3;
		num2++;
	}
	return 0;
}
