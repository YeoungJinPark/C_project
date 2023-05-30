//두 수를 입력받아 두 수의 합이 0이상이고
//앞의 수로 뒤의 수를 나누었을 때
//나머지가 1 이상이면 1, 아니면 0을 출력
#include <stdio.h>

int main(void)
{
	int num1, num2;

	printf("두 수를 입력: ");
	scanf("%d %d", &num1, &num2);
	printf("%d\n", (num1+num2)>=0 && num1%num2>=1);

	return 0;
}
