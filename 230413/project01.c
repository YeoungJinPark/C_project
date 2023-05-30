//출석부 번호에서 랜덤으로 4개 출력

#include <stdio.h>
#include <stdlib.h> // srand()함수 포함 라이브러리
#include <time.h> // time()함수 포함 라이브러리

int main(void)
{
	int random = 0, permit=0, check=0, select;

	srand((unsigned)time(NULL)); // 매번 다른 시드값 생성
	while(select<0||select>2)
	{
		printf("0. 종료 1. 중복허용 2. 중복없음\n 입력: ");
		scanf("%d", &select);
		if(select==0)
			return 0;
		else if(select==1)
			permit=1;
		else if(select==2)
			permit=0;
		else
			printf("0~2만 입력해 주세요.\n");
	}
	printf("추첨 번호: ");
	for (int i=1; i<=4; i++) // 4번 반복
		{
			random = rand()%16+1; // 난수 생성

			if(permit==1&&check==random)
			{
				i--;
				continue;
			}

			printf("%d", random); // 출력
			if(i<4)
				printf(", ");
			check = random;
		}
	printf("\n");
	return 0;
}
