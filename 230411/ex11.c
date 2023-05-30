//세 수 중 가장 큰 수 찾기
#include <stdio.h>

int main(void)
{
	int max;
	int a;
	
	printf("첫번째 수 입력: ");
	scanf("%d", &max);
	printf("두번째 수 입력: ");
	scanf("%d", &a);

	if(a>max)
		max=a;

	printf("세번째 수 입력: ");
	scanf("%d", &a);
	
	if(a>max)
		max=a;
	
	printf("가장 큰 수: %d\n", max);
	return 0;
}
