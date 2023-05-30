//알파벳 소문자 입력받아 대문자로 바꾸어 출력
#include <stdio.h>

int main(void)
{
	char chr;

	printf("알파벳 소문자를 입력: ");
	scanf("%c", &chr);
	printf("%c\n", chr-32);
	return 0;
}
