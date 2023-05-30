//c언어 점수 입력받아 성적표 출력
#include <stdio.h>

int main(void)
{
	int num1, num2, num3, num4, num5;
	float average, average1, average2, average3, average4, average5;
	
	printf("박영선님의 C언어 점수 입력: ");
	scanf("%d", &num1);
	printf("한  설님의 C언어 점수 입력: ");
	scanf("%d", &num2);
	printf("이태윤님의 C언어 점수 입력: ");
	scanf("%d", &num3);
	printf("박장미님의 C언어 점수 입력: ");
	scanf("%d", &num4);
	printf("김가영님의 C언어 점수 입력: ");
	scanf("%d", &num5);
	
	average=num1+num2+num3+num4+num5;
	average1=85+80+65+num1;
	average2=85+75+95+num2;
	average3=85+90+80+num3;
	average4=85+80+75+num4;
	average5=85+95+60+num5;
	
	printf("             성적표\n");
	printf("----------------------------------------\n");
	printf("       국어 영어 수학 C언어 평균\n");
	printf("박영선  85   80   65   %d   %.1f\n", num1, average1/4);
	printf("한  설  85   75   95   %d   %.1f\n", num2, average2/4);
	printf("이태영  85   90   80   %d   %.1f\n", num3, average3/4);
	printf("박장미  85   80   75   %d   %.1f\n", num4, average4/4);
	printf("김가영  85   95   60   %d   %.1f\n", num5, average5/4);
	printf("평  균 85.0 84.0 75.0 %.1f\n", average/5);
	printf("----------------------------------------\n");
	return 0;
}
