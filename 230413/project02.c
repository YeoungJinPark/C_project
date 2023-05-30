/* 춘식이는 매턴 밥을 먹는다.
   기본 몸무게 20kg 애정도: 0
   매턴 애정도 5 증가.
   밥먹으면 몸무게 증가 0.3kg, 50% 확률로 똥(몸무게 -0.2kg)
   매턴 10%확률 병걸림
   병에 걸리면 몸무게 -0.5kg(밥먹기 중지)
   병에 걸리면 매턴 애정도만큼의 확률로 회복
   병에 걸리면 매턴 10% 확률로 사망
   목표는 100kg까지 키우기
   종료시 몸무게, 애정도 출력
   매턴 문구 출력
   몸무게에 따른 춘식이 크기 변화 출력*/

#include <stdio.h>
#include <stdlib.h>	//srand()함수 포함 라이브러리
#include <time.h>	//time()함수 포함 라이브러리

int main(void)
{
	int death, recovery, poop, sick_percent, sick=0, love=0, turn=1, win=0;
	double weight=20.0, size=weight;
	srand((unsigned)time(NULL)); //실행마다 다른 난수값 생성

	while(1)
	{
		printf("%d번째 턴. \n", turn);
		sick_percent=rand()%10+1;	//병걸릴 확률 랜덤생성
		recovery=rand()%10+1;    //회복할 확률
        death=rand()%10+1;   //사망할 확률
        poop=rand()%10+1;    //밥을 먹은 후 똥을 쌀 확률

		if(sick==1)	//병에 걸렸는지 체크
		{
			weight-=0.5;
			size=size+(weight-size);
			printf("춘식이가 병에 걸린 상태이고 밥을 굶습니다.(몸무게-0.5kg)\n");

			if(recovery<love*0.1)	//애정도x0.1만큼의 확률로 회복			
			{
				printf("당신의 애정에 춘식이가 회복되었습니다.\n");
				sick=0;
			}
			else
			{
				if(death<2)	//사망 체크
				{
					printf("춘식이가 병이 악화돼 사망했습니다.\n Game Over\n");
					break;
				}
				printf("당신의 애정이 부족해 춘식이가 회복하지 못했습니다.\n");
			}
		}
		else if(turn>1 && sick_percent<2)	//병에 걸리지 않은 상태라면 병에 걸릴 확률 체크
		{
			sick=1;
			printf("춘식이가 병에 걸렸습니다.\n");
			weight-=0.5;
			size=size+(weight-size);
            printf("춘식이가 병에 걸린 상태이고 밥을 굶습니다.(몸무게-0.5kg)\n");
		}
		else	//병에 걸리지 않은 상태이고 병에 걸릴 확률도 피했다면 밥을 먹는다
		{
			weight+=0.3;
			printf("춘식이가 밥을 먹어 살이 찝니다.(몸무게 +0.3kg)\n");
			size=size+(weight-size);

			if(weight>=100)	//몸무게가 100을 넘기면 즉시 턴을 종료하고 승리
			{
				win=1;
				break;
			}
			
			if(poop<6)
			{
				printf("춘식이가 똥을 쌌습니다.(몸무게 -0.2kg)\n");
				weight-=0.2;
				size=size+(weight-size);
			}
		}
		turn++;
		love+=5;
		printf("춘식이와 함께하는 만큼 애정도가 증가합니다.(애정도+5)\n");
		printf("몸무게: %.1f 애정도: %d\n\n", weight, love);
	}
	if(win)
		printf("춘식이가 무사히 100kg이상으로 거대해졌습니다.\n승리 !\n");
	printf("최종 몸무게: %.1f 애정도: %d\n", weight, love);
	return 0;
}
