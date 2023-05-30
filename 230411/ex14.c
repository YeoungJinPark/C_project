/*나이에 따른 입장료
  8세 미만: 0
  8세 이상~60세 미만 : 5,000
  60세 이상 : 2,500 */

#include <stdio.h>

int main(void)
{
	double charge=5000;
	int age;

	printf("나이를 입력해주세요: ");
	scanf("%d", &age);

	if(age<8)
		printf("입장료는 0원 입니다.\n");
	else if(age<60)
		printf("입장료는 %.0f원 입니다.\n", charge);
	else
		printf("입장료는 %.0f원 입니다.\n", charge*0.5);

	return 0;
}
