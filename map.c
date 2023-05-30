#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, num, type=3, here=0;
    int map[10][44]={0, };
    int x=22, y=6;      //춘식이 위치 좌표

    while(1)
    {
        system("clear");
        for(i=0; i<10; i++)
        {
            for(j=0; j<44; j++)
            {
                map[0][j]=1;                //0번줄 벽 생성
                if(i>=1&&i<=8)              //1번줄~9번줄까지 좌 우 벽 생성
                {
                    map[i][0]=1;
                    map[i][43]=1;
                }
                map[9][j]=1;                //0번줄 벽 생성

                switch(type)                //맵 타입에따른 입구 위치
                {
                    case 0:                 //디폴트. 좌상단맵에서 시작 우,하 입구
                    if(j>=21&&j<=24)        //하단 입구
                    map[9][j]=2;
                    if(j==43)               //우측 입구
                    {
                        map[4][j]=2;
                        map[5][j]=2;
                    }
                    break;

                    case 1:
                    if(j>=21&&j<=24)        //하단 입구
                    map[9][j]=2;
                    if(j==0)                //좌측 입구
                    {
                        map[4][j]=2;
                        map[5][j]=2;
                    }
                    break;

                    case 2:
                    if(j>=21&&j<=24)        //상단 입구
                    map[0][j]=2;
                    if(j==0)                //좌측 입구
                    {
                        map[4][j]=2;
                        map[5][j]=2;
                    }
                    break;

                    case 3:
                    if(j>=21&&j<=24)        //상단 입구
                    map[0][j]=2;
                    if(j==43)               //우측 입구
                    {
                        map[4][j]=2;
                        map[5][j]=2;
                    }
                    break;
                    
                    default:
                    printf("ERROR! MAP\n");
                    break;
                }

                if(i==y&&j==x||here>0)      //캐릭터 위치 출력
                {
                    if(here==0)
                    {
                        printf("😺");
                        here++;             //벽 밀리는 것 방지
                    }
                    else
                    here++;                 //캐릭터를 그린 다음 2칸은 공백을 그리지 않음. 춘식이 크기==" "2칸
                }

                if(here==0)
                {
                    if(map[i][j]==0)        //빈칸
                    printf(" ");
                    else if(map[i][j]==1)   //벽
                    printf("▒");
                    else if(map[i][j]==2)   //입구
                    printf(" ");
                    else
                    {
                        printf("ERROR\n");
                        break;
                    }
                }
                
                if(here>=2)                 //2칸을 아무것도 출력하지 않았으면 초기화
                here=0;
            }
            printf("\n");
        }
        break;  //테스트용
    }
}