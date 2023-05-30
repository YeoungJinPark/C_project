#include <stdio.h>

int main(void)
{
	int n1,n2,n3,result=0;

	printf("계산할 세 정수 입력: ");
	scanf("%d %d %d", &n1, &n2, &n3);
	result=(n1-n2)*(n2+n3)*(n3%n1);
	printf("%d\n", result);
	return 0;
}
