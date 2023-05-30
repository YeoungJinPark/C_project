#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //메뉴별 가격(가장 작은 사이즈 기준)
    int coffee_price[] = {0, 4000, 4500, 4500, 5400, 5400, 5000, 5400}; //커피 가격
    int coldbrew_price[] = {0, 5800, 6000, 5800, 4900}; //콜드브루 가격
    int frappuccino_price[] = {0, 6300, 6300, 6300, 6000, 6000, 6000, 5900, 5500, 5500};    //프라푸치노 가격
    int blended_price[] = {0, 6300, 6300, 6300, 6300, 5400};    //블렌디드 가격
    int fizzio_price[] = {0, 5900, 5400, 5400}; //피지오 가격
    int tea_price[] = {0, 6100, 5900, 5900, 5900, 6100, 5500, 5900, 5700};  //차 가격
    int size[]={0, 500, 1000, 1500, 2000};  //1.Short 2.Tall 3.Grande 4.Venti

    //주문한 메뉴
    int order_coffee[50]= {0, };
    int order_coldbrew[50]= {0, };
    int order_frappuccino[50]= {0, };
    int order_blended[50]= {0, };
    int order_fizzio[50]= {0, };
    int order_tea[50]= {0, };
    
    //사이즈
    int size_coffee[50]= {0, };
    int size_coldbrew[50]= {0, };
    int size_frappuccino[50]= {0, };
    int size_blended[50]= {0, };
    int size_fizzio[50]= {0, };
    int size_tea[50]= {0, };

    //메뉴별 수량
    int cnt_coffee[8]= {0, };
    int cnt_coldbrew[5]= {0, };
    int cnt_frappuccino[10]= {0, };
    int cnt_blended[6]= {0, };
    int cnt_fizzio[5]= {0, };
    int cnt_tea[8]= {0, };

    //선택관련 변수 s_는 select
    int s_category, s_menu=10, s_size=0, s_number=0, s_bill=0, s_membership=0, select=0, back=0;

    //계산관련 변수
    int revenue[7]= {0, };  //카테고리별 매출총액
    int cart[7] = {0, };    //카테고리별 결제할 금액 1.커피 2.콜드브루 3.프라푸치노 4.블렌디드 5.피지오 6.티
    int i=1, daily_total=0, total=0, cnt=0, cnt_short=0, tall=0, grande=0, venti=0;

    while(1)
    {
        printf("0.계산하기 1.커피 2.콜드 브루 3.프라푸치노 4.블렌디드 5.피지오 6.티 7.일 매출 정산\n");
        printf("카테고리를 선택해주세요.\n");
        scanf("%d", &s_category);

        while(1)
        {
            switch(s_category)
            {
                case 0: //계산하기
                break;
                
                case 1: //커피
                system("clear");
                printf("스타벅스 커피 메뉴\n");
                printf("--------------------------------------------------------\n");
                printf("    메뉴              short     Tall     Grande     Venti\n");
                printf("1.아메리카노          %d      %d      %d      %d\n",coffee_price[1] ,coffee_price[1]+size[1], coffee_price[1]+size[2], coffee_price[1]+size[3]);
                printf("2.카페라떼            %d      %d      %d      %d\n",coffee_price[2] ,coffee_price[2]+size[1], coffee_price[2]+size[2], coffee_price[2]+size[3]);
                printf("3.카푸치노            %d      %d      %d      %d\n",coffee_price[3] ,coffee_price[3]+size[1], coffee_price[3]+size[2], coffee_price[3]+size[3]);
                printf("4.카라멜 마키아또     %d      %d      %d      %d\n",coffee_price[4] ,coffee_price[4]+size[1], coffee_price[4]+size[2], coffee_price[4]+size[3]);
                printf("5.화이트 초콜릿 모카  %d      %d      %d      %d\n",coffee_price[5] ,coffee_price[5]+size[1], coffee_price[5]+size[2], coffee_price[5]+size[3]);
                printf("6.카페모카            %d      %d      %d      %d\n",coffee_price[6] ,coffee_price[6]+size[1], coffee_price[6]+size[2], coffee_price[6]+size[3]);
                printf("7.스타벅스 돌체라떼   %d      %d      %d      %d\n",coffee_price[7] ,coffee_price[7]+size[1], coffee_price[7]+size[2], coffee_price[7]+size[3]);
                printf("--------------------------------------------------------\n");
                printf("0.돌아가기\n");
                printf("메뉴를 선택해주세요.\n");
                scanf("%d", &s_menu);
                if(s_menu==0)
                break;
                else if(s_menu>0&&s_menu<8)
                {
                    printf("1.Short 2.Tall 3.Grande 4.Venti\n");
                    printf("사이즈를 선택해주세요.\n");
                    scanf("%d", &s_size);
                    if(s_size<1||s_size>4)
                    {
                        printf("다시 선택해 주세요.\n");
                        continue;
                    }
                    printf("수량을 선택해주세요.\n");
                    scanf("%d", &s_number);
                    if(s_number<1)
                    {
                        printf("다시 선택해 주세요.\n");
                        continue;
                    }
                    
                    switch(s_menu)
                    {
                        case 1: //아메리카노
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=coffee_price[s_menu]+size[s_size];
                            cnt_coffee[s_menu]+=1;
                            cnt=cnt_coffee[s_menu];
                            size_coffee[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("아메리카노 Short사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("아메리카노 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==3)
                        printf("아메리카노 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("아메리카노 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_coffee[cnt+1]='\0';
                        continue;

                        case 2: //카페라떼
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=coffee_price[s_menu]+size[s_size];
                            cnt_coffee[s_menu]+=1;
                            cnt=cnt_coffee[s_menu];
                            size_coffee[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("카페라떼 Short사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("카페라떼 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==3)
                        printf("카페라떼 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("카페라떼 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_coffee[cnt+1]='\0';
                        continue;
                        
                        case 3: //카푸치노
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=coffee_price[s_menu]+size[s_size];
                            cnt_coffee[s_menu]+=1;
                            cnt=cnt_coffee[s_menu];
                            size_coffee[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("카푸치노 Short사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("카푸치노 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==3)
                        printf("카푸치노 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("카푸치노 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_coffee[cnt+1]='\0';
                        continue;
                        
                        case 4: //카라멜 마키아또
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=coffee_price[s_menu]+size[s_size];
                            cnt_coffee[s_menu]+=1;
                            cnt=cnt_coffee[s_menu];
                            size_coffee[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("카라멜 마키아또 Short사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("카라멜 마키아또 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==3)
                        printf("카라멜 마키아또 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("카라멜 마키아또 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_coffee[cnt+1]='\0';
                        continue;
                        
                        case 5: //화이트 초콜릿 모카
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=coffee_price[s_menu]+size[s_size];
                            cnt_coffee[s_menu]+=1;
                            cnt=cnt_coffee[s_menu];
                            size_coffee[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("화이트 초콜릿 모카 Short사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("화이트 초콜릿 모카 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==3)
                        printf("화이트 초콜릿 모카 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("화이트 초콜릿 모카 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_coffee[cnt+1]='\0';
                        continue;
                        
                        case 6: //카페모카
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=coffee_price[s_menu]+size[s_size];
                            cnt_coffee[s_menu]+=1;
                            cnt=cnt_coffee[s_menu];
                            size_coffee[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("카페모카 Short사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("카페모카 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==3)
                        printf("카페모카 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("카페모카 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_coffee[cnt+1]='\0';
                        continue;
                        
                        case 7: //스타벅스 돌체라떼
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=coffee_price[s_menu]+size[s_size];
                            cnt_coffee[s_menu]+=1;
                            cnt=cnt_coffee[s_menu];
                            size_coffee[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("스타벅스 돌체라떼 Short사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("스타벅스 돌체라떼 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==3)
                        printf("스타벅스 돌체라떼 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("스타벅스 돌체라떼 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_coffee[cnt+1]='\0';
                        continue;
                        
                    }
                }
                else
                {
                    printf("0~7중에 선택해주세요.\n");
                    continue;
                }
                break;

                case 2: //콜드 브루
                system("clear");
                printf("스타벅스 콜드 브루 메뉴\n");
                printf("--------------------------------------------------------\n");
                printf("    메뉴              Tall     Grande     Venti\n");
                printf("1.콜드브루 오트라떼   %d      %d      %d      \n",coldbrew_price[1] ,coldbrew_price[1]+500, coldbrew_price[1]+1000);
                printf("2.돌체 콜드브루       %d      %d      %d      \n",coldbrew_price[2] ,coldbrew_price[2]+500, coldbrew_price[2]+1000);
                printf("3.바닐라크림 콜드브루 %d      %d      %d      \n",coldbrew_price[3] ,coldbrew_price[3]+500, coldbrew_price[3]+1000);
                printf("4.콜드브루            %d      %d      %d      \n",coldbrew_price[4] ,coldbrew_price[4]+500, coldbrew_price[4]+1000);
                printf("--------------------------------------------------------\n");
                printf("메뉴를 선택해주세요.\n");
                printf("0.돌아가기\n");
                scanf("%d", &s_menu);
                if(s_menu==0)
                break;
                else if(s_menu>0&&s_menu<8)
                {
                    printf("1.Tall 2.Grande 3.Venti\n");
                    printf("사이즈를 선택해주세요.\n");
                    scanf("%d", &s_size);
                    if(s_size<1||s_size>3)
                    {
                        printf("다시 선택해 주세요.\n");
                        continue;
                    }
                    printf("수량을 선택해주세요.\n");
                    scanf("%d", &s_number);
                    if(s_number<1)
                    {
                        printf("다시 선택해 주세요.\n");
                        continue;
                    }
                    
                    switch(s_menu)
                    {
                        case 1: //콜드브루 오트라떼
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=coldbrew_price[s_menu]+size[s_size];
                            cnt_coldbrew[s_menu]+=1;
                            cnt=cnt_coldbrew[s_menu];
                            size_coldbrew[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("콜드브루 오트라떼 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("콜드브루 오트라떼 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("콜드브루 오트라떼 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_coldbrew[cnt+1]='\0';
                        continue;

                        case 2: //돌체 콜드브루
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=coldbrew_price[s_menu]+size[s_size];
                            cnt_coldbrew[s_menu]+=1;
                            cnt=cnt_coldbrew[s_menu];
                            size_coldbrew[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("돌체 콜드브루 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("돌체 콜드브루 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("돌체 콜드브루 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_coldbrew[cnt+1]='\0';
                        continue;
                        
                        case 3: //바닐라크림 콜드브루
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=coldbrew_price[s_menu]+size[s_size];
                            cnt_coldbrew[s_menu]+=1;
                            cnt=cnt_coldbrew[s_menu];
                            size_coldbrew[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("바닐라크림 콜드브루 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("바닐라크림 콜드브루 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("바닐라크림 콜드브루 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_coldbrew[cnt+1]='\0';
                        continue;
                        
                        case 4: //콜드브루
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=coldbrew_price[s_menu]+size[s_size];
                            cnt_coldbrew[s_menu]+=1;
                            cnt=cnt_coldbrew[s_menu];
                            size_coldbrew[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("콜드브루 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("콜드브루 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("콜드브루 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_coldbrew[cnt+1]='\0';
                        continue;

                        default:
                        break;
                    }
                }
                else
                {
                    printf("0~4중에 선택해주세요.\n");
                    continue;
                }
                break;

                case 3: //프라푸치노
                system("clear");
                printf("스타벅스 프라푸치노 메뉴\n");
                printf("-------------------------------------------------------------\n");
                printf("    메뉴                    Tall     Grande     Venti\n");
                printf("1.더블 에스프레소 칩        %d      %d      %d      \n",frappuccino_price[1] ,frappuccino_price[1]+500, frappuccino_price[1]+1000);
                printf("    프라푸치노\n");
                printf("2.제주 유기농 말차로 만든   %d      %d      %d      \n",frappuccino_price[2] ,frappuccino_price[2]+500, frappuccino_price[2]+1000);
                printf("   크림 프라푸치노\n");
                printf("3.자바 칩 프라푸치노        %d      %d      %d      \n",frappuccino_price[3] ,frappuccino_price[3]+500, frappuccino_price[3]+1000);
                printf("4.초콜릿 크림칩 프라푸치노  %d      %d      %d      \n",frappuccino_price[4] ,frappuccino_price[4]+500, frappuccino_price[4]+1000);
                printf("5.화이트 초콜릿 모카        %d      %d      %d      \n",frappuccino_price[5] ,frappuccino_price[5]+500, frappuccino_price[5]+1000);
                printf("    프라푸치노\n");
                printf("6.모카 프라푸치노           %d      %d      %d      \n",frappuccino_price[6] ,frappuccino_price[6]+500, frappuccino_price[6]+1000);
                printf("7.카라멜 프라푸치노         %d      %d      %d      \n",frappuccino_price[7] ,frappuccino_price[7]+500, frappuccino_price[7]+1000);
                printf("8.에스프레소 프라푸치노     %d      %d      %d      \n",frappuccino_price[8] ,frappuccino_price[8]+500, frappuccino_price[8]+1000);
                printf("9.바닐라크림 프라푸치노     %d      %d      %d      \n",frappuccino_price[9] ,frappuccino_price[9]+500, frappuccino_price[9]+1000);
                printf("-------------------------------------------------------------\n");
                printf("메뉴를 선택해주세요.\n");
                printf("0.돌아가기\n");
                scanf("%d", &s_menu);
                if(s_menu==0)
                break;
                else if(s_menu>0&&s_menu<8)
                {
                    printf("1.Tall 2.Grande 3.Venti\n");
                    printf("사이즈를 선택해주세요.\n");
                    scanf("%d", &s_size);
                    if(s_size<1||s_size>3)
                    {
                        printf("다시 선택해 주세요.\n");
                        continue;
                    }
                    printf("수량을 선택해주세요.\n");
                    scanf("%d", &s_number);
                    if(s_number<1)
                    {
                        printf("다시 선택해 주세요.\n");
                        continue;
                    }
                    
                    switch(s_menu)
                    {
                        case 1: //더블 에스프레소 칩 프라푸치노
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=frappuccino_price[s_menu]+size[s_size];
                            cnt_frappuccino[s_menu]+=1;
                            cnt=cnt_frappuccino[s_menu];
                            size_frappuccino[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("더블 에스프레소 칩 프라푸치노 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("더블 에스프레소 칩 프라푸치노 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("더블 에스프레소 칩 프라푸치노 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_frappuccino[cnt+1]='\0';
                        continue;

                        case 2: //제주 유기농 말차로 만든 크림 프라푸치노
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=frappuccino_price[s_menu]+size[s_size];
                            cnt_frappuccino[s_menu]+=1;
                            cnt=cnt_frappuccino[s_menu];
                            size_frappuccino[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("제주 유기농 말차로 만든 크림 프라푸치노 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("제주 유기농 말차로 만든 크림 프라푸치노 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("제주 유기농 말차로 만든 크림 프라푸치노 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_frappuccino[cnt+1]='\0';
                        continue;
                        
                        case 3: //자바 칩 프라푸치노
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=frappuccino_price[s_menu]+size[s_size];
                            cnt_frappuccino[s_menu]+=1;
                            cnt=cnt_frappuccino[s_menu];
                            size_frappuccino[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("자바 칩 프라푸치노 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("자바 칩 프라푸치노 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("자바 칩 프라푸치노 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_frappuccino[cnt+1]='\0';
                        continue;
                        
                        case 4: //초콜릿 크림칩 프라푸치노
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=frappuccino_price[s_menu]+size[s_size];
                            cnt_frappuccino[s_menu]+=1;
                            cnt=cnt_frappuccino[s_menu];
                            size_frappuccino[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("초콜릿 크림칩 프라푸치노 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("초콜릿 크림칩 프라푸치노 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("초콜릿 크림칩 프라푸치노 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_frappuccino[cnt+1]='\0';
                        continue;

                        case 5: //화이트 초콜릿 모카 프라푸치노
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=frappuccino_price[s_menu]+size[s_size];
                            cnt_frappuccino[s_menu]+=1;
                            cnt=cnt_frappuccino[s_menu];
                            size_frappuccino[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("화이트 초콜릿 모카 프라푸치노 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("화이트 초콜릿 모카 프라푸치노 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("화이트 초콜릿 모카 프라푸치노 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_frappuccino[cnt+1]='\0';
                        continue;

                        case 6: //모카 프라푸치노
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=frappuccino_price[s_menu]+size[s_size];
                            cnt_frappuccino[s_menu]+=1;
                            cnt=cnt_frappuccino[s_menu];
                            size_frappuccino[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("모카 프라푸치노 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("모카 프라푸치노 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("모카 프라푸치노 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_frappuccino[cnt+1]='\0';
                        continue;

                        case 7: //카라멜 프라푸치노
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=frappuccino_price[s_menu]+size[s_size];
                            cnt_frappuccino[s_menu]+=1;
                            cnt=cnt_frappuccino[s_menu];
                            size_frappuccino[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("카라멜 프라푸치노 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("카라멜 프라푸치노 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("카라멜 프라푸치노 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_frappuccino[cnt+1]='\0';
                        continue;

                        case 8: //에스프레소 프라푸치노
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=frappuccino_price[s_menu]+size[s_size];
                            cnt_frappuccino[s_menu]+=1;
                            cnt=cnt_frappuccino[s_menu];
                            size_frappuccino[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("에스프레소 프라푸치노 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("에스프레소 프라푸치노 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("에스프레소 프라푸치노 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_frappuccino[cnt+1]='\0';
                        continue;

                        case 9: //바닐라크림 프라푸치노
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=frappuccino_price[s_menu]+size[s_size];
                            cnt_frappuccino[s_menu]+=1;
                            cnt=cnt_frappuccino[s_menu];
                            size_frappuccino[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("바닐라크림 프라푸치노 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("바닐라크림 프라푸치노 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("바닐라크림 프라푸치노 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_frappuccino[cnt+1]='\0';
                        continue;
                    }
                }
                else
                {
                    printf("0~9중에 선택해주세요.\n");
                    continue;
                }
                break;

                case 4: //블렌디드
                system("clear");
                printf("스타벅스 블렌디드 메뉴\n");
                printf("--------------------------------------------------------\n");
                printf("    메뉴                    Tall     Grande     Venti\n");
                printf("1.민트 초콜릿 칩 블렌디드   %d      %d      %d      \n",blended_price[1] ,blended_price[1]+500, blended_price[1]+1000);
                printf("2.딸기 딜라이트             %d      %d      %d      \n",blended_price[2] ,blended_price[2]+500, blended_price[2]+1000);
                printf(" 요거트 블렌디드\n");
                printf("3.피치&레몬 블렌디드        %d      %d      %d      \n",blended_price[3] ,blended_price[3]+500, blended_price[3]+1000);
                printf("4.망고 바나나 블렌디드      %d      %d      %d      \n",blended_price[4] ,blended_price[4]+500, blended_price[4]+1000);
                printf("5.망고 패션 프루트          %d      %d      %d      \n",blended_price[5] ,blended_price[5]+500, blended_price[5]+1000);
                printf("   블렌디드\n");
                printf("--------------------------------------------------------\n");
                printf("메뉴를 선택해주세요.\n");
                printf("0.돌아가기\n");
                scanf("%d", &s_menu);
                if(s_menu==0)
                break;
                else if(s_menu>0&&s_menu<8)
                {
                    printf("1.Tall 2.Grande 3.Venti\n");
                    printf("사이즈를 선택해주세요.\n");
                    scanf("%d", &s_size);
                    if(s_size<1||s_size>3)
                    {
                        printf("다시 선택해 주세요.\n");
                        continue;
                    }
                    printf("수량을 선택해주세요.\n");
                    scanf("%d", &s_number);
                    if(s_number<1)
                    {
                        printf("다시 선택해 주세요.\n");
                        continue;
                    }
                    
                    switch(s_menu)
                    {
                        case 1: //민트 초콜릿 칩 블렌디드
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=blended_price[s_menu]+size[s_size];
                            cnt_blended[s_menu]+=1;
                            cnt=cnt_blended[s_menu];
                            size_blended[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("민트 초콜릿 칩 블렌디드 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("민트 초콜릿 칩 블렌디드 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("민트 초콜릿 칩 블렌디드 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_blended[cnt+1]='\0';
                        continue;

                        case 2: //딸기 딜라이트 요거트 블렌디드
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=blended_price[s_menu]+size[s_size];
                            cnt_blended[s_menu]+=1;
                            cnt=cnt_blended[s_menu];
                            size_blended[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("딸기 딜라이트 요거트 블렌디드 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("딸기 딜라이트 요거트 블렌디드Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("딸기 딜라이트 요거트 블렌디드 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_blended[cnt+1]='\0';
                        continue;

                        case 3: //피치&레몬 블렌디드
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=blended_price[s_menu]+size[s_size];
                            cnt_blended[s_menu]+=1;
                            cnt=cnt_blended[s_menu];
                            size_blended[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("피치&레몬 블렌디드 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("피치&레몬 블렌디드 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("피치&레몬 블렌디드 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_blended[cnt+1]='\0';
                        continue;
                        
                        case 4: //망고 바나나 블렌디드
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=blended_price[s_menu]+size[s_size];
                            cnt_blended[s_menu]+=1;
                            cnt=cnt_blended[s_menu];
                            size_blended[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("망고 바나나 블렌디드 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("망고 바나나 블렌디드 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("망고 바나나 블렌디드 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_blended[cnt+1]='\0';
                        continue;

                        case 5: //망고 패션 프루트 블렌디드
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=blended_price[s_menu]+size[s_size];
                            cnt_blended[s_menu]+=1;
                            cnt=cnt_blended[s_menu];
                            size_blended[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("망고 패션 프루트 블렌디드 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("망고 패션 프루트 블렌디드 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("망고 패션 프루트 블렌디드 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_blended[cnt+1]='\0';
                        continue;

                        default:
                        break;
                    }
                }
                else
                {
                    printf("0~7중에 선택해주세요.\n");
                    continue;
                }
                break;

                case 5: //피지오
                system("clear");
                printf("스타벅스 피지오 메뉴\n");
                printf("--------------------------------------------------------\n");
                printf("    메뉴                          Tall     Grande     Venti\n");
                printf("1.쿨라임 피지오                   %d      %d      %d\n",fizzio_price[1] ,fizzio_price[1]+500, fizzio_price[1]+1000);
                printf("2.딸기 딜라이트                   %d      %d      %d\n",fizzio_price[2] ,fizzio_price[2]+500, fizzio_price[2]+1000);
                printf("3.블랙티 레모네이도 피지오        %d      %d      %d\n",fizzio_price[3] ,fizzio_price[3]+500, fizzio_price[3]+1000);
                printf("4.패션 탱고 티 레모네이드 피지오  %d      %d      %d\n",fizzio_price[4] ,fizzio_price[4]+500, fizzio_price[4]+1000);
                printf("--------------------------------------------------------\n");
                printf("메뉴를 선택해주세요.\n");
                printf("0.돌아가기\n");
                scanf("%d", &s_menu);
                if(s_menu==0)
                break;
                else if(s_menu>0&&s_menu<8)
                {
                    printf("1.Tall 2.Grande 3.Venti\n");
                    printf("사이즈를 선택해주세요.\n");
                    scanf("%d", &s_size);
                    if(s_size<1||s_size>3)
                    {
                        printf("다시 선택해 주세요.\n");
                        continue;
                    }
                    printf("수량을 선택해주세요.\n");
                    scanf("%d", &s_number);
                    if(s_number<1)
                    {
                        printf("다시 선택해 주세요.\n");
                        continue;
                    }
                    
                    switch(s_menu)
                    {
                        case 1: //쿨라임 피지오
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=fizzio_price[s_menu]+size[s_size];
                            cnt_fizzio[s_menu]+=1;
                            cnt=cnt_fizzio[s_menu];
                            size_fizzio[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("쿨라임 피지오 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("쿨라임 피지오 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("쿨라임 피지오 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_fizzio[cnt+1]='\0';
                        continue;

                        case 2: //딸기 딜라이트
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=fizzio_price[s_menu]+size[s_size];
                            cnt_fizzio[s_menu]+=1;
                            cnt=cnt_fizzio[s_menu];
                            size_fizzio[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("딸기 딜라이트 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("딸기 딜라이트 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("딸기 딜라이트 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_fizzio[cnt+1]='\0';
                        continue;

                        case 3: //블랙티 레모네이도 피지오
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=fizzio_price[s_menu]+size[s_size];
                            cnt_fizzio[s_menu]+=1;
                            cnt=cnt_fizzio[s_menu];
                            size_fizzio[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("블랙티 레모네이도 피지오 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("블랙티 레모네이도 피지오 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("블랙티 레모네이도 피지오 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_fizzio[cnt+1]='\0';
                        continue;
                        
                        case 4: //패션 탱고 티 레모네이드 피지오
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=fizzio_price[s_menu]+size[s_size];
                            cnt_fizzio[s_menu]+=1;
                            cnt=cnt_fizzio[s_menu];
                            size_fizzio[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("패션 탱고 티 레모네이드 피지오 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("패션 탱고 티 레모네이드 피지오 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("패션 탱고 티 레모네이드 피지오 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_fizzio[cnt+1]='\0';
                        continue;
                    }
                }
                else
                {
                    printf("0~7중에 선택해주세요.\n");
                    continue;
                }
                break;

                case 6: //티
                system("clear");
                printf("스타벅스 티 메뉴\n");
                printf("--------------------------------------------------------\n");
                printf("    메뉴               Tall     Grande     Venti\n");
                printf("1.뉴이어 시트러스 티   %d      %d      %d\n",tea_price[1] ,tea_price[1]+500, tea_price[1]+1000);
                printf("2.돌체 블랙 밀크티     %d      %d      %d\n",tea_price[2] ,tea_price[2]+500, tea_price[2]+1000);
                printf("3.유자 민트 티         %d      %d      %d\n",tea_price[3] ,tea_price[3]+500, tea_price[3]+1000);
                printf("4.패션 프루트 티       %d      %d      %d\n",tea_price[4] ,tea_price[4]+500, tea_price[4]+1000);
                printf("5.제주 유기농 말차로   %d      %d      %d\n",tea_price[5] ,tea_price[5]+500, tea_price[5]+1000);     
                printf("    만든 라떼\n");
                printf("6.라임 패션 티         %d      %d      %d\n",tea_price[6] ,tea_price[6]+500, tea_price[6]+1000);
                printf("7.자몽 허니 블랙티     %d      %d      %d\n",tea_price[7] ,tea_price[7]+500, tea_price[7]+1000);
                printf("--------------------------------------------------------\n");
                printf("메뉴를 선택해주세요.\n");
                printf("0.돌아가기\n");
                scanf("%d", &s_menu);
                if(s_menu==0)
                break;
                else if(s_menu>0&&s_menu<8)
                {
                    printf("1.Short 2.Tall 3.Grande 4.Venti\n");
                    printf("사이즈를 선택해주세요.\n");
                    scanf("%d", &s_size);
                    if(s_size<1||s_size>4)
                    {
                        printf("다시 선택해 주세요.\n");
                        continue;
                    }
                    printf("수량을 선택해주세요.\n");
                    scanf("%d", &s_number);
                    if(s_number<1)
                    {
                        printf("다시 선택해 주세요.\n");
                        continue;
                    }
                    
                    switch(s_menu)
                    {
                        case 1: //뉴이어 시트러스 티
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=tea_price[s_menu]+size[s_size];
                            cnt_tea[s_menu]+=1;
                            cnt=cnt_tea[s_menu];
                            size_tea[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("뉴이어 시트러스 티 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("뉴이어 시트러스 티 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("뉴이어 시트러스 티 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_tea[cnt+1]='\0';
                        continue;

                        case 2: //돌체 블랙 밀크티
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=tea_price[s_menu]+size[s_size];
                            cnt_tea[s_menu]+=1;
                            cnt=cnt_tea[s_menu];
                            size_tea[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("돌체 블랙 밀크티 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("돌체 블랙 밀크티 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("돌체 블랙 밀크티 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_tea[cnt+1]='\0';
                        continue;
                        
                        case 3: //유자 민트 티
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=tea_price[s_menu]+size[s_size];
                            cnt_tea[s_menu]+=1;
                            cnt=cnt_tea[s_menu];
                            size_tea[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("유자 민트 티 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("유자 민트 티 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("유자 민트 티 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_tea[cnt+1]='\0';
                        continue;
                        
                        case 4: //패션 프루트 티
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=tea_price[s_menu]+size[s_size];
                            cnt_tea[s_menu]+=1;
                            cnt=cnt_tea[s_menu];
                            size_tea[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("패션 프루트 티 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("패션 프루트 티 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("패션 프루트 티 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_tea[cnt+1]='\0';
                        continue;
                        
                        case 5: //제주 유기농 말차로 만든 라떼
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=tea_price[s_menu]+size[s_size];
                            cnt_tea[s_menu]+=1;
                            cnt=cnt_tea[s_menu];
                            size_tea[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("제주 유기농 말차로 만든 라떼 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("제주 유기농 말차로 만든 라떼 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("제주 유기농 말차로 만든 라떼 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_tea[cnt+1]='\0';
                        continue;
                        
                        case 6: //라임 패션 티
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=tea_price[s_menu]+size[s_size];
                            cnt_tea[s_menu]+=1;
                            cnt=cnt_tea[s_menu];
                            size_tea[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("라임 패션 티 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("라임 패션 티 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("라임 패션 티 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_tea[cnt+1]='\0';
                        continue;
                        
                        case 7: //자몽 허니 블랙티
                        for(i=1; i<=s_number; i++)
                        {
                            cart[s_category]+=tea_price[s_menu]+size[s_size];
                            cnt_tea[s_menu]+=1;
                            cnt=cnt_tea[s_menu];
                            size_tea[cnt]=s_size;
                        }
                        if(s_size==1)
                        printf("자몽 허니 블랙티 Tall사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else if(s_size==2)
                        printf("자몽 허니 블랙티 Grande사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        else
                        printf("자몽 허니 블랙티 Venti사이즈 %d잔을 장바구니에 추가했습니다.\n", s_number);
                        size_tea[cnt+1]='\0';
                        continue;
                        
                    }
                }
                else
                {
                    printf("0~7중에 선택해주세요.\n");
                    continue;
                }
                break;

                case 7: //일 매출 정산
                printf("커피 매출 총합: %d", revenue[1]);
                printf("콜드 브루 매출 총합: %d", revenue[2]);
                printf("프라푸치노 매출 총합: %d", revenue[3]);
                printf("블렌디드 매출 총합: %d", revenue[4]);
                printf("피지오 매출 총합: %d", revenue[5]);
                printf("티 매출 총합: %d", revenue[6]);
                for(int k=1; k<=6; k++)
                daily_total+=revenue[k];
                printf("일 매출 총합: %d", daily_total);
                break;
            }
        }
        if(back==1) //돌아가기
        {
            back=0;
            continue;
        }
        for(i=1; i<=6; i++)
        total+=cart[i];
        printf("총 금액: %d원\n", total);
        printf("0.계산취소 1.멤버쉽 할인");
        scanf("%d", &select);
        if(select==0)
        {
            for(i=1; i<=10; i++)
            {
                cnt_coffee[i]=0;
                cnt_coldbrew[i]=0;
                cnt_frappuccino[i]=0;
                cnt_blended[i]=0;
                cnt_fizzio[i]=0;
                cnt_tea[i]=0;
                cart[i]=0;
            }
            total=0;
        }
        else if(select==1)
        {
            system("clear");
            printf("주문 내역\n");
            i=1;
            while(1)
            {
                if(cnt_coffee[1]>0)
                {
                    for(i=1; i<=cnt_coffee[1]; i++)
                    {
                        switch(size_coffee[i])
                        {
                            case 1:
                            cnt_short++;
                            break;
                            case 2:
                            tall++;
                            break;
                            case 3:
                            grande++;
                            break;
                            case 4:
                            venti++;
                            break;
                            default:
                            break;
                        }
                    }
                }
            }
            while(1)
            {
                printf("스타벅스 멤버쉽 할인\n");
                printf("                          최소 금액           할인율\n");
                printf("Silver                      10000               5%%\n");
                printf("Gold                        20000              15%%\n");
                printf("VIP                          없음               15%%\n");
                printf("1.Silver 2.Gold 3.VIP");
                scanf("%d", &s_membership);
                if(s_membership==1&&total>=10000)
                {
                    printf("총 금액:%d\n할인되는 금액:%d\n", total, total-total*0.05);
                    total*=0.05;
                    printf("결제 금액: %d\n", total);
                }
                else if(s_membership==2&&total>=20000)
                {
                    printf("총 금액:%d\n할인되는 금액:%d\n", total, total-total*0.15);
                    total*=0.15;
                    printf("결제 금액: %d\n", total);
                }
                else if(s_membership==3)
                {
                    printf("총 금액:%d\n할인되는 금액:%d\n", total, total-total*0.15);
                    total*=0.15;
                    printf("결제 금액: %d\n", total);
                }
                else
                {
                    printf("결제금액이 부족하거나 없는 등급입니다.");
                    continue;
                }
                daily_total+=total;
                break;
            }
        }
        break;
    }
    return 0;
}