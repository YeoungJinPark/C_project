//최대공약수 구하기

#include <stdio.h>

int main(void)
{
	int n1, n2;

	printf("최대공약수를 구할 두 정수 입력: ");
	scanf("%d %d", &n1, &n2);

	for(int i=n1; i>=1; i--)
		if(n1%i==0&&n2%i==0)
		{
			printf("%d와 %d의 최대공약수는 %d입니다.\n", n1, n2, i);
			break;
		}
	return 0;
}
