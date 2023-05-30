/* 사용자에게 입력받으면 고맙다고 인사.
   정수를 입력받으면 아이고~ 고맙습니다
   두 수를 입력받으면 뭐~ 이런걸 다~ ^^
   두 수를 입력받았을 때 합이 5 이상이면
   조금 더 쓰시지?
   나누어 떨어지면 이럴수가?! */

#include <stdio.h>

int main(void)
{
	int i=0, j=0;
	int num1, num2;

		printf("정수 입력: ");
		scanf("%d %d", &num1, &num2);
		return 0;
}
