//정수 두개 입력받아 두 정수포함 그 사이의 정수들의 합을 계산하여 출력

#include <stdio.h>

int main(void)
{
	int num1, num2;
	int sum=0;

	printf("두 정수 입력: ");
	scanf("%d %d", &num1, &num2);

	for( ; num1>num2 ;)
	{
		printf("두번째 값이 더 크게 입력해 주세요.\n");
		scanf("%d %d", &num1, &num2);
	}
	for(int i=num1; i<num2+1; i++)
	{
		sum+=i;
	}
	printf("두 정수 사이의 합: %d\n", sum);
	return 0;
}
