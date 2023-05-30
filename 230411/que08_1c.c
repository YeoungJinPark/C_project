/*전체 평균점수에 대한 학점 출력
90이상 A, 80이상 B, 70이상 C, 50이상 D, 50미만 F
국어, 영어, 수학 순서대로 입력받는다.*/

#include <stdio.h>

int main(void)
{
	int num1, num2, num3;
	double avr;
	char asc;

	printf("국어 점수를 입력해주세요: ");
	scanf("%d", &num1);
	printf("영어 점수를 입력해주세요: ");
	scanf("%d", &num2);
	printf("수학 점수를 입력해주세요: ");
	scanf("%d", &num3);

	avr = (double)(num1+num2+num3)/3;

	if(avr>=90.0)
		asc=65;
	else if(avr>=80)
		asc=66;
	else if(avr>=70)
		asc=67;
	else if(avr>=50)
		asc=68;
	else
		asc=70;

	printf("당신의 평균은%.1f이고 학점은 %c입니다.\n",avr, asc);
	return 0;
}
