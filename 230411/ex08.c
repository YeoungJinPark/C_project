//두 수 중 큰 수 찾기

#include <stdio.h>

int main(void)
{
	int a, b;

	printf("두 수 입력: ");
	scanf("%d %d", &a, &b);

	if(a>b)
		printf("%d는(은) %d보다 크다\n", a, b);
	else
		printf("%d는(은) %d보다 크거나 같다\n", b, a);
	return 0;
}
