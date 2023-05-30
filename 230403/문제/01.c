#include <stdio.h>

int main(void)
{
	int n1, n2 = 0;
	int result = 0;
	
	printf("계산할 두 정수 입력: ");
	scanf("%d %d", &n1, &n2);
	result=n1-n2;
	printf("뺄셈 : %d\n", result);
	result=n1*n2;
	printf("곱셈 : %d\n", result);
	return 0;
}
	
	
