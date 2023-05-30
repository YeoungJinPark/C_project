//출석부 번호에서 랜덤으로 4개 출력

#include <stdio.h>
#include <stdlib.h> // srand()함수 포함 라이브러리
#include <time.h> // time()함수 포함 라이브러리

int main(void)
{
	int num[17];
	int random = 0, permit=0, check=0, except_n=0, except=0, select=0, i=0, j=0;

	srand((unsigned)time(NULL)); // 매번 다른 시드값 생성
	while(1)
	{
		printf("0.종료 1.중복허용 2.중복없음 3.숫자 제외\n 입력: ");
		scanf("%d", &select);
		if(select==0)
		return 0;
		else if(select==1)
		{
			permit=0;
			break;
		}
		else if(select==2)
		{
			permit=1;
			break;
		}
		else if(select==3)
		{
			while(1)
			{
				printf("그만 입력하려면 0");
				printf("제외시킬 숫자 입력: ");
				scanf("%d", &except_n);
				if(except_n==0)
				{
					num[i]='\0';
					except=1;
					break;
				}
				else
				{
					num[i]=except_n;
					i++;
				}
			}
		}
		else
			printf("0~3만 입력해 주세요.\n");
	}
	printf("번호를 뽑을 갯수 입력: ");
	scanf("%d", &select);
	//random = rand()%15+1; // 난수 생성

	for (i=1; i<=select; i++)
		{
			random = rand()%15+1; // 난수 생성
			if(except==1)
			{
				for(j=0; num[j]=='\0'; j++)
				{
					if(random==num[j])
					{
						random = rand()%15+1; // 난수 생성
						j--;
						continue;
					}
					else
					break;
				}
			}

			if(permit==1&&check==random)
			{
				i--;
				continue;
			}

			printf("%d", random); // 출력
			if(i<select)
				printf(", ");
			check = random;
		}
	printf("\n");
	return 0;
}
