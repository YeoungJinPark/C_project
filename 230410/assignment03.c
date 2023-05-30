//1~50까지 출력, 한 줄에 5개씩 끊기
//1, 2, 3, 4, 5

#include <stdio.h>

int main(void)
{
	int num1=0, num2=0;

	while(num1<50)
	{
		num2=num1%5;
		while(num2==0)
		{
			printf("\n");
			num2++;
		}
		num1++;
		printf("%d ", num1);
	}
	printf("\n");
	return 0;
}
