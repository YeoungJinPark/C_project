#include <stdio.h>

int main(void)
{
	int num, result=0;

	printf("제곱할 값을 입력 : ");
	scanf("%d", &num);
	result=num*num;
	printf("%d\n", result);
	return 0;
}
