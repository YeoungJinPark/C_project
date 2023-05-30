//알파벳 문자 하나를 입력받아 그에 해당하는 아스키 코드 값을 출력.
//ex) 문자 A를 입력하면 정수 65를 출력.
#include <stdio.h>

int main(void)
{
	char character;

	printf("아스키 코드 값을 출력할 알파벳 입력: ");
	scanf("%c", &character);
	
	printf("아스키 코드 값: %d\n", character);
	return 0;
}
