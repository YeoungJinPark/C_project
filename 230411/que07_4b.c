//n! = 1x2x3x‥ xn에서 n을 입력받아 n의 계승 n!을 계산해 출력
#include <stdio.h>

int main(void)
{
	int n;
	int result=1;

	printf("정수 입력: ");
	scanf("%d", &n);
	for(int i=1; i<n+1; i++)
	{
		result*=i;
	}
	printf("n! : %d\n", result);
	return 0;
}
