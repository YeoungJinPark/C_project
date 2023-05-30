//1~50 출력 한 줄의 길이를 정수로 입력받기

#include <stdio.h>

int main(void)
{
	int num1, num2=0, num3=0;

	printf("한 줄의 길이 입력: ");
	scanf("%d", &num1);
	while(num2<50)
	{
		while(num3==num1)
		{
			printf("\n");
			num3=0;
		}
		num2++;
		num3++;
		printf("%d ", num2);
	}
	printf("\n");
	return 0;
}
