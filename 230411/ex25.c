//약수 구하기

#include <stdio.h>

int main(void)
{
	int n;

	printf("약수를 구할 값 입력: ");
	scanf("%d", &n);
	printf("%d의 약수는: ", n);

	for(int i=1; i<=n; i++)
	{
		if(n%i==0)
			printf("%d ", i);
	}
	printf("입니다. \n");
	return 0;
}
