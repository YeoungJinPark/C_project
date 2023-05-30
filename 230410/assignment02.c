//1~10까지 출력, 출력할 값이 짝수면 1, 홀수면 0을 같이 출력.

#include <stdio.h>

int main(void)
{
	int num1=1, num2;

	while(num1<11)
	{
		num2=num1%2;
		num2=(!num2);
		printf("%d, %d\n", num1, num2);
		num1++;
	}
	return 0;
}
