//문자 두 개를 입력받아 두 문자의 아스키 코드 값의 차이를 구하기
#include <stdio.h>

int main(void)
{
	char chr1, chr2;
	
	printf("알파벳 두 개를 입력: ");
	scanf("%c %c", &chr1, &chr2);
	printf("차이값:%d\n", chr1-chr2);
	return 0;
}
