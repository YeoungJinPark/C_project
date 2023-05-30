//세 수 중 가장 큰 수 찾기
#include <stdio.h>

int main(void)
{
	int a, b, c;

	printf("가장 큰수를 찾을 세 수 입력: ");
	scanf("%d %d %d", &a, &b, &c);
	
	if(a>b)
	{
		if(a>c)
			printf("가장 큰 수는a:%d\n", a);
		else
			printf("가장 큰 수는c:%d\n", c);
	}
	else
	{
		if(b>c)
			printf("가장 큰 수는b:%d\n", b);
		else
			printf("가장 큰 수는c:%d\n", c);
	}
	return 0;
}
