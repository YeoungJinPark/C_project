//x,y 좌표 입력받아 두 점이루는 직사각형 넓이 계산하여 출력
//단, 좌 상단의 x,y 좌표 값이 우 하단의 x,y 좌표 값보다 작다고 가정,
//좌 상단의 좌표정보를 먼저 입력받는다.

#include <stdio.h>

int main(void)
{
	int x1, y1, x2, y2;
	int result1, result2, result3;

	printf("좌 상단의 x, y 좌표: ");
	scanf("%d %d", &x1, &y1);
	printf("우 상단의 x, y 좌표: ");
	scanf("%d %d", &x2, &y2);

	result1=x1-x2;
	result2=y1-y2;
	result3=result1*result2;

	printf("두 점이 이루는 직사각형의 넓이는 %d입니다.\n", result3);

	return 0;
}
