#include <stdio.h>

int main(void)
{
	/*
	int result;
	int n1, n2;

	printf("정수 one: ");
	scanf("%d", &n1);
	printf("정수 two: ");
	scanf("%d", &n2);

	result=n1+n2;
	printf("%d + %d = %d \n", n1, n2, result);
	*/
	int result;
	int n1, n2, n3;
	printf("세 개의 정수 입력: ");
	scanf("%d %d %d", &n1, &n2, &n3);

	result=n1+n2+n3;
	printf("%d + %d + %d = %d \n", n1, n2, n3, result);
	return 0;
}
