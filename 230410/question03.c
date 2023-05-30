//0을 입력할때까지 정수를 계속 입력받고, 입력받은 정수의 합을 출력 후 종료.

#include <stdio.h>

int main(void)
{
	int num=1, result;

	while(num>0 || num<0)
	{
		printf("정수 입력: ");
		scanf("%d", &num);
		result+=num;
	}
	printf("모든 정수의 합: %d\n", result);
	return 0;
}
