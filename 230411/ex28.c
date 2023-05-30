//소수 판별하기

#include <stdio.h>

int main(void)
{
	int chk=1;
	int n;

	printf("소수인지 판별할 값 입력: ");
	scanf("%d", &n);

	for(int i=2; i<=n-1; i++)
		if(n%i==0)
		{
			chk=0;
			break;
		}
	if(chk==1)
		printf("%d은(는) 소수입니다.\n", n);
	else
		printf("%d은(는) 소수가 아닙니다.\n", n);
	return 0;
}
