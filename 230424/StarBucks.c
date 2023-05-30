#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    //메뉴 이름
    const char *menu_coffee[8]={" ", "아메리카노", "카페라떼", "카푸치노", "카라멜 마키아또", "화이트 초콜릿 모카", "카페모카", "스타벅스 돌체라떼"};
    const char *menu_coldbrew[5]={" ", "콜드브루 오트라떼", "돌체 콜드브루", "바닐라 크림 콜드브루", "콜드브루"};
    const char *menu_frappuccino[10]={" ", "더블 에스프레소 칩 프라푸치노", "제주 유기농 말차로 만든 크림 프라푸치노", "자바 칩 프라푸치노"
    , "초콜릿 크림칩 프라푸치노", "화이트 초콜릿 모카 푸라푸치노", "모카 푸라푸치노", "카라멜 푸라푸치노", "에스프레소 프라푸치노", "바닐라크림 프라푸치노"};
    const char *menu_blended[6]={" ", "민트 초콜릿 칩 블렌디드", "딸기 딜라이트 요거트 블렌디드", "피치 & 레몬 블렌디드", "망고 바나나 블렌디드", "망고 패션 프루트 블렌디드"};
    const char *menu_fizzio[4]={" ", "쿨라임 피지오", "블랙티 레모네이드 피지오", "패션 탱고 티 레모네이드 피지오"};
    const char *menu_tea[9]={" ", "뉴이어 시트러스 티", "돌체 블랙 밀크티", "유자 민트 티", "패션 프루트 티", "제주 유기농 말차로 만든 라떼", "차이 티 라떼", 
    "라임 패션 티", "자몽 허니 블랙티"};
    //사이즈
    const char* size[4]={"Short", "Tall", "Grande", "Venti"};
    //메뉴 가격
    int price_coffee[8][5]=
                          {
                            {0, 0, 0, 0, 0},
                            {0, 4000, 4500, 5000, 5500},
                            {0, 4500, 5000, 5500, 6000},
                            {0, 4500, 5000, 5500, 6000},
                            {0, 5400, 5900, 6400, 6900},
                            {0, 5400, 5900, 6400, 6900},
                            {0, 5000, 5500, 6000, 6500},
                            {0, 5400, 5900, 6400, 6900}
                          };
    int price_coldbrew[5][4]=
                            {
                                {0, 0, 0, 0},
                                {0, 5800, 6300, 6800},
                                {0, 6000, 6500, 7000},
                                {0, 5800, 6300, 6800},
                                {0, 4900, 5400, 5900}
                            };
    int price_frappuccino[10][4]=
                                {
                                    {0, 0, 0, 0},
                                    {0, 6300, 6800, 7300},
                                    {0, 6300, 6800, 7300},
                                    {0, 6300, 6800, 7300},
                                    {0, 6000, 6500, 7000},
                                    {0, 6000, 6500, 7000},
                                    {0, 6000, 6500, 7000},
                                    {0, 5900, 6400, 6900},
                                    {0, 5500, 6000, 6500},
                                    {0, 5500, 6000, 6500}
                                };
    int price_blended[6][4]=
                            {
                                {0, 0, 0, 0},
                                {0, 6300, 6800, 7300},
                                {0, 6300, 6800, 7300},
                                {0, 6300, 6800, 7300},
                                {0, 6300, 6800, 7300},
                                {0, 5400, 5900, 6400}
                            };
    int price_fizzio[4][4]=
                            {
                                {0, 0, 0, 0},
                                {0, 5900, 6400, 6900},
                                {0, 5400, 5900, 6400},
                                {0, 5400, 5900, 6400}
                            };
    int price_tea[9][4]=
                        {
                            {0, 0, 0, 0},
                            {0, 6100, 6600, 7100},
                            {0, 5900, 6400, 6900},
                            {0, 5900, 6400, 6900},
                            {0, 5900, 6400, 6900},
                            {0, 6100, 6600, 7100},
                            {0, 5500, 6000, 6500},
                            {0, 5900, 6400, 6900},
                            {0, 5700, 6200, 6700}
                        };
    //[사이즈][메뉴종류] 사이즈별 메뉴수량 저장                        
    int size_coffee[4][8]={{0, }, };
    int size_coldebrew[4][5]={{0, }};
    int size_frappuccino[4][10]={{0, }};
    int size_blended[4][6]={{0, }};
    int size_fizzio[4][4]={{0, }};
    int size_tea[4][9]={{0, }};

    //장바구니 가격 저장
    int cart_coffee[8]={0, };
    int cart_coldbrew[5]={0, };
    int cart_frappuccino[10]={0, };
    int cart_blended[6]={0, };
    int cart_fizzio[4]={0, };
    int cart_tea[9]={0, };

    //카테고리별 총매출액
    int revenue_coffee=0;
    int revenue_coldbrew=0;
    int revenue_frappuccino=0;
    int revenue_blended=0;
    int revenue_fizzio=0;
    int revenue_tea=0;

    int i=0, j=0, s_category, s_menu, s_size, s_num, s_member, daily_total=0, cnt=1;
    // for문 사용   카테고리    메뉴    사이즈   수량    등급      일매출 총합  메뉴별 주문내역
    double total=0;     //할인을 위해 double형으로 선언
    double member[4]={0, 0.05, 0.15, 0.15};    //등급에 따른 할인
    fflush(stdout);
    
    while(1)
    {
        system("clear");
        printf("0.계산하기 1.커피 2.콜드브루 3.프라푸치노 4.블렌디드 5.피지오 6.티 7.일 매출 정산 8.종료\n");
        printf("카테고리를 선택해주세요.\n");
        scanf("%d", &s_category);

        switch(s_category)
        {
            case 0:     //계산하기
            break;

            case 1:     //커피
            system("clear");
            printf("스타벅스 커피 메뉴\n");
            printf("--------------------------------------------------------\n");
            printf("    메뉴                short   Tall   Grande   Venti\n");
            printf("1.%s            %d    %d    %d    %d\n", menu_coffee[1], price_coffee[1][1], price_coffee[1][2], price_coffee[1][3], price_coffee[1][4]);
            printf("2.%s              %d    %d    %d    %d\n", menu_coffee[2], price_coffee[2][1], price_coffee[2][2], price_coffee[2][3], price_coffee[2][4]);
            printf("3.%s              %d    %d    %d    %d\n", menu_coffee[3], price_coffee[3][1], price_coffee[3][2], price_coffee[3][3], price_coffee[3][4]);
            printf("4.%s       %d    %d    %d    %d\n", menu_coffee[4], price_coffee[4][1], price_coffee[4][2], price_coffee[4][3], price_coffee[4][4]);
            printf("5.%s    %d    %d    %d    %d\n", menu_coffee[5], price_coffee[5][1], price_coffee[5][2], price_coffee[5][3], price_coffee[5][4]);
            printf("6.%s              %d    %d    %d    %d\n", menu_coffee[6], price_coffee[6][1], price_coffee[6][2], price_coffee[6][3], price_coffee[6][4]);
            printf("7.%s     %d    %d    %d    %d\n", menu_coffee[7], price_coffee[7][1], price_coffee[7][2], price_coffee[7][3], price_coffee[7][4]);
            printf("--------------------------------------------------------\n");
            printf("0.돌아가기\n");
            printf("메뉴를 선택해주세요.\n");
            scanf("%d", &s_menu);
            if(s_menu<0||s_menu>7)
            {
                printf("없는 메뉴입니다.\n");
                usleep(750000);
                continue;
            }

            if(s_menu==0)
            continue;

            printf("1.Short 2.Tall 3.Grande 4.Venti\n");
            printf("사이즈를 선택해주세요\n");
            scanf("%d", &s_size);
            if(s_size<1||s_size>4)
            {
                printf("없는 사이즈입니다.\n");
                usleep(750000);
                continue;
            }
            printf("수량을 선택해 주세요\n");
            scanf("%d", &s_num);
            if(s_num<1)
            {
                printf("1개 이상 골라주세요\n");
                usleep(750000);
                continue;
            }
            for(i=1; i<=s_num; i++)
            {
                size_coffee[s_size][s_menu]+=1; //사이즈별 메뉴수량을 저장[사이즈1~4][메뉴종류]
                cart_coffee[s_menu]+=price_coffee[s_menu][s_size];  //메뉴별로 장바구니에 메뉴에따른 사이즈별 가격 저장
            }
            printf("%s %s 사이즈 %d개가 장바구니에 추가되었습니다.\n", menu_coffee[s_menu], size[s_size-1], s_num); //short는 커피메뉴에만 있기때문에 -1
            usleep(650000);
            continue;

            case 2:     //콜드브루
            system("clear");
            printf("스타벅스 콜드브루 메뉴\n");
            printf("--------------------------------------------------------\n");
            printf("    메뉴                Tall   Grande   Venti\n");
            printf("1.%s     %d    %d    %d\n", menu_coldbrew[1], price_coldbrew[1][1], price_coldbrew[1][2], price_coldbrew[1][3]);
            printf("2.%s         %d    %d    %d\n", menu_coldbrew[2], price_coldbrew[2][1], price_coldbrew[2][2], price_coldbrew[2][3]);
            printf("3.%s  %d    %d    %d\n", menu_coldbrew[3], price_coldbrew[3][1], price_coldbrew[3][2], price_coldbrew[3][3]);
            printf("4.%s              %d    %d    %d\n", menu_coldbrew[4], price_coldbrew[4][1], price_coldbrew[4][2], price_coldbrew[4][3]);
            printf("--------------------------------------------------------\n");
            printf("0.돌아가기\n");
            printf("메뉴를 선택해주세요.\n");
            scanf("%d", &s_menu);
            if(s_menu<0||s_menu>4)
            {
                printf("없는 메뉴입니다.\n");
                usleep(750000);
                continue;
            }

            if(s_menu==0)
            continue;

            printf("1.Tall 2.Grande 3.Venti\n");
            printf("사이즈를 선택해주세요\n");
            scanf("%d", &s_size);
            if(s_size<1||s_size>3)
            {
                printf("없는 사이즈입니다.\n");
                usleep(750000);
                continue;
            }
            printf("수량을 선택해 주세요\n");
            scanf("%d", &s_num);
            if(s_num<1)
            {
                printf("1개 이상 골라주세요\n");
                usleep(750000);
                continue;
            }
            for(i=1; i<=s_num; i++)
            {
                size_coldebrew[s_size][s_menu]+=1;
                cart_coldbrew[s_menu]+=price_coldbrew[s_menu][s_size];
            }

            printf("%s %s 사이즈 %d개가 장바구니에 추가되었습니다.\n", menu_coldbrew[s_menu], size[s_size], s_num);
            usleep(650000);
            continue;

            case 3:     //프라푸치노
            system("clear");
            printf("스타벅스 프라푸치노 메뉴\n");
            printf("--------------------------------------------------------\n");
            printf("    메뉴                                    Tall   Grande   Venti\n");
            printf("1.%s             %d    %d    %d\n", menu_frappuccino[1], price_frappuccino[1][1], price_frappuccino[1][2], price_frappuccino[1][3]);
            printf("2.%s   %d    %d    %d\n", menu_frappuccino[2], price_frappuccino[2][1], price_frappuccino[2][2], price_frappuccino[2][3]);
            printf("3.%s                        %d    %d    %d\n", menu_frappuccino[3], price_frappuccino[3][1], price_frappuccino[3][2], price_frappuccino[3][3]);
            printf("4.%s                  %d    %d    %d\n", menu_frappuccino[4], price_frappuccino[4][1], price_frappuccino[4][2], price_frappuccino[4][3]);
            printf("5.%s             %d    %d    %d\n", menu_frappuccino[5], price_frappuccino[5][1], price_frappuccino[5][2], price_frappuccino[5][3]);
            printf("6.%s                           %d    %d    %d\n", menu_frappuccino[6], price_frappuccino[6][1], price_frappuccino[6][2], price_frappuccino[6][3]);
            printf("7.%s                         %d    %d    %d\n", menu_frappuccino[7], price_frappuccino[7][1], price_frappuccino[7][2], price_frappuccino[7][3]);
            printf("8.%s                     %d    %d    %d\n", menu_frappuccino[8], price_frappuccino[8][1], price_frappuccino[8][2], price_frappuccino[8][3]);
            printf("9.%s                     %d    %d    %d\n", menu_frappuccino[9], price_frappuccino[9][1], price_frappuccino[9][2], price_frappuccino[9][3]);
            printf("--------------------------------------------------------\n");
            printf("0.돌아가기\n");
            printf("메뉴를 선택해주세요.\n");
            scanf("%d", &s_menu);
            if(s_menu<0||s_menu>9)
            {
                printf("없는 메뉴입니다.\n");
                usleep(750000);
                continue;
            }

            if(s_menu==0)
            continue;

            printf("1.Tall 2.Grande 3.Venti\n");
            printf("사이즈를 선택해주세요\n");
            scanf("%d", &s_size);
            if(s_size<1||s_size>3)
            {
                printf("없는 사이즈입니다.\n");
                usleep(750000);
                continue;
            }
            printf("수량을 선택해 주세요\n");
            scanf("%d", &s_num);
            if(s_num<1)
            {
                printf("1개 이상 골라주세요\n");
                usleep(750000);
                continue;
            }
            for(i=1; i<=s_num; i++)
            {
                size_frappuccino[s_size][1]+=1;
                cart_frappuccino[s_menu]+=price_frappuccino[s_menu][s_size];
            }

            printf("%s %s 사이즈 %d개가 장바구니에 추가되었습니다.\n", menu_frappuccino[s_menu], size[s_size], s_num);
            usleep(650000);
            continue;

            case 4:     //블렌디드
            system("clear");
            printf("스타벅스 블렌디드 메뉴\n");
            printf("--------------------------------------------------------\n");
            printf("    메뉴                         Tall   Grande   Venti\n");
            printf("1.%s        %d    %d    %d\n", menu_blended[1], price_blended[1][1], price_blended[1][2], price_blended[1][3]);
            printf("2.%s  %d    %d    %d\n", menu_blended[2], price_blended[2][1], price_blended[2][2], price_blended[2][3]);
            printf("3.%s           %d    %d    %d\n", menu_blended[3], price_blended[3][1], price_blended[3][2], price_blended[3][3]);
            printf("4.%s           %d    %d    %d\n", menu_blended[4], price_blended[4][1], price_blended[4][2], price_blended[4][3]);
            printf("5.%s      %d    %d    %d\n", menu_blended[5], price_blended[5][1], price_blended[5][2], price_blended[5][3]);
            printf("--------------------------------------------------------\n");
            printf("0.돌아가기\n");
            printf("메뉴를 선택해주세요.\n");
            scanf("%d", &s_menu);
            if(s_menu<0||s_menu>5)
            {
                printf("없는 메뉴입니다.\n");
                usleep(750000);
                continue;
            }

            if(s_menu==0)
            continue;

            printf("1.Tall 2.Grande 3.Venti\n");
            printf("사이즈를 선택해주세요\n");
            scanf("%d", &s_size);
            if(s_size<1||s_size>3)
            {
                printf("없는 사이즈입니다.\n");
                usleep(750000);
                continue;
            }
            printf("수량을 선택해 주세요\n");
            scanf("%d", &s_num);
            if(s_num<1)
            {
                printf("1개 이상 골라주세요\n");
                usleep(750000);
                continue;
            }
            for(i=1; i<=s_num; i++)
            {
                size_blended[s_size][s_menu]+=1;
                cart_blended[s_menu]+=price_blended[s_menu][s_size];
            }

            printf("%s %s 사이즈 %d개가 장바구니에 추가되었습니다.\n", menu_blended[s_menu], size[s_size], s_num);
            usleep(650000);
            continue;

            case 5:     //피지오
            system("clear");
            printf("스타벅스 피지오 메뉴\n");
            printf("--------------------------------------------------------\n");
            printf("    메뉴                          Tall   Grande   Venti\n");
            printf("1.%s                   %d    %d    %d\n", menu_fizzio[1], price_fizzio[1][1], price_fizzio[1][2], price_fizzio[1][3]);
            printf("2.%s        %d    %d    %d\n", menu_fizzio[2], price_fizzio[2][1], price_fizzio[2][2], price_fizzio[2][3]);
            printf("3.%s  %d    %d    %d\n", menu_fizzio[3], price_fizzio[3][1], price_fizzio[3][2], price_fizzio[3][3]);
            printf("--------------------------------------------------------\n");
            printf("0.돌아가기\n");
            printf("메뉴를 선택해주세요.\n");
            scanf("%d", &s_menu);
            if(s_menu<0||s_menu>3)
            {
                printf("없는 메뉴입니다.\n");
                usleep(750000);
                continue;
            }

            if(s_menu==0)
            continue;

            printf("1.Tall 2.Grande 3.Venti\n");
            printf("사이즈를 선택해주세요\n");
            scanf("%d", &s_size);
            if(s_size<1||s_size>3)
            {
                printf("없는 사이즈입니다.\n");
                usleep(750000);
                continue;
            }
            printf("수량을 선택해 주세요\n");
            scanf("%d", &s_num);
            if(s_num<1)
            {
                printf("1개 이상 골라주세요\n");
                usleep(750000);
                continue;
            }
            for(i=1; i<=s_num; i++)
            {
                size_fizzio[s_size][s_menu]+=1;
                cart_fizzio[s_menu]+=price_fizzio[s_menu][s_size];
            }

            printf("%s %s 사이즈 %d개가 장바구니에 추가되었습니다.\n", menu_fizzio[s_menu], size[s_size], s_num);
            usleep(650000);
            continue;

            case 6:
            system("clear");
            printf("스타벅스 티 메뉴\n");
            printf("--------------------------------------------------------\n");
            printf("    메뉴                        Tall   Grande   Venti\n");
            printf("1.%s            %d    %d    %d\n", menu_tea[1], price_tea[1][1], price_tea[1][2], price_tea[1][3]);
            printf("2.%s              %d    %d    %d\n", menu_tea[2], price_tea[2][1], price_tea[2][2], price_tea[2][3]);
            printf("3.%s                  %d    %d    %d\n", menu_tea[3], price_tea[3][1], price_tea[3][2], price_tea[3][3]);
            printf("4.%s                %d    %d    %d\n", menu_tea[4], price_tea[4][1], price_tea[4][2], price_tea[4][3]);
            printf("5.%s  %d    %d    %d\n", menu_tea[5], price_tea[5][1], price_tea[5][2], price_tea[5][3]);
            printf("6.%s                  %d    %d    %d\n", menu_tea[6], price_tea[6][1], price_tea[6][2], price_tea[6][3]);
            printf("7.%s                  %d    %d    %d\n", menu_tea[7], price_tea[7][1], price_tea[7][2], price_tea[7][3]);
            printf("8.%s              %d    %d    %d\n", menu_tea[8], price_tea[8][1], price_tea[8][2], price_tea[8][3]);
            printf("--------------------------------------------------------\n");
            printf("0.돌아가기\n");
            printf("메뉴를 선택해주세요.\n");
            scanf("%d", &s_menu);
            if(s_menu<0||s_menu>8)
            {
                printf("없는 메뉴입니다.\n");
                usleep(750000);
                continue;
            }

            if(s_menu==0)
            continue;

            printf("1.Tall 2.Grande 3.Venti\n");
            printf("사이즈를 선택해주세요\n");
            scanf("%d", &s_size);
            if(s_size<1||s_size>3)
            {
                printf("없는 사이즈입니다.\n");
                usleep(750000);
                continue;
            }
            printf("수량을 선택해 주세요\n");
            scanf("%d", &s_num);
            if(s_num<1)
            {
                printf("1개 이상 골라주세요\n");
                usleep(750000);
                continue;
            }
            for(i=1; i<=s_num; i++)
            {
                size_tea[s_size][s_menu]+=1;
                cart_tea[s_menu]+=price_tea[s_menu][s_size];
            }

            printf("%s %s 사이즈 %d개가 장바구니에 추가되었습니다.\n", menu_tea[s_menu], size[s_size], s_num);
            usleep(650000);
            continue;

            case 7:     // 일 매출 정산
            printf("커피 메뉴 총액:         %d원\n", revenue_coffee);
            printf("콜드브루 메뉴 총액:     %d원\n", revenue_coldbrew);
            printf("프라푸치노 메뉴 총액:   %d원\n", revenue_frappuccino);
            printf("블렌디드 메뉴 총액:     %d원\n", revenue_blended);
            printf("피지오 메뉴 총액:       %d원\n", revenue_fizzio);
            printf("티 메뉴 총액:           %d원\n", revenue_tea);
            printf("일 매출 총액:           %d원\n", daily_total);
            usleep(800000);
            continue;

            case 8: //종료하기
            printf("종료합니다.\n");
            return 0;
            default:
            printf("0~8중에서 선택해주세요.\n");
            usleep(750000);
            continue;
        }

        for(j=1; j<=7; j++)     // 주문내역 커피
        {
            for(i=0; i<4; i++)
            {
                if(size_coffee[i][cnt]>0)
                {
                    printf("%s %s 사이즈 %d개\n", menu_coffee[cnt], size[i-1], size_coffee[i][cnt]);
                    size_coffee[i][cnt]=0;
                }
            }
            cnt++;
        }
        cnt=1;

        for(j=1; j<=4; j++)     // 주문내역 콜드브루
        {
            for(i=0; i<4; i++)
            {
                if(size_coldebrew[i][cnt]>0)
                {
                    printf("%s %s 사이즈 %d개\n", menu_coldbrew[cnt], size[i], size_coldebrew[i][cnt]);
                    size_coldebrew[i][cnt]=0;
                }
            }
            cnt++;
        }
        cnt=1;

        for(j=1; j<=9; j++)     // 주문내역 프라푸치노
        {
            for(i=0; i<4; i++)
            {
                if(size_frappuccino[i][cnt]>0)
                {
                    printf("%s %s 사이즈 %d개\n", menu_frappuccino[cnt], size[i], size_frappuccino[i][cnt]);
                    size_frappuccino[i][cnt]=0;
                }
            }
            cnt++;
        }
        cnt=1;

        for(j=1; j<=5; j++)     // 주문내역 블렌디드
        {
            for(i=0; i<4; i++)
            {
                if(size_blended[i][cnt]>0)
                {
                    printf("%s %s 사이즈 %d개\n", menu_blended[cnt], size[i], size_blended[i][cnt]);
                    size_blended[i][cnt]=0;
                }
            }
            cnt++;
        }
        cnt=1;

        for(j=1; j<=3; j++)     // 주문내역 피지오
        {
            for(i=0; i<4; i++)
            {
                if(size_fizzio[i][cnt]>0)
                {
                    printf("%s %s 사이즈 %d개\n", menu_fizzio[cnt], size[i], size_fizzio[i][cnt]);
                    size_fizzio[i][cnt]=0;
                }
            }
            cnt++;
        }
        cnt=1;

        for(j=1; j<=8; j++)     // 주문내역 티
        {
            for(i=0; i<4; i++)
            {
                if(size_tea[i][cnt]>0)
                {
                    printf("%s %s 사이즈 %d개\n", menu_tea[cnt], size[i], size_tea[i][cnt]);
                    size_tea[i][cnt]=0;
                }
            }
            cnt++;
        }
        cnt=1;

        //계산할 총액 확인
        for(i=1; i<=7; i++)
        total+=cart_coffee[i];
        for(i=1; i<=4; i++)
        total+=cart_coldbrew[i];
        for(i=1; i<=9; i++)
        total+=cart_frappuccino[i];
        for(i=1; i<=5; i++)
        total+=cart_blended[i];
        for(i=1; i<=3; i++)
        total+=cart_fizzio[i];
        for(i=1; i<=8; i++)
        total+=cart_tea[i];

        if(total<=0)
        {
            printf("메뉴를 주문해주세요\n");
            usleep(800000);
            continue;
        }
        printf("등급            최소 금액           할인율\n");
        printf("1.Silver          10000                5%%\n");
        printf("2.Gold            20000               15%%\n");
        printf("3.VIP              없음               15%%\n");
        printf("총 금액: %.0f\n", total);
        printf("등급 선택\n");
        scanf("%d", &s_member);
        switch(s_member)
        {
            
            case 1: //silver 최소금액 10000원 5%할인
            if(total>=10000)
            {
                printf("%.0f원 만큼 할인하여 %.0f원 결제되었습니다.\n", total*member[s_member], total-total*member[s_member]);
                total -= total*member[s_member];
            }
            else
            {
                printf("최소 금액이 부족합니다.\n");
                usleep(750000);
                continue;
            }
            break;

            case 2: //Gold 최소금액 20000원 15%할인
            if(total>=20000)
            {
                printf("%.0f원 만큼 할인하여 %.0f원 결제되었습니다.\n", total*member[s_member], total-total*member[s_member]);
                total -= total*member[s_member];
            }
            else
            {
                printf("최소 금액이 부족합니다.\n");
                usleep(750000);
                continue;
            }
            break;

            case 3: //VIP 최소금액 없음 15%할인
            printf("%.0f원 만큼 할인하여 %.0f원 결제되었습니다.\n", total*member[s_member], total-total*member[s_member]);
            total -= total*member[s_member];
            break;

            default:
            printf("1~3중에서 선택해주세요.\n");
            usleep(750000);
            continue;
        }
        //계산한 금액 일매출정산에 포함
        daily_total+=total;
        total=0;
        for(i=1; i<=7; i++)
        revenue_coffee += cart_coffee[i] - cart_coffee[i]*member[s_member];
        for(i=1; i<=4; i++)
        revenue_coldbrew += cart_coldbrew[i] - cart_coldbrew[i]*member[s_member];
        for(i=1; i<=9; i++)
        revenue_frappuccino += cart_frappuccino[i] - cart_frappuccino[i]*member[s_member];
        for(i=1; i<=5; i++)
        revenue_blended += cart_blended[i] - cart_blended[i]*member[s_member];
        for(i=1; i<=3; i++)
        revenue_fizzio += cart_fizzio[i] - cart_fizzio[i]*member[s_member];
        for(i=1; i<=8; i++)
        revenue_tea += cart_tea[i] - cart_tea[i]*member[s_member];

        //카트 초기화
        for(i=1; i<=7; i++)
        cart_coffee[i]=0;
        for(i=1; i<=4; i++)
        cart_coldbrew[i]=0;
        for(i=1; i<=9; i++)
        cart_frappuccino[i]=0;
        for(i=1; i<=5; i++)
        cart_blended[i]=0;
        for(i=1; i<=3; i++)
        cart_fizzio[i]=0;
        for(i=1; i<=8; i++)
        cart_tea[i]=0;
        usleep(800000);
    }
    return 0;
}