/*나이에 따른 공원 입장료
  8세 미만 무료
  8세 이상 60세 미만 5,000원
  60세 이상 무료*/

#include <stdio.h>

int main(void)
{
	int age;
	
	printf("나이를 입력해 주세요: ");
	scanf("%d", &age);

	if(age<8 || age>=60)
		printf("입장료는 무료입니다.\n");
	else
		printf("입장료는 5,000원 입니다.\n");

	return 0;
}
