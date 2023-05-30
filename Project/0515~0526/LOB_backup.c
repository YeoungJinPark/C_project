#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define dead 1
#define allive 0

typedef struct
{
    char name[20];          //이름
    char class_name[20];    //클래스 이름
    int class;              //클래스 종류 1.전사 2.백마법사 3.흑마법사 4.적마법사 5.궁수 6.검사
    int lv;                 //레벨
    int max_hp;             //최대 체력
    int max_mp;             //최대 마나
    int hp;                 //현재 체력
    int mp;                 //현재 마나
    int atk;                //공격력
    int total_atk;          //최종 공격력(공격력+무기 공격력)
    int def;                //방어력
    int total_def;          //최종 방어력(방어력+무기 방어력)
    int exp;                //현재 경험치
    char *head_eqm;  // 머리
    char *body_eqm;  // 상의
    char *pants_eqm; // 하의
    char *cape_eqm;  // 망토
    char *glove_eqm; // 장갑
    char *left_eqm;  // 방패
    char *right_eqm; // 무기
    int state;              //상태(전투 불능)
    int area;               //현재 있는 구역 1.불 2.눈 3.숲 4.물
} Player;

typedef struct
{
    char name[20];      //몬스터 이름
    char skill[20];     //몬스터 스킬 이름
    int hp;             //체력
    int atk;            //공격력
    int def;            //방어력
    int exp;            //잡았을때 주는 경험치
    int state;          //상태(전투 불능)
    int type;           //몬스터 타입(1.불 2.숲 3.눈 4.물)
    int cd;             //쿨다운 남은 턴
    int class;          //수호대 클래스
} Monster;

typedef struct // 스킬 구성
{
    char *skillname; // 스킬 이름
    int skillatk;    // 스킬 공격력
    int skilldef;    // 스킬 방어력
    int skillheal;   // 스킬 회복력
    int skillmp;     // 스킬 사용시 마나 사용량
    int s_unlock;    // 스킬 레벨 제한
} Skillstat;

typedef struct // 스킬 구성
{
    char *skillname; // 스킬 이름
    int skillatk;    // 스킬 공격력
} Mobskillstat;

typedef struct
{
    char name[50];  // 보스 이름
    char skill[50]; // 보스 스킬 이름
    int hp;         // 체력
    int atk;        // 공격력
    int def;        // 방어력
    int exp;        // 경험치
    int state;      // 상태(전투 불능) hp가 0이되면 state의 값이0으로돼서 전투 불능상태
    int type;       // 마법 물리 0이면 물리 1이면 마법
} Boss;

typedef struct // 소비 아이템 구조체
{
    char name[30]; // 이름
    int count;  // 수량 (수량 변수로 동기화 필요. 우선 0으로 기입. 추후 전투로직 완성시 변수 받아서 삽입.)
    int hp;     // HP
    int mp;     // MP
} Consumption;

typedef struct
{
    char *head_name;  // 머리
    char *body_name;  // 상의
    char *pants_name; // 하의
    char *cape_name;  // 망토
    char *glove_name; // 장갑
    char *left_name;  // 방패
    char *right_name; // 무기
    int def;          // 방어력
    int atk;          //  공격력
    int count;        // 수량    전투가 끝나면 아이템 수량을 받아야함.
} Equipment;

Mobskillstat Nmob(Monster *mob, int turn_atk, int n) // 일반 몬스터 스킬 정의
{
    srand((unsigned)time(NULL));
    double normal1 = rand() % 31 + 20; // 20 ~ 50 값
    double normal2 = rand() % 41 + 20; // 20 ~ 60 값
    double normal3 = rand() % 51 + 30; // 30 ~ 80 값
    double normal4 = rand() % 61 + 30; // 30 ~ 90 값

    Mobskillstat normal[4] = {{"불뿜기", mob[turn_atk].atk * (normal1 / 100)},
                              {"물대포", mob[turn_atk].atk * (normal2 / 100)},
                              {"얼음고드름", mob[turn_atk].atk * (normal3 / 100)},
                              {"나무던지기", mob[turn_atk].atk * (normal4 / 100)}};

    return normal[n];
}

Consumption itemList(Player *chr, int turn_atk, int n) // 소비 아이템 리스트 정의
{
    double num1=0.3;
    double num2=0.6;
    double num3=0.8;

    Consumption item[11] = {{"초급 HP회복 포션", 0, chr[turn_atk].max_hp*num1, 0},
                            {"중급 HP회복 포션", 0, chr[turn_atk].max_hp*num2, 0},
                            {"상급 HP회복 포션", 0, chr[turn_atk].max_hp*num3, 0},
                            {"초급 MP회복 포션", 0, 0, chr[turn_atk].max_mp*num1},
                            {"중급 MP회복 포션", 0, 0, chr[turn_atk].max_mp*num2},
                            {"상급 MP회복 포션", 0, 0, chr[turn_atk].max_mp*num3},
                            {"초급 엘릭서", 0, chr[turn_atk].max_hp * (25 / 100), chr[turn_atk].max_mp * (25 / 100)},
                            {"중급 엘릭서", 0, chr[turn_atk].max_hp * (50 / 100), chr[turn_atk].max_mp * (50 / 100)},
                            {"상급 엘릭서", 0, chr[turn_atk].max_hp * (75 / 100), chr[turn_atk].max_mp * (75 / 100)},
                            {"부활 포션", 0, chr[turn_atk].max_hp, chr[turn_atk].max_mp},
                            {"텐트", 0, chr[turn_atk].max_hp, chr[turn_atk].max_mp}};

   return item[n];
}


Skillstat SwordManSkill(Player *chr, int turn_atk) // 검사 스킬 정의
{
    srand((unsigned)time(NULL));
    int luck = rand() % 49 + 2; // 1~50 값

    Skillstat swordman = {"럭키스트라이크", chr[turn_atk].total_atk * luck, 0, chr[turn_atk].max_mp / 2, 10}; // 단일
    return swordman;
}

Skillstat WhiteWizardSkill(Player *chr, int caster, int target, int n) // 백법사 스킬 정의
{
    srand((unsigned)time(NULL));
    double heal = rand() % 41 + 30;    // 30~70 값
    double gheal = rand() % 41 + 60;   // 60~100 값
    double healall = rand() % 41 + 40; // 40~80 값
    double atkup = rand() % 21 + 50;   // 50~70 값

    Skillstat whitewizard[6] = {{"힐", 0, 0, chr[target].max_hp * (heal / 100), chr[caster].max_mp / 10, 1},           // 단일
                                {"그레이터힐", 0, 0, chr[target].max_hp * (gheal / 100), chr[caster].max_mp / 10, 15}, // 단일
                                {"힐올", 0, 0, chr[target].max_hp * (healall / 100), chr[caster].max_mp / 10, 30},     // 전체
                                {"공격력 업!", chr[target].total_atk/2 +10, 0, 0, chr[caster].max_mp / 10, 10},        // 전체
                                {"방어력 업!", 0, chr[target].total_def / 2, 0, chr[caster].max_mp / 10, 15}};         // 전체

    return whitewizard[n];
}

Skillstat blackWizard(Player *chr, int turn_atk, int n) // 흑법사 스킬 정의
{
    srand((unsigned)time(NULL));
    double black = rand() % 21 + 50; // 50~70 값

    Skillstat blackwizard[4] = {{"파이어볼", (chr[turn_atk].atk) + (chr[turn_atk].total_atk * (30 / 100)), 0, 0, chr[turn_atk].max_mp / 10, 1},         // 단일
                                {"파이어월", (chr[turn_atk].atk) + (chr[turn_atk].total_atk * (black / 100)), 0, 0, chr[turn_atk].max_mp / 10, 15},     // 전체
                                {"썬더브레이커", (chr[turn_atk].atk) + (chr[turn_atk].total_atk * (black / 100)), 0, 0, chr[turn_atk].max_mp / 10, 20}, // 전체
                                {"블리자드", (chr[turn_atk].atk) + (chr[turn_atk].total_atk * (black / 100)), 0, 0, chr[turn_atk].max_mp / 10, 25}};    // 전체

    return blackwizard[n];
}
 
Skillstat RedWizardSkill(Player *chr, int caster, int target, int n) // 적법사 스킬 정의
{
    srand((unsigned)time(NULL));
    double red = rand() % 81 + 20; // 20~80 값

    Skillstat redwizard[4] = {{"힐", 0, 0, chr[target].max_hp * (red / 100), chr[caster].max_mp / 10, 1},            // 단일
                              {"파이어볼", chr[caster].total_atk * (red / 100), 0, 0, chr[caster].max_mp / 10, 1},   // 단일
                              {"힐올", 0, 0, chr[target].max_hp * (red / 100), chr[caster].max_mp / 10, 20},         // 전체
                              {"파이어월", chr[caster].total_atk * (red / 100), 0, 0, chr[caster].max_mp / 10, 20}}; // 전체

    return redwizard[n];
}

Skillstat ArcherSkill(Player *chr, int turn_atk, int n) // 궁수 스킬 정의
{
    srand((unsigned)time(NULL));
    double archeratk1 = rand() % 31 + 20; // 20~50 값
    double archeratk2 = rand() % 21 + 40; // 40~60 값
    double archeratk3 = rand() % 21 + 50; // 50~70 값

    Skillstat archer[3] = {{"집중타", (chr[turn_atk].atk) + (chr[turn_atk].total_atk * (archeratk1 / 100)), 0, 0, chr[turn_atk].max_mp / 10, 10},    // 단일
                           {"듀얼샷", (chr[turn_atk].atk) + (chr[turn_atk].total_atk * (archeratk2 / 100)), 0, 0, chr[turn_atk].max_mp / 10, 15},    // 단일
                           {"마스터샷", (chr[turn_atk].atk) + (chr[turn_atk].total_atk * (archeratk3 / 100)), 0, 0, chr[turn_atk].max_mp / 10, 20}}; // 단일

    return archer[n];
}

int getch() // 엔터를 누르지 않아도 1문자씩 키입력을 받기 위한 함수(wasd)
{
    int c;
    struct termios oldattr, newattr;

    tcgetattr(STDIN_FILENO, &oldattr); // 현재 터미널 설정 읽음
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);        // CANONICAL과 ECHO 끔
    newattr.c_cc[VMIN] = 1;                     // 최소 입력 문자 수를 1로 설정
    newattr.c_cc[VTIME] = 0;                    // 최소 읽기 대기 시간을 0으로 설정
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr); // 터미널에 설정 입력
    c = getchar();                              // 키보드 입력 읽음
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr); // 원래의 설정으로 복구
    return c;
}

int PutKey(int max)
{
    char put;
    while(1)
    {
        put=getch();
        put=atoi(&put);     //입력받은 키(문자)를 정수로 변환
        if(put<1||put>max)
        continue;
        else
        break;
    }
    
    return put;
}

void Init_Monster(Monster* mob, int area, int m_max, int chr_lv)        //능력치 초기화
{
    const char* name[4]={"불 슬라임", "눈 슬라임", "숲 슬라임", "물 슬라임"};
    const char* num[10]={"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    int i;
    int rand_hp;

    for(i=0; i<m_max; i++)
    {
        rand_hp=rand()%800+200;               //수치는 플레이어 레벨에 맞춰 능동적으로 변화할 예정
        strcpy(mob[i].name, name[area-1]);    //출현 몬스터 이름
        strcat(mob[i].name, num[i]);          //몬스터 번호
        mob[i].hp=rand_hp+50*chr_lv;          //200~1000랜덤
        mob[i].atk=80+3*chr_lv;               //세부 수치 수정 예정
        mob[i].def=40+3*chr_lv;               //세부 수치 수정 예정
        mob[i].exp=3+rand()%5;                //세부 수치 수정 예정
        mob[i].state=allive;                  //사망 상태
        mob[i].type=area;                     //구역에 따른 몬스터 종류
        mob[i].cd=0;                          //스킬 쿨다운
    }
}

void Init_Guardian(Monster* guard, Player* chr) //수호대, 캐릭터
{
    int lv, class, overlap=0;
    int i,j;
    int check[6]={0, };
    const char* class_name[6]={"전사", "백마법사", "흑마법사", "적마법사", "궁수", "검사"};
    const char* class_skill[6]={"", "힐", "파이어월", "파이어볼", "집중타", "럭키스트라이크"};

    for(i=0; i<5; i++)
    {
        class=rand()%6+1;
        for(j=0; j<5; j++)      //중복처리
        {
            if(check[j]==class)
            overlap=1;
        }
        if(overlap==1)
        {
            i--;
            overlap=0;
            continue;
        }

        strcpy(guard[i].name, class_name[class-1]);
        strcpy(guard[i].skill, class_skill[class-1]);
        lv=rand()%5+chr->lv;

        switch(class)
        {
            case 1: //전사
            guard[i].hp = 250 + 50*lv;
            guard[i].atk = 100 + 20*lv;
            guard[i].def = 160 + 40*lv;
            guard[i].exp = 30;
            guard[i].state = allive;
            guard[i].class = class;
            guard[i].cd=0;
            break;
            case 2: //백마법사
            guard[i].hp = 150 + 50*lv;
            guard[i].atk = 100 + 20*lv;
            guard[i].def = 90 + 40*lv;
            guard[i].exp = 30;
            guard[i].state = allive;
            guard[i].class = class;
            guard[i].cd=0;
            break;
            case 3: //흑마법사
            guard[i].hp = 150 + 50*lv;
            guard[i].atk = 250 + 20*lv;
            guard[i].def = 90 + 40*lv;
            guard[i].exp = 30;
            guard[i].state = allive;
            guard[i].class = class;
            guard[i].cd=0;
            break;
            case 4: //적마법사
            guard[i].hp = 100 + 50*lv;
            guard[i].atk = 200 + 20*lv;
            guard[i].def = 80 + 40*lv;
            guard[i].exp = 30;
            guard[i].state = allive;
            guard[i].class = class;
            guard[i].cd=0;
            break;
            case 5: //궁수
            guard[i].hp = 100 + 50*lv;
            guard[i].atk = 230 + 20*lv;
            guard[i].def = 90 + 40*lv;
            guard[i].exp = 30;
            guard[i].state = allive;
            guard[i].class = class;
            guard[i].cd=0;
            break;
            case 6: //검사
            guard[i].hp = 100 + 50*lv;
            guard[i].atk = 220 + 20*lv;
            guard[i].def = 100 + 40*lv;
            guard[i].exp = 30;
            guard[i].state = allive;
            guard[i].class = class;
            guard[i].cd=0;
            break;
        }
        
    }
}

void Init_Player(Player* chr)   //스테이터스 초기화
{
    const char* name[5]={"이시영", "이영광", "원영진", "박영진", "박영선"};
    const char* class_name[6]={"전사", "백마법사", "흑마법사", "적마법사", "궁수", "검사"};
    int check[5]={0, };
    int class, i, j, overlap=0;

    for(i=0; i<5; i++)
    {
        class=rand()%6+1;
        for(j=0; j<5; j++)      //중복처리
        {
            if(check[j]==class)
            {
                i--;
                overlap=1;
                break;
            }
        }
        if(overlap==1)
        {
            overlap=0;
            continue;
        }

        strcpy(chr[i].name, name[i]);                           //캐릭터 이름
        strcpy(chr[i].class_name, class_name[class-1]);         //직업 이름
        chr[i].class=class;                                     //직업 종류
        switch(class)
        {
            case 1:     //전사
            chr[i].lv=1;
            chr[i].max_hp=300;
            chr[i].max_mp=0;
            chr[i].hp=chr[i].max_hp;
            chr[i].mp=chr[i].max_mp;
            chr[i].atk=150;
            chr[i].total_atk=chr[i].atk;
            chr[i].def=200;
            chr[i].total_def=chr[i].def;
            chr[i].exp=0;
            chr[i].state=allive;
            chr[i].area=1;
            break;

            case 2:     //백마법사
            chr[i].lv=1;
            chr[i].max_hp=200;
            chr[i].max_mp=150;
            chr[i].hp=chr[i].max_hp;
            chr[i].mp=chr[i].max_mp;
            chr[i].atk=100;
            chr[i].total_atk=chr[i].atk;
            chr[i].def=100;
            chr[i].total_def=chr[i].def;
            chr[i].exp=0;
            chr[i].state=allive;
            chr[i].area=1;
            break;

            case 3:     //흑마법사
            chr[i].lv=1;
            chr[i].max_hp=200;
            chr[i].max_mp=150;
            chr[i].hp=chr[i].max_hp;
            chr[i].mp=chr[i].max_mp;
            chr[i].atk=500;
            chr[i].total_atk=chr[i].atk;
            chr[i].def=100;
            chr[i].total_def=chr[i].def;
            chr[i].exp=0;
            chr[i].state=allive;
            chr[i].area=1;
            break;

            case 4:     //적마법사
            chr[i].lv=1;
            chr[i].max_hp=150;
            chr[i].max_mp=100;
            chr[i].hp=chr[i].max_hp;
            chr[i].mp=chr[i].max_mp;
            chr[i].atk=380;
            chr[i].total_atk=chr[i].atk;
            chr[i].def=80;
            chr[i].total_def=chr[i].def;
            chr[i].exp=0;
            chr[i].state=allive;
            chr[i].area=1;
            break;

            case 5:     //궁수
            chr[i].lv=1;
            chr[i].max_hp=150;
            chr[i].max_mp=150;
            chr[i].hp=chr[i].max_hp;
            chr[i].mp=chr[i].max_mp;
            chr[i].atk=450;
            chr[i].total_atk=chr[i].atk;
            chr[i].def=120;
            chr[i].total_def=chr[i].def;
            chr[i].exp=0;
            chr[i].state=allive;
            chr[i].area=1;
            break;

            case 6:     //검사
            chr[i].lv=1;
            chr[i].max_hp=150;
            chr[i].max_mp=150;
            chr[i].hp=chr[i].max_hp;
            chr[i].mp=chr[i].max_mp;
            chr[i].atk=300;
            chr[i].total_atk=chr[i].atk;
            chr[i].def=150;
            chr[i].total_def=chr[i].def;
            chr[i].exp=0;
            chr[i].state=allive;
            chr[i].area=1;
            break;

            default:
            printf("INIT ERROR!!\n");
            break;
        }
        check[i]=class;
    }
}

void Battlemap(int (*battlemap)[24], Player *chr, Consumption *ptr)  //전투화면 맵 출력함수
{
    int itemlist[24][3]={
        {9,9,6},
        {10,0,8},
        {11,0,8},
        {12,0,8},
        {13,0,8},
        {14,0,8},
        {15,0,8},
        {16,0,8},
        {17,0,8},
        {18,0,8},
        {19,0,8},
        {20,0,8},
        {21,0,8},
        {0,0,8},
        {0,0,8},
        {0,0,8},
        {0,0,8},
        {0,0,8},
        {0,0,8},
        {0,0,8},
        {0,0,8},
        {0,0,8},
        {0,0,8},
        {9,9,7}
    };
    system("clear");

    for (int i=0; i<24; i++)
    {
        for(int j=0; j<24; j++)
        {
            if(battlemap[i][j]==0)
                printf("   ");
            else if(battlemap[i][j]==1)
                printf("╭");
            else if(battlemap[i][j]==2)
                printf("╮");
            else if(battlemap[i][j]==3)       
                printf("╰");
            else if(battlemap[i][j]==4)
                printf("╯"); 
            else if(battlemap[i][j]==8)
                printf("│");
            else if(battlemap[i][j]==9)
                printf("───");                                        
        }
        
        if(i==1)
        {
            for(int i=0; i<3; i++)
            {
                if(itemlist[1][i]==10)
                    printf("   보유 아이템 리스트  ");
                else if(itemlist[1][i]==8)
                    printf("  │");
                else if(itemlist[1][i]==0)
                    printf(" ");            
            }
        }

        for(int k=0; k<3; k++)
        {
            if(itemlist[i][k]==11)
                printf(" HP하      %2d", ptr[0].count);
            else if(itemlist[i][k]==12)
                printf(" HP중      %2d", ptr[1].count);
            else if(itemlist[i][k]==13)
                printf(" HP상      %2d", ptr[2].count);
            else if(itemlist[i][k]==14)
                printf(" MP하      %2d", ptr[3].count);
            else if(itemlist[i][k]==15)
                printf(" MP중      %2d", ptr[4].count);
            else if(itemlist[i][k]==16)
                printf(" MP상      %2d", ptr[5].count);
            else if(itemlist[i][k]==17)
                printf(" ALL하     %2d", ptr[6].count);    
            else if(itemlist[i][k]==18)
                printf(" All중     %2d", ptr[7].count);  
            else if(itemlist[i][k]==19)
                printf(" All상     %2d", ptr[8].count);
            else if(itemlist[i][k]==20)
                printf(" 부활물약  %2d", ptr[9].count);
            else if(itemlist[i][k]==21)
                printf(" 텐트      %2d", ptr[10].count);                  
            else if(itemlist[i][k]==0)
                printf("             ");
            else if(itemlist[i][k]==8 && i!=1)
                printf("│");          
            else if(itemlist[i][k]==9)
                printf("─────────────");
            else if(itemlist[i][k]==6)
                printf("╮");
            else if(itemlist[i][k]==7)
                printf("╯");
        }
        printf("\n");
    }
    
    printf("╭──────────────────╮");
    printf("─────────────────╮");
    printf("──────────────────╮");
    printf("─────────────────╮");
    printf("───────────────────╮\n");
    printf("│%10s   이시영 │%10s  이영광 │%10s   원영진 │%10s  박영진 │%10s   박영선  │\n", chr[0].class_name, chr[1].class_name, chr[2].class_name, chr[3].class_name, chr[4].class_name);
    printf("│ HP       %5d   │ HP       %5d  │ HP         %5d │ HP        %5d │ HP         %5d  │\n", chr[0].hp, chr[1].hp, chr[2].hp, chr[3].hp, chr[4].hp);
    printf("│ MP       %5d   │ MP       %5d  │ MP         %5d │ MP        %5d │ MP         %5d  │\n", chr[0].mp, chr[1].mp, chr[2].mp, chr[3].mp, chr[4].mp);
    printf("│ atk      %5d   │ atk      %5d  │ atk        %5d │ atk       %5d │ atk        %5d  │\n", chr[0].total_atk, chr[1].total_atk, chr[2].total_atk, chr[3].total_atk, chr[4].total_atk);
    printf("│ def      %5d   │ def      %5d  │ def        %5d │ def       %5d │ def        %5d  │\n", chr[0].total_def, chr[1].total_def, chr[2].total_def, chr[3].total_def, chr[4].total_def);
    printf("│ exp      %5d   │ exp      %5d  │ exp        %5d │ exp       %5d │ exp        %5d  │\n", chr[0].exp, chr[1].exp, chr[2].exp, chr[3].exp, chr[4].exp);
    printf("╰──────────────────╯");
    printf("─────────────────╯");
    printf("──────────────────╯");
    printf("─────────────────╯");
    printf("───────────────────╯\n");
}

int Battle(Player * chr, Consumption *ptr, int (*battlemap)[24], int m_type)    // 몬스터 타입 1.일반몹 2.수호대 3.보스몹
{
    // 전투 시스템 관련 변수
    int turn=1, runaway=1, death=0, exp=0, i, result=0;
    // 턴수, 전투 종료, 죽은 적 수, 잡았을 때 경험치, , 전투결과

    // 플레이어 관련 변수
    int run, p_atk=0, menu, s_item, s_target, s_skill, s_unlock=1, sword=0;
    //도망확률, 공격순서, 행동 선택, 아이템 선택, 공격할 적 선택, 스킬 선택, 해금된 스킬
    Skillstat skill[10];        // 스킬 수치 받아올 구조체 배열
    Skillstat* pskill=skill;    // 구조체 배열을 가리키는 구조체 포인터변수
    Mobskillstat mskill[10];
    Mobskillstat* pmskill=mskill;

    int buff_atk[5]={0, };      // 공격버프 전 공격력 저장
    int buff_def[5]={0, };      // 방어버프 전 방어력 저장

    int white_dur1=0;           // 공격버프 지속시간
    int white_dur2=0;           // 방어버프 지속시간
    int sword_buff=0;           // 검사 버프 전 공격력 저장
    int sword_dur=0;            // 검사 버프 지속시간

    int white_cd[5]={0, };      // 백마법사 스킬 쿨타임
    int black_cd[5]={0, };      // 흑마법사 스킬 쿨타임
    int red_cd[5]={0, };        // 적마법사 스킬 쿨타임
    int archer_cd[5]={0, };     // 궁수 스킬 쿨타임
    int sword_cd=0;             // 검사 스킬 쿨타임

    // 몬스터 관련 변수
    int m_atk=0, m_skill, m_target, m_max;
    // 공격순서, 스킬 발동 확률, 타겟, 생성된 몹 수

    // 수호대 관련 변수
    int guard_buff=0, guard_class=0;
    // 수호대 검사 버프 전 공격력 저장, 수호대 클래스(검사)저장
    switch(m_type)
    {
        case 1:
        m_max=rand()%10+1;  //일반몹은 1~10마리
        break;
        case 2:
        m_max=5;            //수호대 하나당 5명 고정
        break;
        case 3:
        m_max=rand()%6+1;   //0은 보스자리+ 0~6마리 일반몹
        break;
    }
    Monster mob[m_max]; //랜덤 수 몹 생성   보스전일때 0번은 보스자리
    Monster* pmob=mob;

    switch(m_type)
    {
        case 1:
        Init_Monster(pmob, chr->area, m_max, chr->lv); //몹 초기화
        printf("야생의 몬스터가 등장했다!!\n");
        break;
        case 2:
        Init_Guardian(mob, chr);
        printf("적(?)과 조우했다!!\n");
        break;
        case 3:
        m_max=rand()%6+1;   //0은 보스자리+ 0~6마리 일반몹
        //보스 구조체 추가예정
        printf("보스와 마주쳤다!!\n");
        break;
    }

    for(i=0; i<5; i++)
    {
        if(chr[i].class==6)
        {
            sword_buff=chr[i].total_atk;
            break;
        }
    }
    Battlemap(battlemap, chr, ptr);
    usleep(500000);
    while(runaway)      //0이면 종료
    {
        if(chr[p_atk].state==dead)
        {
            p_atk++;
            continue;
        }
        printf("%s의 턴 !\n", chr[p_atk].name);
        usleep(500000);
        Battlemap(battlemap, chr, ptr);
        printf("현재 턴: %d\n", turn);
        printf("1.일반 공격 2.스킬 사용 3.아이템 사용 4.도망가기\n");
        menu=PutKey(4);
        switch(menu)
        {
            case 1:     //  일반공격
            printf("누구를 공격?\n");
            s_target=PutKey(m_max);
            s_target-=1;
            printf("\n");
            if(mob[s_target].state==dead)   //사망한 몹 공격 못하게 체크
            {
                printf("이미 죽은 대상입니다.\n");
                usleep(500000);
                continue;
            }
            printf("%s의 공격!\n %s에게 %d의 대미지를 입혔다!\n", chr[p_atk].name, mob[s_target].name, chr[p_atk].total_atk-mob[s_target].def/2);

            if(mob[s_target].hp-chr[p_atk].total_atk-mob[s_target].def/2<=0)
            printf("공격이 통하지 않았다.\n");
            else
            mob[s_target].hp-=chr[p_atk].total_atk-mob[s_target].def/2; //대미지 적용
            break;
            case 2:     //  스킬사용
            switch(chr[p_atk].class)
            {
                case 1: //전사
                printf("사용할 수 있는 스킬이 없습니다.\n");
                usleep(500000);
                continue;
                case 2: //백마법사
                if(chr[p_atk].lv<10)       //레벨에 따라 사용 가능한 스킬 해금
                {
                    printf("1.힐\n");
                    s_unlock=1;
                }
                else if(chr[p_atk].lv>=10&&chr[p_atk].lv<15)
                {
                    printf("1.힐 2.공격력 업!\n");
                    s_unlock=2;
                }
                else if(chr[p_atk].lv>=15&&chr[p_atk].lv<30)
                {
                    printf("1.힐 2.공격력 업! 3.그레이터 힐 4.방어력 업!\n");
                    s_unlock=4;
                }
                else
                {
                    printf("1.힐 2.공격력 업! 3.그레이터 힐 4.방어력 업! 5.힐 올\n");
                    s_unlock=5;
                }

                s_skill=PutKey(s_unlock);
                switch(s_skill)
                {
                    case 1: //힐
                    *pskill=WhiteWizardSkill(chr, p_atk, 0, 0);
                    if(chr[p_atk].mp<pskill->skillmp)
                    {
                        printf("MP가 부족합니다.\n");
                        usleep(500000);
                        continue;
                    }
                    printf("누구를? \n");
                    s_target=PutKey(5);
                    s_target-=1;
                    *pskill=WhiteWizardSkill(chr, p_atk, s_target, 0);
                    if(chr[s_target].state==dead)
                    {
                        printf("죽은 대상입니다.\n");
                        usleep(500000);
                        continue;
                    }
                    else if(chr[s_target].hp>=chr[s_target].max_hp)
                    {
                        printf("이미 최대 체력입니다.\n");
                        usleep(500000);
                        continue;
                    }
                    chr[s_target].hp+=pskill->skillheal;
                    chr[p_atk].mp-=pskill->skillmp;
                    if(chr[s_target].hp>chr[s_target].max_hp)
                    {
                        printf("%s의 HP를 %d 회복했다.\n", chr[s_target].name, chr[s_target].hp-chr[s_target].max_hp);
                        chr[s_target].hp=chr[s_target].max_hp;
                    }
                    else
                    printf("%s의 HP를 %d 회복했다.\n", chr[s_target].name, pskill->skillheal);
                    white_cd[0]=2;
                    break;
                    case 2: //공격력업
                    *pskill=WhiteWizardSkill(chr, p_atk, 0, 3);
                    if(chr[p_atk].mp < pskill->skillmp)
                    {
                        printf("MP가 부족합니다.\n");
                        usleep(500000);
                        continue;
                    }
                    else if(white_dur1>0)
                    {
                        printf("이미 적용된 스킬입니다.\n");
                        usleep(500000);
                        continue;
                    }
                    else if(white_cd[1]>0)
                    {
                        printf("쿨타임 중 입니다.\n남은 쿨타임: %d턴\n", white_cd[1]);
                        usleep(500000);
                        continue;
                    }
                    chr[p_atk].mp-=pskill->skillmp;
                    for(i=0; i<5; i++)
                    {
                        *pskill=WhiteWizardSkill(chr, p_atk, i, 3);
                        if(chr[i].state==dead)
                        continue;
                        else
                        {
                            buff_atk[i] = chr[i].total_atk;
                            chr[i].total_atk += pskill->skillatk;
                        }    
                    }
                    printf("수호대의 공격력이 상승했다!\n");
                    usleep(500000);
                    white_dur1=2;
                    white_cd[1]=2;
                    break;
                    case 3: // 그레이터 힐
                    *pskill=WhiteWizardSkill(chr, p_atk, 0, 1);
                    if(chr[p_atk].mp<pskill->skillmp)
                    {
                        printf("MP가 부족합니다.\n");
                        usleep(500000);
                        continue;
                    }
                    printf("누구를? \n");
                    s_target=PutKey(5);
                    s_target-=1;
                    if(chr[s_target].state==dead)
                    {
                        printf("죽은 대상입니다.\n");
                        usleep(500000);
                        continue;
                    }
                    else if(chr[s_target].hp>=chr[s_target].max_hp)
                    {
                        printf("이미 최대 체력입니다.\n");
                        usleep(500000);
                        continue;
                    }
                    *pskill=WhiteWizardSkill(chr, p_atk, s_target, 1);
                    chr[s_target].hp+=pskill->skillheal;
                    if(chr[s_target].hp>chr[s_target].max_hp)
                    {
                        printf("%s의 HP를 %d 회복했다.\n", chr[s_target].name, chr[s_target].hp-chr[s_target].max_hp);
                        chr[s_target].hp=chr[s_target].max_hp;
                    }
                    else
                    printf("%s의 HP를 %d 회복했다.\n", chr[s_target].name, pskill->skillheal);
                    chr[p_atk].mp-=pskill->skillmp;
                    white_cd[2]=2;
                    break;
                    case 4: // 방어력업
                    *pskill=WhiteWizardSkill(chr, p_atk, 0, 4);
                    if(chr[p_atk].mp < pskill->skillmp)
                    {
                        printf("MP가 부족합니다.\n");
                        usleep(500000);
                        continue;
                    }
                    else if(white_dur2>0)
                    {
                        printf("이미 적용된 스킬입니다.\n");
                        usleep(500000);
                        continue;
                    }
                    else if(white_cd[3]>0)
                    {
                        printf("쿨타임 중 입니다.\n남은 쿨타임: %d턴\n", white_cd[3]);
                        usleep(500000);
                        continue;
                    }
                    chr[p_atk].mp-=pskill->skillmp;
                    for(i=0; i<5; i++)
                    {
                        *pskill=WhiteWizardSkill(chr, p_atk, i, 4);
                        if(chr[i].state==dead)
                        continue;
                        else
                        {
                            buff_def[i] = chr[i].total_def;
                            chr[i].total_def += pskill->skilldef;
                        }
                    }
                    white_dur2=2;
                    white_cd[3]=2;
                    case 5: //힐 올
                    *pskill=WhiteWizardSkill(chr, p_atk, i, 2);
                    if(chr[p_atk].mp<pskill->skillmp)
                    {
                        printf("MP가 부족합니다.\n");
                        usleep(500000);
                        continue;
                    }
                    else if(white_cd[4]>0)
                    {
                        printf("쿨타임 중 입니다.\n남은 쿨타임: %d턴\n", white_cd[4]);
                        usleep(500000);
                        continue;
                    }

                    for(i=0; i<5; i++)
                    {
                        *pskill=WhiteWizardSkill(chr, p_atk, i, 2);
                        if(chr[i].state==dead)
                        continue;
                        else
                        {
                            chr[i].hp+=pskill->skillheal;
                            if(chr[i].hp>=chr[i].max_hp)
                            {
                                printf("%s의 HP를 %d 회복했다.\n", chr[i].name, chr[i].hp-chr[i].max_hp);
                                chr[i].hp=chr[i].max_hp;
                            }
                            else
                            printf("%s의 HP를 %d 회복했다.\n", chr[i].name, pskill->skillheal);
                        }
                    }
                    white_cd[4]=2;
                    break;
                }
                break;

                case 3: //흑마법사
                if(chr[p_atk].lv<15)       //레벨에 따라 사용 가능한 스킬 해금
                {
                    printf("1.파이어볼\n");
                    s_unlock=1;
                }
                else if(chr[p_atk].lv>=15&&chr[p_atk].lv<20)
                {
                    printf("1.파이어볼 2.파이어월\n");
                    s_unlock=2;
                }
                else if(chr[p_atk].lv>=20&&chr[p_atk].lv<25)
                {
                    printf("1.파이어볼 2.파이어월 3.썬더브레이커\n");
                    s_unlock=3;
                }
                else
                {
                    printf("1.파이어볼 2.파이어월 3.썬더브레이커 4.블리자드\n");
                    s_unlock=4;
                }
                s_skill=PutKey(s_unlock);
                *pskill=blackWizard(chr, p_atk, s_skill-1);
                if(chr[p_atk].mp<pskill->skillmp)
                {
                    printf("MP가 부족합니다.\n");
                    usleep(500000);
                    continue;
                }
                else if(black_cd[s_skill-1]>0)
                {
                    printf("쿨타임 중 입니다.\n남은 쿨타임: %d턴\n", black_cd[s_skill-1]);
                    usleep(500000);
                    continue;
                }
                switch(s_skill)
                {
                    case 1: //파이어볼
                    printf("누구를?\n");
                    s_target=PutKey(m_max);
                    s_target-=1;
                    if(mob[s_target].state==dead)
                    {
                        printf("이미 죽은 대상입니다\n");
                        usleep(500000);
                        continue;
                    }
                    chr[p_atk].mp-=pskill->skillmp;
                    mob[s_target].hp-=(chr[p_atk].total_atk+ pskill->skillatk)-mob[s_target].def/2;
                    printf("%s의 %s ! %s은(는) %d의 피해를 입었다.\n", chr[p_atk].name, pskill->skillname, mob[s_target].name, 
                    (chr[p_atk].total_atk+ pskill->skillatk)-mob[s_target].def/2);
                    black_cd[0]=2;
                    break;
                    case 2: //파이어월
                    chr[p_atk].mp-=pskill->skillmp;
                    for(i=0; i<m_max; i++)
                    {
                        if(mob[i].state==dead)
                        continue;
                        else
                        mob[i].hp-=(chr[p_atk].total_atk+pskill->skillatk)-mob[s_target].def/2;
                    }
                    printf("%s의 %s !\n", chr[p_atk].name, pskill->skillname);
                    black_cd[1]=2;
                    break;
                    case 3: //썬더브레이커
                    chr[p_atk].mp-=pskill->skillmp;
                    for(i=0; i<m_max; i++)
                    {
                        if(mob[i].state==dead)
                        continue;
                        else
                        mob[i].hp-=(chr[p_atk].total_atk+pskill->skillatk)-mob[s_target].def/2;
                    }
                    printf("%s의 %s !\n", chr[p_atk].name, pskill->skillname);
                    black_cd[2]=2;
                    break;
                    case 4: //블리자드
                    chr[p_atk].mp-=pskill->skillmp;
                    for(i=0; i<m_max; i++)
                    {
                        if(mob[i].state==dead)
                        continue;
                        else
                        mob[i].hp-=(chr[p_atk].total_atk+pskill->skillatk)-mob[s_target].def/2;
                    }
                    printf("%s의 %s !\n", chr[p_atk].name, pskill->skillname);
                    black_cd[3]=2;
                    break;
                }
                break;

                case 4: //적마법사
                if(chr[p_atk].lv<20)       //레벨에 따라 사용 가능한 스킬 해금
                {
                    printf("1.힐 2.파이어볼\n");
                    s_unlock=2;
                }
                else
                {
                    printf("1.힐 2.파이어볼 3.힐올 4.파이어월\n");
                    s_unlock=4;
                }
                s_skill=PutKey(s_unlock);
                *pskill=RedWizardSkill(chr, p_atk, 0, s_skill-1);
                if(chr[p_atk].mp<pskill->skillmp)
                {
                    printf("MP가 부족합니다.\n");
                    usleep(500000);
                    continue;
                }
                else if(red_cd[s_skill-1]>0)
                {
                    printf("쿨타임 중 입니다.\n남은 쿨타임: %d턴\n", red_cd[s_skill-1]);
                    usleep(500000);
                    continue;
                }
                switch(s_skill)
                {
                    case 1: //힐
                    printf("누구를?\n");
                    s_target=PutKey(5);
                    s_target-=1;
                    *pskill=RedWizardSkill(chr, p_atk, s_target, s_skill-1);
                    if(chr[s_target].state==dead)
                    {
                        printf("이미 죽은 대상입니다\n");
                        usleep(500000);
                        continue;
                    }
                    else if(chr[s_target].hp>=chr[s_target].max_hp)
                    {
                        printf("이미 최대 체력입니다.\n");
                        usleep(500000);
                        continue;
                    }
                    chr[p_atk].mp-=pskill->skillmp;
                    chr[s_target].hp+=pskill->skillheal;

                    if(chr[s_target].hp>chr[s_target].max_hp)
                    {
                        printf("%s의 HP를 %d 회복했다.\n", chr[s_target].name, chr[s_target].hp-chr[s_target].max_hp);
                        chr[s_target].hp=chr[s_target].max_hp;
                    }
                    else
                    printf("%s의 HP를 %d 회복했다.\n", chr[s_target].name, pskill->skillheal);
                    break;

                    case 2: //파이어볼
                    printf("누구를?\n");
                    s_target=PutKey(m_max);
                    s_target-=1;
                    if(mob[s_target].state==dead)
                    {
                        printf("이미 죽은 대상입니다\n");
                        usleep(500000);
                        continue;
                    }
                    chr[p_atk].mp-=pskill->skillmp;
                    mob[s_target].hp-=(chr[p_atk].total_atk+ pskill->skillatk)-mob[s_target].def/2;
                    printf("%s의 %s ! %s은(는) %d의 피해를 입었다.\n", chr[p_atk].name, pskill->skillname, mob[s_target].name, 
                    (chr[p_atk].total_atk+ pskill->skillatk)-mob[s_target].def/2);
                    break;

                    case 3: //힐올
                    for(i=0; i<5; i++)
                    {
                        *pskill=RedWizardSkill(chr, p_atk, i, s_skill-1);
                        if(chr[i].state==dead)
                        continue;
                        else
                        {
                            chr[i].hp+=pskill->skillheal;
                            if(chr[i].hp>=chr[i].max_hp)
                            {
                                printf("%s의 HP를 %d 회복했다.\n", chr[i].name, chr[i].hp-chr[i].max_hp);
                                chr[i].hp=chr[i].max_hp;
                            }
                            else
                            printf("%s의 HP를 %d 회복했다.\n", chr[i].name, pskill->skillheal);
                        }
                        usleep(500000);
                    }
                    break;

                    case 4: //파이어월
                    chr[p_atk].mp-=pskill->skillmp;
                    for(i=0; i<m_max; i++)
                    {
                        if(mob[i].state==dead)
                        continue;
                        else
                        mob[i].hp-=(chr[p_atk].total_atk+pskill->skillatk)-mob[s_target].def/2;
                    }
                    printf("%s의 %s !\n", chr[p_atk].name, pskill->skillname);
                    break;
                }
                red_cd[s_skill-1]=2;
                break;

                case 5: //궁수
                if(chr[p_atk].lv<10)       //레벨에 따라 사용 가능한 스킬 해금
                {
                    printf("사용할 수 있는 스킬이 없습니다.\n");
                    usleep(500000);
                    continue;
                }
                else if(chr[p_atk].lv>=10&&chr[p_atk].lv<15)
                {
                    printf("1.집중타\n");
                    s_unlock=1;
                }
                else if(chr[p_atk].lv>=15&&chr[p_atk].lv<20)
                {
                    printf("1.집중타 2.듀얼샷\n");
                    s_unlock=2;
                }
                else
                {
                    printf("1.집중타 2.듀얼샷 3.마스터샷\n");
                    s_unlock=3;
                }
                s_skill=PutKey(s_unlock);
                s_skill-=1;
                *pskill=ArcherSkill(chr, p_atk, s_skill);
                if(chr[p_atk].mp<pskill->skillmp)
                {
                    printf("MP가 부족합니다.\n");
                    usleep(500000);
                    continue;
                }
                else if(archer_cd[s_skill]>0)
                {
                    printf("쿨타임 중 입니다.\n남은 쿨타임: %d턴\n", archer_cd[s_skill]);
                    usleep(500000);
                    continue;
                }
                printf("누구를?\n");
                s_target=PutKey(m_max);
                s_target-=1;
                if(mob[s_target].state==dead)
                {
                    printf("이미 죽은 대상입니다.\n");
                    usleep(500000);
                    continue;
                }
                chr[p_atk].mp-=pskill->skillmp;
                mob[s_target].hp-=(chr[p_atk].total_atk+ pskill->skillatk)-mob[s_target].def/2;
                printf("%s의 %s ! %s은(는) %d의 피해를 입었다.\n", chr[p_atk].name, pskill->skillname, mob[s_target].name, 
                (chr[p_atk].total_atk+ pskill->skillatk)-mob[s_target].def/2);
                break;

                case 6: //검사
                if(chr[p_atk].lv<10)       //레벨에 따라 사용 가능한 스킬 해금
                {
                    printf("사용할 수 있는 스킬이 없습니다.\n");
                    usleep(500000);
                    continue;
                }
                else
                {
                    printf("1.럭키스트라이크\n");
                    s_unlock=1;
                }
                s_skill=PutKey(s_unlock);
                *pskill=SwordManSkill(chr, p_atk);
                if(chr[p_atk].mp < pskill->skillmp)
                {
                    printf("MP가 부족합니다.\n");
                    usleep(500000);
                    continue;
                }
                else if(sword_dur>0)
                {
                    printf("이미 적용된 스킬입니다.\n");
                    usleep(500000);
                    continue;
                }
                else if(sword_cd>0)
                {
                    printf("쿨타임 중 입니다.\n남은 쿨타임: %d턴\n", sword_cd);
                    usleep(500000);
                    continue;
                }
                chr[p_atk].mp-=pskill->skillmp;
                sword_buff=chr[p_atk].total_atk;
                chr[p_atk].total_atk=pskill->skillatk;
                printf("%s의 %s ! 공격력이 %d 상승했다.\n", chr[p_atk].name, pskill->skillname, chr[p_atk].total_atk-sword_buff);
                break;
            }
            usleep(500000);
            break;
            case 3:     //  아이템 사용
            printf("무슨 아이템?\n");
            scanf("%d", &s_item);
            if(s_item<0||s_item>10)
            {
                printf("1~10중에 선택해주세요\n");
                usleep(500000);
                continue;
            }
            if(ptr[s_item-1].count<=0)
            {
                printf("아이템이 부족합니다.\n");
                usleep(500000);
                continue;
            }
            else
            {
                printf("누구에게?\n");
                s_target=PutKey(5);
                s_target-=1;
                *ptr=itemList(chr, s_target, s_item-1);
                switch(s_item)
                {
                    case 1: // HP 하
                    case 2: // HP 중
                    case 3: // HP 상
                    chr[s_target].hp+=ptr->hp;
                    ptr->count--;
                    if(chr[s_target].hp>chr[s_target].max_hp);
                    chr[s_target].hp=chr[s_target].max_hp;
                    printf("%s에게 %s를 사용합니다.", chr[s_target].name, ptr->name);
                    break;

                    case 4: // MP 하
                    case 5: // MP 중
                    case 6: // MP 상
                    chr[s_target].mp+=ptr->mp;
                    ptr->count--;
                    if(chr[s_target].mp>chr[s_target].max_mp);
                    chr[s_target].mp=chr[s_target].max_mp;
                    printf("%s에게 %s를 사용합니다.", chr[s_target].name, ptr->name);
                    break;

                    case 7: // ALL 하
                    case 8: // ALL 중
                    case 9: // ALL 상
                    chr[s_target].hp+=ptr->hp;
                    chr[s_target].mp+=ptr->mp;
                    ptr->count--;
                    if(chr[s_target].hp>chr[s_target].max_hp);
                    chr[s_target].hp=chr[s_target].max_hp;
                    if(chr[s_target].mp>chr[s_target].max_mp);
                    chr[s_target].mp=chr[s_target].max_mp;
                    printf("%s에게 %s를 사용합니다.", chr[s_target].name, ptr->name);
                    break;

                    case 10: // 부활물약
                    if(chr[s_target].state==dead)   //대상이 죽었으면 부활
                    {
                        chr[s_target].state=allive;
                        chr[s_target].hp=chr[s_target].max_hp/10;
                        chr[s_target].mp=chr[s_target].max_mp/10;
                    }
                    else
                    {
                        printf("살아있는 대상에게는 사용할 수 없습니다.\n");
                        usleep(500000);
                        continue;
                    }
                    break;
                }
            }
            //아이템 효과 함수
            break;
            case 4:     //  도망가기
            printf("수호대는 등을 돌리고 도망쳤다!\n");
            usleep(500000);
            run=rand()%10+1;
            if(run<=3)
            {
                printf("수호대는 무사히 도망쳤다!\n");
                runaway=0;      //전투(반복문) 종료
                continue;
            }
            else
            printf("수호대는 도망치지 못했다.\n");
            usleep(500000);
            break;
            default:    //  예외처리
            break;
        }
        usleep(700000);
        Battlemap(battlemap, chr, ptr);

        for(i=0; i<m_max; i++)  //몬스터 hp체크해 사망여부 갱신, 정산
        {
            if(mob[i].hp<=0)
            mob[i].state=dead;

            if(mob[i].state==dead)
            {
                exp+=mob[i].exp;
                death++;
            }
        }
        if(death==m_max)
        {
            //전투결과 처리result
            break;
        }
        else
        {
            death=0;
            exp=0;
        }

        //몬스터 턴 시작
        while(1)
        {
            if(m_atk>=m_max)
            m_atk=0;
            if(mob[m_atk].state==dead)
            m_atk++;
            else
            break;
        }

        m_skill=rand()%30+1;
        while(1)
        {
            m_target=rand()%5;
            if(chr[m_target].state==dead)                           //사망상태인 캐릭터 공격하지 않음
            continue;
            else if(mob[m_atk].class>0&&mob[m_target].state==dead)  //힐쓸때 사망상태인 수호대에게 사용불가
            continue;
            else
            break;
        }
        if(mob[m_atk].class==1) //전사면 스킬을 발동하지 않음
        m_skill=1;
        if(m_skill<30&&mob[m_atk].cd<=1)
        {
            switch(mob[m_atk].class)
            {
                case 2:     //백마법사
                mob[m_target].hp+= mob[m_target].hp/(rand()%15+10);
                printf("%s의 %s !\n", mob[m_atk].name, mob[m_atk].skill);
                break;

                case 3:     //흑마법사
                printf("%s의 %s !\n", mob[m_atk].name, mob[m_atk].skill);
                for(i=0; i<5; i++)
                {
                    if(chr[i].state==dead)
                    continue;
                    else
                    {
                        if(mob[m_atk].atk + (mob[m_atk].atk*(2/10)) - chr[i].total_def/2<=0)
                        continue;
                        else
                        chr[i].hp -= mob[m_atk].atk + (mob[m_atk].atk*(2/10)) - chr[i].total_def/2;
                    }
                }
                break;

                case 4:     //적마법사
                printf("%s의 %s !\n", mob[m_atk].name, mob[m_atk].skill);
                if(chr[m_target].hp-=chr[m_target].hp/(rand()%15+10)<=0)
                printf("피해는 없었다.\n");
                else
                chr[m_target].hp-=chr[m_target].hp/(rand()%15+10);
                break;

                case 5:     //궁수
                printf("%s의 %s !\n", mob[m_atk].name, mob[m_atk].skill);
                if(chr[m_target].hp-=chr[m_target].hp/(rand()%20+13)<=0)
                printf("피해는 없었다.\n");
                else
                chr[m_target].hp-=chr[m_target].hp/rand()%20+13;
                
                break;

                case 6:     //검사
                guard_buff=mob[m_atk].atk;
                mob[m_atk].atk*=rand()%3+1;
                printf("%s의 %s !\n", mob[m_atk].name, mob[m_atk].skill);
                printf("적의 공격력이 증가했다.\n");
                break;

                default:    //수호대가 아닐때
                *pmskill=Nmob(mob, m_atk, mob[m_atk].type-1);
                printf("%s의 %s 발동!\n", mob[m_atk].name, pmskill->skillname);
                usleep(500000);

                if(mob[m_atk].atk<chr[m_target].def/2)
                printf("%s은(는) 아무런 대미지도 입지 않았다.\n", chr[m_target].name);
                else
                {
                    chr[m_target].hp-= (mob[m_atk].atk+pmskill->skillatk)-chr[m_target].total_def/2;
                    printf("%s은(는) %d의 피해를  입었다!\n", chr[m_target].name, (mob[m_atk].atk+pmskill->skillatk)-chr[m_target].total_def/2);
                }
                break;
            }
            mob[m_atk].cd=3;
        }
        else
        {
            printf("%s의 공격!\n", mob[m_atk].name);
            usleep(500000);
            if(mob[m_atk].atk<chr[m_target].def/2)
            printf("%s은(는) 아무런 대미지도 입지 않았다.\n", chr[m_target].name);
            else
            {
                chr[m_target].hp-=mob[m_atk].atk-chr[m_target].def/2;
                printf("%s은(는) %d의 피해를 입었다!\n",chr[m_target].name, mob[m_atk].atk-chr[m_target].def/2);
            }
        }
        usleep(500000);
        for(i=0; i<5; i++)  //  캐릭터 hp체크해 사망 상태로 만들어줌
        {
            if(chr[i].state==allive&&chr[i].hp<=0)
            chr[i].state=dead;
        }
        //턴 증가, 공격 순서 변경
        p_atk++;
        m_atk++;
        if(p_atk>=5)
        {
            p_atk=0;
            for(i=0; i<5; i++)  //한 턴이 끝나면 지속시간, 쿨타임이 줄어든다
            {
                if(white_dur1>0)
                white_dur1--;
                if(white_dur2>0)
                white_dur2--;
                if(white_dur1==0)
                chr[i].total_atk=buff_atk[i];
                if(white_dur2==0)
                chr[i].total_def=buff_def[i];

                if(sword_dur>0)
                sword_dur--;

                if(sword_dur==0)
                chr[sword].total_atk=sword_buff;

                if(mob[guard_class].cd==1)
                mob[guard_class].atk=guard_buff;

                if(white_cd[i]>0)
                white_cd[i]--;
                if(black_cd[i]>0)
                black_cd[i]--;
                if(red_cd[i]>0)
                red_cd[i]--;
                if(archer_cd[i]>0)
                archer_cd[i]--;
                if(sword_cd>0)
                sword_cd--;
            }
            for(i=0; i<m_max; i++)
            {
                if(mob[i].cd>1)
                mob[i].cd--;
            }
            turn++;
        }
    }
    if(runaway!=0)
    {
        printf("적을 물리쳤다! \n");
        usleep(500000);
        for(i=0; i<5; i++)
        {
            chr[i].exp+=exp/5;
        }
    }
    //전투종료 상황에 따라 메세지 출력 or 경험치, 아이템 정산

    return result;  //전투 결과, 도망 or 승리 or 패배
}

int main(void)
{
    Player chr[5];
    Player * pchr=chr;
    Monster mob[5];
    Mobskillstat skill[5];
    Consumption *ptr = (Consumption *)calloc(11, sizeof(Consumption));

    int map[24][24]={                                        //수호대 출발지
        {7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,6},   //(2,11) (21,11)  (11,2)  (11,21)
        {8,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,8},   //불의구역 (2,2)~(11,11)  -> Player.area=1
        {8,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,8},   //눈의구역 (2,12)~(11,21) -> Player.area=2
        {8,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,8},   //숲의구역 (12,2)~(21,11) -> Player.area=3
        {8,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,8},   //물의구역 (12,12)~(21,21) -> Player.area=4
        {8,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,8},
        {8,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,8},
        {8,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,8},
        {8,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,8},
        {8,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,8},
        {8,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,8},
        {8,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,8},
        {8,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,8},
        {8,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,8},
        {8,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,8},
        {8,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,8},
        {8,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,8},
        {8,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,8},
        {8,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,8},
        {8,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,8},
        {8,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,8},
        {8,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,8},
        {8,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,8},
        {7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,6}
    };

     int battlemap[24][24]={
        {1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,2},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},
        {3,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,4}
    };

    Equipment armor[62] = {{"빛바랜 천두건", "", "", "", "", "", "", 5, 0, 0},
                           {"견고한 천두건", "", "", "", "", "", "", 10, 0, 0},
                           {"빛바랜 가죽투구", "", "", "", "", "", "", 10, 0, 0},
                           {"견고한 가죽투구", "", "", "", "", "", "", 15, 0},
                           {"빛바랜 철투구", "", "", "", "", "", "", 15, 0, 0},
                           {"견고한 철투구", "", "", "", "", "", "", 20, 0, 0},
                           {"", "마모된 천갑옷", "", "", "", "", "", 5, 0, 0},
                           {"", "빛바랜 천갑옷", "", "", "", "", "", 10, 0, 0},
                           {"", "견고한 천갑옷", "", "", "", "", "", 15, 0, 0},
                           {"", "마모된 가죽갑옷", "", "", "", "", "", 5, 0, 0},
                           {"", "빛바랜 가죽갑옷", "", "", "", "", "", 10, 0, 0},
                           {"", "견고한 가죽갑옷", "", "", "", "", "", 15, 0, 0},
                           {"", "마모된 경갑갑옷", "", "", "", "", "", 10, 0, 0},
                           {"", "빛바랜 경갑갑옷", "", "", "", "", "", 15, 0, 0},
                           {"", "견고한 경갑갑옷", "", "", "", "", "", 20, 0, 0},
                           {"", "마모된 중갑갑옷", "", "", "", "", "", 15, 0, 0},
                           {"", "빛바랜 중갑갑옷", "", "", "", "", "", 20, 0, 0},
                           {"", "견고한 중갑갑옷", "", "", "", "", "", 25, 0, 0},
                           {"", "", "빛바랜 천바지", "", "", "", "", 5, 0, 0},
                           {"", "", "견고한 천바지", "", "", "", "", 10, 0, 0},
                           {"", "", "빛바랜 가죽바지", "", "", "", "", 10, 0, 0},
                           {"", "", "견고한 가죽바지", "", "", "", "", 15, 0, 0},
                           {"", "", "빛바랜 경갑바지", "", "", "", "", 15, 0, 0},
                           {"", "", "견고한 경갑바지", "", "", "", "", 20, 0, 0},
                           {"", "", "빛바랜 중갑바지", "", "", "", "", 20, 0, 0},
                           {"", "", "견고한 중갑바지", "", "", "", "", 25, 0, 0},
                           {"", "", "", "마모된 천망토", "", "", "", 5, 0, 0},
                           {"", "", "", "빛바랜 천망토", "", "", "", 10, 0, 0},
                           {"", "", "", "견고한 천망토", "", "", "", 15, 0, 0},
                           {"", "", "", "마모된 가죽망토", "", "", "", 10, 0, 0},
                           {"", "", "", "빛바랜 가죽망토", "", "", "", 15, 0, 0},
                           {"", "", "", "견고한 가죽망토", "", "", "", 20, 0, 0},
                           {"", "", "", "", "마모된 천장갑", "", "", 5, 0, 0},
                           {"", "", "", "", "빛바랜 천장갑", "", "", 10, 0, 0},
                           {"", "", "", "", "견고한 천장갑", "", "", 15, 0, 0},
                           {"", "", "", "", "마모된 가죽장갑", "", "", 10, 0, 0},
                           {"", "", "", "", "빛바랜 가죽장갑", "", "", 15, 0, 0},
                           {"", "", "", "", "견고한 가죽장갑", "", "", 20, 0, 0},
                           {"", "", "", "", "마모된 사슬장갑", "", "", 15, 0, 0},
                           {"", "", "", "", "빛바랜 사슬장갑", "", "", 20, 0, 0},
                           {"", "", "", "", "견고한 사슬장갑", "", "", 25, 0, 0},
                           {"", "", "", "", "", "가죽방패", "", 10, 0, 0},
                           {"", "", "", "", "", "사슬방패", "", 20, 0, 0},
                           {"", "", "", "", "", "철방패", "", 30, 0, 0},
                           {"", "", "", "", "", "", "마모된 한손검", 0, 10, 0},
                           {"", "", "", "", "", "", "빛바랜 한손검", 0, 20, 0},
                           {"", "", "", "", "", "", "견고한 한손검", 0, 30, 0},
                           {"", "", "", "", "", "", "마모된 양손검", 0, 10, 0},
                           {"", "", "", "", "", "", "빛바랜 양손검", 0, 20, 0},
                           {"", "", "", "", "", "", "견고한 양손검", 0, 30, 0},
                           {"", "", "", "", "", "", "마모된 장궁", 0, 10, 0},
                           {"", "", "", "", "", "", "빛바랜 장궁", 0, 20, 0},
                           {"", "", "", "", "", "", "견고한 장궁", 0, 30, 0},
                           {"", "", "", "", "", "", "마모된 숏스태프", 0, 10, 0},
                           {"", "", "", "", "", "", "빛바랜 숏스태프", 0, 20, 0},
                           {"", "", "", "", "", "", "견고한 숏스태프", 0, 30, 0},
                           {"", "", "", "", "", "", "마모된 롱스태프", 0, 10, 0},
                           {"", "", "", "", "", "", "빛바랜 롱스태프", 0, 20, 0},
                           {"", "", "", "", "", "", "견고한 롱스태프", 0, 30, 0},
                           {"", "", "", "", "", "", "마모된 룬스태프", 0, 10, 0},
                           {"", "", "", "", "", "", "빛바랜 룬스태프", 0, 20, 0},
                           {"", "", "", "", "", "", "견고한 룬스태프", 0, 30, 0}};

    srand((unsigned int)time(NULL));
    Init_Player(pchr);
    // *skill=Nmob(mob, 2, 2);
    // printf("%s %d\n", skill->skillname, skill->skillatk);
    Battle(pchr, ptr, battlemap, 1);
    return 0;
}