//두 정수 입력받아 차이값을 출력
//단, 큰 수에서 작은 수를 뺀 결과를 출력. 출력 결과는 무조건 0이상

#include <stdio.h>

int main(void)
{
	int num1, num2, result;

	printf("차이값을 구할 두 수를 입력: ");
	scanf("%d %d", &num1, &num2);

	if(num1>num2)
		result=num1-num2;
	else if(num1<num2)
		result=num2-num1;
	else if(num1==num2)
		result=0;
	else
		printf("0이상의 값을 입력해주세요.\n");
	printf("%d와 %d의 차이값은 %d입니다.\n", num1, num2, result);
	return 0;
}
