#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char class_name[20];    //클래스 이름
    int class;              //클래스 종류
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
    int weapon[1];          //0.왼손 1.오른손
    int armor[4];           //0.상의 1.하의 2.머리 3.망토 4.장갑
    int state;              //상태(전투 불능)
    int area;               //현재 있는 구역 1.불 2.눈 3.숲 4.물
} Player;

typedef struct
{
    char class_name[20];    //클래스 이름
    int class;              //클래스 종류
    int hp;                 //체력
    int atk;                //공격력
    int def;                //방어력
    int exp;                //잡았을때 주는 경험치
    int state;              //상태(전투 불능)
} Guardian;

typedef struct
{
    char name[20];      //몬스터 이름
    char skill[20];     //몬스터 스킬 이름
    int hp;             //체력
    int atk;            //공격력
    int def;            //방어력
    int exp;            //잡았을때 주는 경험치
    int state;          //상태(전투 불능)
} Monster;

int main(void)
{
    return 0;
}