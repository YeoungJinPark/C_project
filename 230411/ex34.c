//1, (1+2), (1+2+3), ..., (1+2+...+10)의 합 구하기

#include <stdio.h>

int main(void)
{
	int n=0, sum=0;

	for(int i=0; i<=10; i++)
	{
		n+=i;
		sum+=n;
	}
	printf("결과: %d\n", sum);
	return 0;
}
