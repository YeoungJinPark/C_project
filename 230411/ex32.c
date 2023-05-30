//1부터 10까지의 정수에 대한 약수 구하기

#include <stdio.h>

int main(void)
{
	for(int i=1; i<=10; i++)
	{
		printf("%d의 약수: ", i);
		for(int j=1; j<=i; j++)
		{
			if(i%j==0)
				printf("%d ", j);
		}
		printf("\n");
	}
	return 0;
}
