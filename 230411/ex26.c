//공약수 구하기

#include <stdio.h>

int main(void)
{
	int n1, n2;

	printf("공약수를 구할 두 정수 입력: ");
	scanf("%d %d", &n1, &n2);
	printf("%d와 %d의 공약수는: ", n1, n2);

	for(int i=1; i<=n1; i++)
	{
		if(n1%i==0 && n2%i==0)
			printf("%d ", i);
	}
	printf("입니다.\n");
	return 0;
}
