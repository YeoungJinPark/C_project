//최댓값 구하기

#include <stdio.h>

int main(void)
{
	int a, max;

	printf("최댓값을 구할 값 입력: ");
	scanf("%d", &a);
	max=a;

	while(a!=0)
	{
		if(a>max)
			max=a;

		printf("최댓값을 구할 값 입력: ");
		scanf("%d", &a);
	}
	printf("최댓값은: %d\n", max);
	return 0;
}
