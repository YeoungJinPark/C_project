/*
아스키 코드 값을 정수형태로 입력 받고 받은 정수의 아스키 코드를 문자로 출력.
ex) 정수 65를 입력하면 문자 A를 출력 한다.
*/
#include <stdio.h>

int main(void)
{
	int num;

	printf("아스키 코드 값 입력: ");
	scanf("%d", &num);

	printf("출력문자: %c\n", num);
	return 0;
}
