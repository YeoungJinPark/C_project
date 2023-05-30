//입력받은 단의 구구단을 역순으로 출력
//9단 이하는 9×9단으로, 10단이상은 19×19단으로 출력한다.
#include <stdio.h>

int main(void)
{
	int dan, num=9;
	
	printf("몇 단?: ");
	scanf("%d", &dan);
	while(dan<=9&&num>0)
	{
		printf("%d×%d=%d\n", dan, num, dan*num);
		num--;
	}
	num=19;
	while(dan>9&&num>0)
	{
		printf("%d×%d=%d\n", dan, num, dan*num);
		num--;
	}
	return 0;
}
