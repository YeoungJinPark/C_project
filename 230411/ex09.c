//양수, 0, 음수 판별
#include <stdio.h>

int main(void)
{
	int a;

	printf("양수,0,음수를 판별할 값 입력: ");
	scanf("%d", &a);

	if(a<0)
		printf("음수\n");
	else if(a>0)
		printf("양수\n");
	else
		printf("0\n");

	return 0;
}
