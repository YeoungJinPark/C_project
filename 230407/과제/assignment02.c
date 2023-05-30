//정수를 입력받아 짝수면 1, 아니면 0을 출력
#include <stdio.h>

int main(void)
{
	int num;
	
	printf("정수를 입력: ");
	scanf("%d", &num);

	printf("%d\n", num%2==0);
	return 0;
}
