/*자판기 메뉴
  콜라 1,200 우주맛 콜라 1,900 제로콜라 1,200 스프라이트 1,100
  환타 900 닥터페퍼 1,100 몬스터 1,800 파워에이드 1,900 네스티 1,600
  글라소 비타민 워터 2,100 미닛메이드 1,700 조지아 커피 900 암바사 900 마테차 1,700
  
  돈을 먼저 입력 받아 넣고 원하는 음료를 선택 한다.
  1)콜라~14)마테차 S)계산 하기 X)종료하기

  계산 하기 전까지는 선택한 음료는 저장.
  총 금액의 합산을 변수에 저장하여 입력한 돈과 비교하여 계산.
  입력한 돈이 주문의 합보다 적으로 돈이 부족하다고 하면서 종료 시킨다.

  변수 이름은 영어로만.

  모든 음료를 선택, 주문 다하고 계산하기 직전에 작은 별이 깜빡이게
  자판기 최상단에 코카콜라 자판기 만의 깜빡임이나 모양 출력*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void)
{
	int menu=0, money_in, money_out=0, money_now=0, pay=0, cal=0;
	char select='\0';

	printf("투입할 금액 입력: ");
    scanf("%d", &money_in);
    money_now+=money_in;
    money_out+=money_in;

	while(1)//자판기 모양
	{
		system("clear");
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                                                                                        ┃\n");
		printf("┃ 1) 콜라      2)우주맛 콜라   3)제로콜라    4)스프라이트     5)환타        6)닥터페퍼   ┃\n");
		printf("┃ ┌──────┐       ┌──────┐       ┌──────┐       ┌──────┐       ┌──────┐       ┌──────┐    ┃\n");
		printf("┃ │1200원│       │1900원│       │1200원│       │1100원│       │ 900원│       │1100원│    ┃\n");
		printf("┃ └──────┘       └──────┘       └──────┘       └──────┘       └──────┘       └──────┘    ┃\n");
		printf("┃                                                                                        ┃\n");
		printf("┃                                             10)글라소                                  ┃\n");
		printf("┃ 7)몬스터     8)파워에이드     9)네스티     비타민 워터   11)미닛메이드   12)조지아커피 ┃\n");
		printf("┃ ┌──────┐       ┌──────┐       ┌──────┐       ┌──────┐       ┌──────┐       ┌──────┐    ┃\n");
        printf("┃ │1800원│       │1900원│       │1600원│       │2100원│       │1700원│       │ 900원│    ┃\n");
        printf("┃ └──────┘       └──────┘       └──────┘       └──────┘       └──────┘       └──────┘    ┃\n");
		printf("┃                                                                                        ┃\n");
		printf("┃                                                                                        ┃\n");
		printf("┃ 13)암바사     14)마테차                                                                ┃\n");
		printf("┃ ┌──────┐      ┌──────┐        ┌──────┐       ┌──────┐       ┌──────┐       ┌──────┐    ┃\n");
        printf("┃ │ 900원│      │1700원│        │   X  │       │   X  │       │   X  │       │   X  │    ┃\n");
        printf("┃ └──────┘      └──────┘        └──────┘       └──────┘       └──────┘       └──────┘    ┃\n");
		printf("┃                                                                                        ┃\n");
		printf("┃                                                                           W)금액투입   ┃\n");
		printf("┃                                                                           S)계산하기   ┃\n");
		printf("┃                                                                           X)종료하기   ┃\n");
		printf("┃                                                                           E)음료선택   ┃\n");
		printf("┃                                                                                        ┃\n");
		printf("                                                                       투입금액: %d원\n", money_now);
		
		if(cal==1)
		{
			printf("계산중.                                                                  ★ ☆ ☆\n");
			cal=2;
			fflush(stdout);
			sleep(1);
			system("clear");
			continue;
		}
		else if(cal==2)
		{
			printf("계산중..                                                                 ☆ ★ ☆\n");
			cal=3;
			fflush(stdout);
			sleep(1);
			system("clear");
			continue;
		}
		else if(cal==3)
		{
			printf("계산중...                                                                ☆ ☆ ★\n");
			cal=0;
			fflush(stdout);
			sleep(1);
			if(money_out<pay)
			{
				printf("잔액이 부족합니다.\n");
				return 0;
			}
			else
			{
				printf("거스름돈: %d원\n", money_out);
				money_out=0;
				money_now=0;
				pay=0;
			}
		}
		else
			cal=0;

		if(select==0)
			select='\0';
		else if(select==69||select==101)
		{
			printf("메뉴 선택: ");
			scanf("%d", &menu);

			if(menu==0)
				menu=0;
			else if(menu==1)			//콜라 1200
			{
				printf("콜라1,200원\n");
				pay+=1200;
			}
			else if(menu==2)	//우주맛 콜라1900
			{
				printf("우주맛 콜라1,900원\n");
				pay+=1900;
			}
			else if(menu==3)	//제로콜라1200
			{
				printf("제로콜라1,200원\n");
				pay+=1200;
			}
			else if(menu==4)	//스프라이트1100
			{
				printf("스프라이트1,100원\n");
				pay+=1100;
			}
			else if(menu==5)	//환타900
			{
				printf("환타900원\n");
				pay+=900;
			}
			else if(menu==6)	//닥터페퍼1100
			{
				printf("닥터페퍼1,100원\n");
				pay+=1100;
			}
			else if(menu==7)	//몬스터1800	
			{
				printf("몬스터1,800원\n");
				pay+=1800;
			}
			else if(menu==8)	//파워에이드1900
			{
				printf("파워에이드1,900원\n");
				pay+=1900;
			}
			else if(menu==9)	//네스티1600
			{
				printf("네스티1,600원\n");
				pay+=1600;
			}
			else if(menu==10)	//글라소 비타민 워터
			{
				printf("글라소 비타민 워터2,100원\n");
				pay+=2100;
			}
			else if(menu==11)	//미닛메이드1700
			{
				printf("미닛메이드1,700원\n");
				pay+=1700;
			}
			else if(menu==12)	//조지아 커피900
			{
				printf("조지아 커피900원\n");
				pay+=900;
			}
			else if(menu==13)	//암바사900
			{
				printf("암바사900원\n");
				pay+=900;
			}
			else if(menu==14)	//마테차1700
			{
				printf("마테차1,700원\n");
				pay+=1700;
			}
			else
				printf("없는 메뉴입니다.\n");
		}
		else if(select==83||select==115)		//계산 하기
	    {
			cal=1;	
			select=0;
			continue;
		}
		else if(select==88||select==120)		//종료
		{
			printf("종료합니다.\n");
			return 0;
		}
		else if(select==87||select==119)		//추가금액 투입
		{
			printf("투입할 금액 입력: ");
			scanf("%d", &money_in);
			money_now+=money_in;
			money_out+=money_in;
		}

		printf("무엇을 하시겠습니까?  ");
		scanf(" %c", &select);
		printf("\n");
	}
	return 0;
}
