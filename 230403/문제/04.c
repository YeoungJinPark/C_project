#include <stdio.h>

int main(void)
{
	int n1,n2,r1,r2=0;

	printf("나눗셈 할 두 정수 입력 : ");
	scanf("%d %d", &n1, &n2);
	r1=n1/n2;
	r2=n1%n2;
	printf("몫:%d 나머지:%d\n", r1, r2);
	return 0;
}
