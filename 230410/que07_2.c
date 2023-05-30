#include <stdio.h>

int main(void)
{
	int num1=1, num2=1;
	int result;

	while(num1<6)
	{
		while(num2<1)
		{
			printf("1이상의 정수로 다시 입력해주세요.\n");
			num2=1;
			num1--;
		}
		printf("1이상의 정수를 입력: ");
		scanf("%d", &num2);
		result+=num2;
		num1++;
	}
	printf("정수의 합: %d\n", result);
	return 0;
}
