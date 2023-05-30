#include <stdio.h>

int main(void)
{
	int num1=1, num2;

	while(num1<6)
	{
		num2=1;
		while(num1>num2)
		{
			printf("o ");
			num2++;
		}
		printf("*\n");
		num1++;
	}
	
	return 0;
}	
