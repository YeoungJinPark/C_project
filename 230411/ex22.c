//1부터 100까지의 수 중 짝수의 합 구하기

#include <stdio.h>

int main(void)
{
	int sum=0;

	for(int i=1; i<=100; i++)
		if(i%2==0)
			sum+=i;
	printf("짝수의 합:%d\n", sum);
	
	return 0;
}
