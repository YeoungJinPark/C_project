#include <stdio.h>

int main(void)
{
	int n1=10;
	int n2=12;
	int result1, result2, result3;

	result1 = (n1==10 && n2==12);
	result2 = (n1<12 || n2>12);
	result3 = (!n1);

	printf("result1: %d \n", result1);
	printf("result2: %d \n", result2);
	printf("result3: %d \n", result3);
	return 0;
}

