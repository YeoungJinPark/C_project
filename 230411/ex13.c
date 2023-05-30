//3의 배수 판별하기

#include <stdio.h>

int main(void)
{
	int a;

	printf("3의 배수를 판별할 값 입력: ");
	scanf("%d", &a);

	if(a%3==0)
		printf("%d은(는) 3의 배수입니다.\n", a);
	else
		printf("%d은(는) 3의 배수가 아닙니다.\n", a);
	
	return 0;
}
