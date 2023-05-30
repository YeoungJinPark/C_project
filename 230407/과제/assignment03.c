//두 수를 입력받고 먼저 입력 받은 수가
//두번째로 입력받은 수보다 크면 1, 아니면 0을 출력.
#include <stdio.h>

int main(void)
{
	int num1, num2;

	printf("두 수를 입력: ");
	scanf("%d %d", &num1, &num2);
	printf("%d\n", num1 > num2);
	return 0;
}
