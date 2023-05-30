//1부터 100까지의 수 중 짝수의 합 구하기

#include <stdio.h>

int main(void)
{
	int sum=0;

	for(int i=2; i<=100; i+=2)
		sum+=i;
	printf("짝수의 합:%d\n", sum);
	return 0;
}
