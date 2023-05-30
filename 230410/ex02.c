//예제 구구단 출력
#include <stdio.h>

int main(void)
{
	int dan=0, num=1;
	printf("몇 단? ");
	scanf("%d", &dan);
	/*
	while(num<10)
	{
		printf("%d×%d=%d \n", dan, num, dan*num);
		num++;
	}*/
	//가로출력
	while(num<10)
	{
		printf("%d×%d=%d ", dan, num, dan*num);
		num++;
	}
	printf("\n");
	return 0;
}
