//홀수, 짝수 판별하기
#include <stdio.h>

int main(void)
{
	int a;

	printf("홀,짝 판별할 수 입력: ");
	scanf("%d", &a);

	if(a%2==0)
		printf("%d은(는) 짝수.\n", a);
	else
		printf("%d은(는) 홀수.\n", a);

	return 0;
}
