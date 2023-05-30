//피보나치수열 구하기

#include <stdio.h>

int main(void)
{
	int a=1, b=1, c;

	printf("%d %d ", a, b);
	
	for(int i=3; i<=20; i++)
	{
		c=a+b;
		printf("%d ", c);
		a=b;
		b=c;
	}
	printf("\n");
	return 0;
}
