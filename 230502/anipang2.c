#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <unistd.h> 리눅스로 옮길 때 주석 해제

int main(void)
{
    srand((unsigned int)time(NULL));
    int scr[10][10]; // 게임화면
    /*
    1~5 색깔블록
    6 아아템
    */
    int title; // 타이틀화면
    int a, b; // 좌표 입력
    char mv; // 교체할 방향 입력
    int mix; // 블록 섞기
    int temp;
    int i, j, k, l;

    while(1)
    {
        int score=0; // 점수 100점 달성 시 클리어

        printf("1.게임시작 2.종료 \n");
        scanf("%d", &title);

        if(title==1)
        {
        }else if(title==2){
            break;
        }else{
            continue;
        }

        while(1) // 3블록 연속인 블록 제거
        {
            int dup=0;

            for(i=0; i<10; i++)
            {
                for(j=0; j<10; j++)
                {
                    mix=(rand()%5)+1;

                    if(mix==1)
                    {
                        scr[i][j]=1;
                    }else if(mix==2){
                        scr[i][j]=2;
                    }else if(mix==3){
                        scr[i][j]=3;
                    }else if(mix==4){
                        scr[i][j]=4;
                    }else if(mix==5){
                        scr[i][j]=5;
                    }
                }
            }

            for(i=0; i<8; i++)
            {
                for(j=0; j<10; j++)
                {
                    if(scr[i][j]==scr[i+1][j] && scr[i+1][j]==scr[i+2][j])
                    {
                        dup=1;
                        break;
                    }
                }

                if(dup==1)
                {
                    break;
                }
            }

            if(dup==1)
            {
                continue;
            }

            for(i=0; i<10; i++)
            {
                for(j=0; j<8; j++)
                {
                    if(scr[i][j]==scr[i][j+1] && scr[i][j+1]==scr[i][j+2])
                    {
                        dup=2;
                        break;
                    }
                }

                if(dup==2)
                {
                    break;
                }
            }

            if(dup==2)
            {
                continue;
            }else{
                break;
            }
        }

        while(1)
        {
            int chg[10][10]={
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
            }; // 블록 교체 및 스코어링 하기 위한 배열

            int cvr=0; // 3연속 블록을 하나도 발견하지 못했을 때 되돌리기 위한 변수
            int chk=0; // 움직일 블록이 있는지 체크

            for(i=0; i<8; i++) // 움직일 블록이 있는지 체크(세로)
            {
                for(j=0; j<10; j++)
                {
                    if(j>=1 && j<=8)
                    {
                        if(scr[i][j]==scr[i+1][j] && scr[i][j]==scr[i+2][j+1])
                        {
                            chk=1;
                        }else if(scr[i][j]==scr[i+1][j] && scr[i][j]==scr[i+2][j-1]){
                            chk=1;
                        }else if(scr[i][j]==scr[i+1][j+1] && scr[i][j]==scr[i+2][j+1]){
                            chk=1;
                        }else if(scr[i][j]==scr[i+1][j-1] && scr[i][j]==scr[i+2][j-1]){
                            chk=1;
                        }else if(scr[i][j]==scr[i+1][j+1] && scr[i][j]==scr[i+2][j]){
                            chk=1;
                        }else if(scr[i][j]==scr[i+1][j-1] && scr[i][j]==scr[i+2][j]){
                            chk=1;
                        }
                    }else if(j==0){
                        if(scr[i][j]==scr[i+1][j] && scr[i][j]==scr[i+2][j+1])
                        {
                            chk=1;
                        }else if(scr[i][j]==scr[i+1][j+1] && scr[i][j]==scr[i+2][j+1]){
                            chk=1;
                        }else if(scr[i][j]==scr[i+1][j+1] && scr[i][j]==scr[i+2][j]){
                            chk=1;
                        }
                    }else if(j==9){
                        if(scr[i][j]==scr[i+1][j] && scr[i][j]==scr[i+2][j-1])
                        {
                            chk=1;
                        }else if(scr[i][j]==scr[i+1][j-1] && scr[i][j]==scr[i+2][j-1]){
                            chk=1;
                        }else if(scr[i][j]==scr[i+1][j-1] && scr[i][j]==scr[i+2][j]){
                            chk=1;
                        }
                    }
                }
            }

            for(i=0; i<10; i++) // 움직일 블록이 있는지 체크(가로)
            {
                for(j=0; j<8; j++)
                {
                    if(i>=1 && i<=8)
                    {
                        if(scr[i][j]==scr[i][j+1] && scr[i][j]==scr[i+1][j+2])
                        {
                            chk=1;
                        }else if(scr[i][j]==scr[i][j+1] && scr[i][j]==scr[i-1][j+2]){
                            chk=1;
                        }else if(scr[i][j]==scr[i+1][j+1] && scr[i][j]==scr[i+1][j+2]){
                            chk=1;
                        }else if(scr[i][j]==scr[i-1][j+1] && scr[i][j]==scr[i-1][j+2]){
                            chk=1;
                        }else if(scr[i][j]==scr[i+1][j+1] && scr[i][j]==scr[i][j+2]){
                            chk=1;
                        }else if(scr[i][j]==scr[i-1][j+1] && scr[i][j]==scr[i][j+2]){
                            chk=1;
                        }
                    }else if(i==0){
                        if(scr[i][j]==scr[i][j+1] && scr[i][j]==scr[i+1][j+2])
                        {
                            chk=1;
                        }else if(scr[i][j]==scr[i+1][j+1] && scr[i][j]==scr[i+1][j+2]){
                            chk=1;
                        }else if(scr[i][j]==scr[i+1][j+1] && scr[i][j]==scr[i][j+2]){
                            chk=1;
                        }
                    }else if(i==9){
                        if(scr[i][j]==scr[i][j+1] && scr[i][j]==scr[i-1][j+2])
                        {
                            chk=1;
                        }else if(scr[i][j]==scr[i-1][j+1] && scr[i][j]==scr[i-1][j+2]){
                            chk=1;
                        }else if(scr[i][j]==scr[i-1][j+1] && scr[i][j]==scr[i][j+2]){
                            chk=1;
                        }
                    }
                }
            }

            if(chk==0) // 움직일 블록이 없으면 반복문 탈출
            {
                printf("움직일 블록이 없습니다 \n");
                // sleep(1); 리눅스로 옮길 때 주석 해제
                break;
            }

            // system("clear"); 리눅스로 옮길 때 주석 해제

            printf("점수:%d \n", score);

            for(i=0; i<10; i++) // 게임화면 출력
            {
                for(j=0; j<10; j++)
                {
                    if(scr[i][j]==1)
                    {
                        printf("🟥");
                    }else if(scr[i][j]==2)
                    {
                        printf("🟨");
                    }else if(scr[i][j]==3)
                    {
                        printf("🟩");
                    }else if(scr[i][j]==4)
                    {
                        printf("🟦");
                    }else if(scr[i][j]==5)
                    {
                        printf("🟪");
                    }else if(scr[i][j]==6){
                        printf("🔳 ");
                    }
                }
                printf("\n");
            }
            
            printf("좌표 입력: "); // 0~9까지 입력
            scanf("%d %d", &a, &b);

            if(a<0 || a>9 || b<0 || b>9)
            {
                continue;
            }

            printf("이동 방향 입력: "); // 방향입력 wasd, 아이템 i
            scanf(" %c", &mv);

            if(mv=='w')
            {
                if(a<=0)
                {
                    continue;
                }
                temp=scr[a][b];
                scr[a][b]=scr[a-1][b];
                scr[a-1][b]=temp;
            }else if(mv=='s'){
                if(a>=9)
                {
                    continue;
                }
                temp=scr[a][b];
                scr[a][b]=scr[a+1][b];
                scr[a+1][b]=temp;
            }else if(mv=='a'){
                if(b<=0)
                {
                    continue;
                }
                temp=scr[a][b];
                scr[a][b]=scr[a][b-1];
                scr[a][b-1]=temp;
            }else if(mv=='d'){
                if(b>=9)
                {
                    continue;
                }
                temp=scr[a][b];
                scr[a][b]=scr[a][b+1];
                scr[a][b+1]=temp;
            }else if(mv=='i'){ // 폭탄 구현
                if(scr[a][b]==6)
                {
                    cvr=1;

                    if(a==0)
                    {
                        if(b==0)
                        {
                            chg[a][b]=1;
                            chg[a+1][b]=1;
                            chg[a][b+1]=1;
                            chg[a+1][b+1]=1;
                        }else if(b==9){
                            chg[a][b]=1;
                            chg[a+1][b]=1;
                            chg[a][b-1]=1;
                            chg[a+1][b-1]=1;
                        }else{
                            chg[a][b]=1;
                            chg[a+1][b]=1;
                            chg[a][b+1]=1;
                            chg[a][b-1]=1;
                            chg[a+1][b-1]=1;
                            chg[a+1][b+1]=1;
                        }
                    }else if(a==9){
                        if(b==0)
                        {
                            chg[a][b]=1;
                            chg[a-1][b]=1;
                            chg[a][b+1]=1;
                            chg[a-1][b+1]=1;
                        }else if(b==9){
                            chg[a][b]=1;
                            chg[a-1][b]=1;
                            chg[a][b-1]=1;
                            chg[a-1][b-1]=1;
                        }else{
                            chg[a][b]=1;
                            chg[a-1][b]=1;
                            chg[a][b+1]=1;
                            chg[a][b-1]=1;
                            chg[a-1][b-1]=1;
                            chg[a-1][b+1]=1;
                        }
                    }else if(b==0){
                        chg[a][b]=1;
                        chg[a-1][b]=1;
                        chg[a+1][b]=1;
                        chg[a][b+1]=1;
                        chg[a-1][b+1]=1;
                        chg[a+1][b+1]=1;
                    }else if(b==9){
                        chg[a][b]=1;
                        chg[a-1][b]=1;
                        chg[a+1][b]=1;
                        chg[a][b-1]=1;
                        chg[a-1][b-1]=1;
                        chg[a+1][b-1]=1;
                    }else{
                        chg[a][b]=1;
                        chg[a-1][b]=1;
                        chg[a+1][b]=1;
                        chg[a][b-1]=1;
                        chg[a][b+1]=1;
                        chg[a-1][b-1]=1;
                        chg[a-1][b+1]=1;
                        chg[a+1][b-1]=1;
                        chg[a+1][b+1]=1;
                    }
                }else{
                    continue;
                }
            }else{
                continue;
            }

            for(i=0; i<8; i++) // 세로 검사
            {
                for(j=0; j<10; j++)
                {
                    if(scr[i][j]==scr[i+1][j] && scr[i][j]==scr[i+2][j])
                    {
                        cvr=1;

                        chg[i][j]=1;
                        chg[i+1][j]=1;
                        chg[i+2][j]=1;
                    }
                }
            }

            for(i=0; i<10; i++) // 가로 검사
            {
                for(j=0; j<8; j++)
                {
                    if(scr[i][j]==scr[i][j+1] && scr[i][j]==scr[i][j+2])
                    {
                        cvr=1;

                        chg[i][j]=1;
                        chg[i][j+1]=1;
                        chg[i][j+2]=1;
                    }
                }
            }

            if(cvr==0) // 3연속 블록을 발견하지 못하면 다시 원위치 시켜주고 돌아감
            {
                if(mv=='w')
                {
                    temp=scr[a][b];
                    scr[a][b]=scr[a-1][b];
                    scr[a-1][b]=temp;
                }else if(mv=='s'){
                    temp=scr[a][b];
                    scr[a][b]=scr[a+1][b];
                    scr[a+1][b]=temp;
                }else if(mv=='a'){
                    temp=scr[a][b];
                    scr[a][b]=scr[a][b-1];
                    scr[a][b-1]=temp;
                }else if(mv=='d'){
                    temp=scr[a][b];
                    scr[a][b]=scr[a][b+1];
                    scr[a][b+1]=temp;
                }
                continue;
            }

            for(i=0; i<10; i++) // 스코어링
            {
                for(j=0; j<10; j++)
                {
                    if(chg[i][j]==1)
                    {
                        score++;
                    }
                }
            }

            while(1) // 빈자리 채우기
            {
                int dup0=0;

                for(i=0; i<10; i++)
                {
                    for(j=0; j<10; j++)
                    {
                        if(chg[i][j]==1)
                        {
                            mix=(rand()%20)+1;
                            
                            if(mix==1) // 5프로 확률로 아이템 등장
                            {
                                scr[i][j]=6;
                            }else{
                                mix=(rand()%5)+1;

                                if(mix==1)
                                {
                                    scr[i][j]=1;
                                }else if(mix==2){
                                    scr[i][j]=2;
                                }else if(mix==3){
                                    scr[i][j]=3;
                                }else if(mix==4){
                                    scr[i][j]=4;
                                }else if(mix==5){
                                    scr[i][j]=5;
                                }
                            }
                        }
                    }
                }

                for(i=0; i<8; i++) // 채워진 블록으로 인해 3연속 블록이 됐다면 돌아가서 다시 채워줌
                {
                    for(j=0; j<10; j++)
                    {
                        if(scr[i][j]==scr[i+1][j] && scr[i+1][j]==scr[i+2][j])
                        {
                            dup0=1;
                            break;
                        }
                    }

                    if(dup0==1)
                    {
                        break;
                    }
                }

                if(dup0==1)
                {
                    continue;
                }

                for(i=0; i<10; i++)
                {
                    for(j=0; j<8; j++)
                    {
                        if(scr[i][j]==scr[i][j+1] && scr[i][j+1]==scr[i][j+2])
                        {
                            dup0=2;
                            break;
                        }
                    }

                    if(dup0==2)
                    {
                        break;
                    }
                }

                if(dup0==2)
                {
                    continue;
                }else{
                    break;
                }
            }

            if(score>=100)
            {
                printf("Clear! \n");
                break;
            }
        }

        if(score>=100)
        {
            break;
        }
    }
    return 0;
}