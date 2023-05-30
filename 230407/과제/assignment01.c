//정수 입력받아 받은 수가 3의 배수면 1이나 0을 출력
#include <stdio.h>

int main(void)
{
	int num;

	printf("정수를 입력: ");
	scanf("%d", &num);
	printf("%d\n", num%3==0 && num>0);
	return 0;
}
