#include <stdio.h> // 팔방으로 찾기추가 버전
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int MiniGame1(int victory, int *ad) // 지뢰 찾기
{
    int map[11][11] = {0};
    int boom = 0;       // 근처 지뢰 탐색용 근처 지뢰 몇개 인지
    int x, y;           // x,y 좌표 반복문
    int i, j, r=1;        // 반복문 돌리는 그냥 변수
    int life = 1;       // 목숨 1 시작
    int item = 2;       // 숨겨진 아이템 개수
    int btn;            // 선택용 변수
    int vp = 0;         // 밝혀지지 않은 부분 파악을 위한 변수, 클리어를 위한 변수
    int count = 0;      // 임시 숫자 파악용
    int heart[3] = {7}; // 목숨 표시용

    srand((unsigned int)time(NULL)); // 난수
    for (i = 0; i < 10; i++)         // 배열 맵에 지뢰 생성!
    {
        system("clear");
        x = (rand() % 10) + 1; // 1~10
        y = (rand() % 10) + 1; // 1~10
        if (map[x][y] == 9)    // x,y 자리에 지뢰가 배치 되었다면 다시 반복!
        {
            i--;      // 증가된 i값 을 낮춰 중복 제외 10회 돌게 만듬
            continue; // 아래 내용 무시 반복
        }
        map[x][y] = 9; // 지뢰 표시
    }
    for (x = 1; x < 11; x++) // (0,0)라인 제외 배열 탐색 후 각 좌표에 지뢰가 근처에 몇개가 있는지 표시
    {
        for (y = 1; y < 11; y++)
        {
            if (map[x][y] != 9) // 지뢰가 아니면 근처에 탐색 하러
            {
                boom = 0;
                if ((x == 1) && (y == 1)) // <1-1> 왼쪽위 꼭지점 4번 탐색
                {
                    for (i = 0; i < 2; i++)
                    {
                        for (j = 0; j < 2; j++)
                        {
                            if (map[x + i][y + j] == 9)
                            {
                                boom++;
                            }
                        }
                    }
                }
                else if ((x == 10) && (y == 1)) // <1-2> 왼쪽아래 꼭지점 4번 탐색
                {
                    for (i = 0; i < 2; i++)
                    {
                        for (j = 0; j < 2; j++)
                        {
                            if (map[(x - 1) + i][y + j] == 9)
                            {
                                boom++;
                            }
                        }
                    }
                }
                else if ((x == 1) && (y == 10)) // <1-3> 오른쪽위 꼭지점 4번 탐색
                {
                    for (i = 0; i < 2; i++)
                    {
                        for (j = 0; j < 2; j++)
                        {
                            if (map[x + i][(y - 1) + j] == 9)
                            {
                                boom++;
                            }
                        }
                    }
                }
                else if ((x == 10) && (y == 10)) // <1-4> 오른쪽아래 꼭지점 4번 탐색
                {
                    for (i = 0; i < 2; i++)
                    {
                        for (j = 0; j < 2; j++)
                        {
                            if (map[(x - 1) + i][(y - 1) + j] == 9)
                            {
                                boom++;
                            }
                        }
                    }
                }
                else if ((1 < x < 10) && (y == 1)) // <2-1> 왼쪽 끝에 사이 6번 탐색
                {
                    for (i = 0; i < 3; i++)
                    {
                        for (j = 0; j < 2; j++)
                        {
                            if (map[(x - 1) + i][y + j] == 9)
                            {
                                boom++;
                            }
                        }
                    }
                }
                else if ((1 < x < 10) && (y == 10)) // <2-2> 오른쪽 끝에 사이 6번 탐색
                {
                    for (i = 0; i < 3; i++)
                    {
                        for (j = 0; j < 2; j++)
                        {
                            if (map[(x - 1) + i][(y - 1) + j] == 9)
                            {
                                boom++;
                            }
                        }
                    }
                }
                else if ((x == 1) && (1 < y < 10)) // <2-3> 위쪽 끝에 사이 6번 탐색
                {
                    for (i = 0; i < 2; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            if (map[x + i][(y - 1) + j] == 9)
                            {
                                boom++;
                            }
                        }
                    }
                }
                else if ((x == 10) && (1 < y < 10)) // <2-4> 아래쪽 끝에 사이 6번 탐색
                {
                    for (i = 0; i < 2; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            if (map[(x - 1) + i][(y - 1) + j] == 9)
                            {
                                boom++;
                            }
                        }
                    }
                }
                else if ((1 < x < 10) && (1 < y < 10)) // <3-1> 나머지 9번 탐색
                {
                    for (i = 0; i < 3; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            if (map[(x - 1) + i][(y - 1) + j] == 9)
                            {
                                boom++;
                            }
                        }
                    }
                }
                map[x][y] = boom;
            }
        }
    }
    for (i = 0; i < 2; i++) // 배열 맵에 목숨 아이템 생성!
    {
        system("clear");
        x = (rand() % 10) + 1; // 1~10
        y = (rand() % 10) + 1; // 1~10
        if (map[x][y] == 9)    // x,y 자리에 지뢰가 배치 되었다면 다시 반복!
        {
            i--;      // 증가된 i값 을 낮춰 중복 제외 10회 돌게 만듬
            continue; // 아래 내용 무시 반복
        }
        map[x][y] = 37; // 목숨 아이템 표시
    }
    while (r) // 본격 게임 화면
    {
        system("clear");
        for (i = 0; i < 11; i++)
        {
            for (j = 0; j < 11; j++)
            {
                if (i == 0 && j == 0)
                {
                    map[0][0] = 99;
                    printf(" 😺 "); // 춘식이
                }
                else if (i == 0)
                {
                    map[0][j] = j;
                    printf(" %2d", j);
                }
                else if (j == 0)
                {
                    map[i][0] = i;
                    printf(" %2d ", i);
                }
                // 그냥 풀, 지뢰, 지뢰 근처
                else if (map[i][j] == 9 || map[i][j] == 0 || map[i][j] == 1 || map[i][j] == 2 || map[i][j] == 3 || map[i][j] == 4 || map[i][j] == 5 || map[i][j] == 6 || map[i][j] == 7 || map[i][j] == 8 || map[i][j] == 37)
                {
                    printf(" ● "); // 풀숲
                }
                else if (map[i][j] == 10)
                {
                    printf(" ○ "); // 아무것도 없음
                }
                else if (map[i][j] == 11)
                {
                    printf(" ① "); // 근처에 지뢰가?! 1개가 있다!
                }
                else if (map[i][j] == 12)
                {
                    printf(" ② "); // 근처에 지뢰가?! 2개가 있다!
                }
                else if (map[i][j] == 13)
                {
                    printf(" ③ "); // 근처에 지뢰가?! 3개가 있다!
                }
                else if (map[i][j] == 14)
                {
                    printf(" ④ "); // 근처에 지뢰가?! 4개가 있다!
                }
                else if (map[i][j] == 15)
                {
                    printf(" ⑤ "); // 근처에 지뢰가?! 5개가 있다!
                }
                else if (map[i][j] == 16)
                {
                    printf(" ⑥ "); // 근처에 지뢰가?! 6개가 있다!
                }
                else if (map[i][j] == 17)
                {
                    printf(" ⑦ "); // 근처에 지뢰가?! 7개가 있다!
                }
                else if (map[i][j] == 18)
                {
                    printf(" ⑧ "); // 근처에 지뢰가?! 8개가 있다!
                }
                else if (map[i][j] == 20 || map[i][j] == 21 || map[i][j] == 22 || map[i][j] == 23 || map[i][j] == 24 || map[i][j] == 25 || map[i][j] == 26 || map[i][j] == 27 || map[i][j] == 28 || map[i][j] == 29 || map[i][j] == 47)
                {
                    printf(" ❗"); // 지뢰가 있을 것 같다!
                }
                else if (map[i][j] == 19)
                {
                    printf(" 💣"); // 지뢰 발견!
                }
                else if (map[i][j] == 77)
                {
                    printf(" ❤️ "); // 아이템 발견!
                }
            }
            printf("\n");
        }
        printf("\n");
        if (r == 1) // 클리어 조건 출력 1턴만
        {
            printf(" @클리어 조건@ \n");
            printf("  아이템을 모두 먹고 \n");
            printf("  지뢰지역을 표시한다음 \n");
            printf("  맵을 모두 밝혀라! \n");
            printf("\n");
            r++;
        }
        for (i = 0; i < 11; i++) // 값 바뀌는 확인용 나중에 없애야됨
        {
            for (j = 0; j < 11; j++)
            {
                printf(" %2d", map[i][j]);
            }
            printf("\n");
        }
        if (vp == 100)
        {
            printf("   클리어!!! \n");
            victory++;
            *ad++;
            usleep(1000000);
            break;
        }
        else if (vp < 100)
        {
            for (i = 1; i <= 10; i++)
            {
                for (j = 1; j <= 10; j++)
                {
                    if (map[i][j] == 29 || map[i][j] == 10 || map[i][j] == 11 || map[i][j] == 12 || map[i][j] == 13 || map[i][j] == 14 || map[i][j] == 15 || map[i][j] == 16 || map[i][j] == 17 || map[i][j] == 18 || map[i][j] == 77)
                    {
                        vp++;
                        if (vp == 100)
                        {
                            printf("춘식이가 모든 맵을 밝혔다! \n");
                        }
                    }
                }
            }
        }
        if (life > 0)
        {
            printf("목숨 > ");
            for (i = 0; i < 3; i++)
            {
                if (heart[i] == 7)
                    printf(" ❤️ ");
            }
            printf("\n");
            printf("숨겨진 아이템 개수 > %d개 \n", item);
            printf("1. 탐색할 위치 지정, 2. 지뢰지역 표시하기 \n");
            printf("선택 > ");
            scanf("%d", &btn);
            getchar();
            if (btn == 1)
            {
                printf("춘식이가 탐색할 곳 좌표(왼쪽,위 번호 순서로) \n");
                printf("입력 > ");
                scanf("%d %d", &x, &y);
                getchar();
                if (map[x][y] == 10 || map[x][y] == 11 || map[x][y] == 12 || map[x][y] == 13 || map[x][y] == 14 || map[x][y] == 15 || map[x][y] == 16 || map[x][y] == 17 || map[x][y] == 18 || map[x][y] == 77)
                {
                    printf("이미 탐색한 곳입니다. 다시! \n");
                    usleep(1000000);
                    continue;
                }
                else if (map[x][y] == 9)
                {
                    printf("춘식이가 지뢰를 밟아서 터져버렸다! \n");
                    sleep(1);
                    map[x][y] = 19;
                    if (life > 0)
                    {
                        for (i = 2; i >= 0; i--)
                        {
                            if (heart[i] == 7)
                            {
                                heart[i] = 0;
                                break;
                            }
                        }
                    }
                    life--;
                    if (life == 0)
                    {
                        printf("춘식이의 목숨이 모두 사라졌다... \n");
                    }
                }
                else if (map[x][y] == 37)
                {
                    printf("춘식이가 아이템을 발견했다! \n");
                    sleep(1);
                    map[x][y] = 77;
                    for (i = 0; i < 3; i++)
                    {
                        if (heart[i] == 0)
                        {
                            heart[i] = 7;
                            break;
                        }
                    }
                    life++;
                    item--;
                }
                else if ((1 <= x <= 10) || (1 <= y <= 10)) // 탐색
                {
                    if ((x == 1) && (y == 1)) // <1-1> 왼쪽위 꼭지점 4번 탐색
                    {
                        for (i = 0; i < 2; i++)
                        {
                            for (j = 0; j < 2; j++)
                            {
                                if (map[x + i][y + j] == 0)
                                {
                                    map[x + i][y + j] = 10;
                                }
                                else if (map[x + i][y + j] == 1)
                                {
                                    map[x + i][y + j] = 11;
                                }
                                else if (map[x + i][y + j] == 2)
                                {
                                    map[x + i][y + j] = 12;
                                }
                                else if (map[x + i][y + j] == 3)
                                {
                                    map[x + i][y + j] = 13;
                                }
                                else if (map[x + i][y + j] == 4)
                                {
                                    map[x + i][y + j] = 14;
                                }
                                else if (map[x + i][y + j] == 5)
                                {
                                    map[x + i][y + j] = 15;
                                }
                                else if (map[x + i][y + j] == 6)
                                {
                                    map[x + i][y + j] = 16;
                                }
                                else if (map[x + i][y + j] == 7)
                                {
                                    map[x + i][y + j] = 17;
                                }
                                else if (map[x + i][y + j] == 8)
                                {
                                    map[x + i][y + j] = 18;
                                }
                            }
                        }
                    }
                    else if ((x == 10) && (y == 1)) // <1-2> 왼쪽아래 꼭지점 4번 탐색
                    {
                        for (i = 0; i < 2; i++)
                        {
                            for (j = 0; j < 2; j++)
                            {
                                if (map[(x - 1) + i][y + j] == 0)
                                {
                                    map[(x - 1) + i][y + j] = 10;
                                }
                                else if (map[(x - 1) + i][y + j] == 1)
                                {
                                    map[(x - 1) + i][y + j] = 11;
                                }
                                else if (map[(x - 1) + i][y + j] == 2)
                                {
                                    map[(x - 1) + i][y + j] = 12;
                                }
                                else if (map[(x - 1) + i][y + j] == 3)
                                {
                                    map[(x - 1) + i][y + j] = 13;
                                }
                                else if (map[(x - 1) + i][y + j] == 4)
                                {
                                    map[(x - 1) + i][y + j] = 14;
                                }
                                else if (map[(x - 1) + i][y + j] == 5)
                                {
                                    map[(x - 1) + i][y + j] = 15;
                                }
                                else if (map[(x - 1) + i][y + j] == 6)
                                {
                                    map[(x - 1) + i][y + j] = 16;
                                }
                                else if (map[(x - 1) + i][y + j] == 7)
                                {
                                    map[(x - 1) + i][y + j] = 17;
                                }
                                else if (map[(x - 1) + i][y + j] == 8)
                                {
                                    map[(x - 1) + i][y + j] = 18;
                                }
                            }
                        }
                    }
                    else if ((x == 1) && (y == 10)) // <1-3> 오른쪽위 꼭지점 4번 탐색
                    {
                        for (i = 0; i < 2; i++)
                        {
                            for (j = 0; j < 2; j++)
                            {
                                if (map[x + i][(y - 1) + j] == 0)
                                {
                                    map[x + i][(y - 1) + j] = 10;
                                }
                                else if (map[x + i][(y - 1) + j] == 1)
                                {
                                    map[x + i][(y - 1) + j] = 11;
                                }
                                else if (map[x + i][(y - 1) + j] == 2)
                                {
                                    map[x + i][(y - 1) + j] = 12;
                                }
                                else if (map[x + i][(y - 1) + j] == 3)
                                {
                                    map[x + i][(y - 1) + j] = 13;
                                }
                                else if (map[x + i][(y - 1) + j] == 4)
                                {
                                    map[x + i][(y - 1) + j] = 14;
                                }
                                else if (map[x + i][(y - 1) + j] == 5)
                                {
                                    map[x + i][(y - 1) + j] = 15;
                                }
                                else if (map[x + i][(y - 1) + j] == 6)
                                {
                                    map[x + i][(y - 1) + j] = 16;
                                }
                                else if (map[x + i][(y - 1) + j] == 7)
                                {
                                    map[x + i][(y - 1) + j] = 17;
                                }
                                else if (map[x + i][(y - 1) + j] == 8)
                                {
                                    map[x + i][(y - 1) + j] = 18;
                                }
                            }
                        }
                    }
                    else if ((x == 10) && (y == 10)) // <1-4> 오른쪽아래 꼭지점 4번 탐색
                    {
                        for (i = 0; i < 2; i++)
                        {
                            for (j = 0; j < 2; j++)
                            {
                                if (map[(x - 1) + i][(y - 1) + j] == 0)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 10;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 1)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 11;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 2)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 12;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 3)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 13;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 4)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 14;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 5)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 15;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 6)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 16;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 7)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 17;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 8)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 18;
                                }
                            }
                        }
                    }
                    else if ((1 < x < 10) && (y == 1)) // <2-1> 왼쪽 끝에 사이 6번 탐색
                    {
                        for (i = 0; i < 3; i++)
                        {
                            for (j = 0; j < 2; j++)
                            {
                                if (map[(x - 1) + i][y + j] == 0)
                                {
                                    map[(x - 1) + i][y + j] = 10;
                                }
                                else if (map[(x - 1) + i][y + j] == 1)
                                {
                                    map[(x - 1) + i][y + j] = 11;
                                }
                                else if (map[(x - 1) + i][y + j] == 2)
                                {
                                    map[(x - 1) + i][y + j] = 12;
                                }
                                else if (map[(x - 1) + i][y + j] == 3)
                                {
                                    map[(x - 1) + i][y + j] = 13;
                                }
                                else if (map[(x - 1) + i][y + j] == 4)
                                {
                                    map[(x - 1) + i][y + j] = 14;
                                }
                                else if (map[(x - 1) + i][y + j] == 5)
                                {
                                    map[(x - 1) + i][y + j] = 15;
                                }
                                else if (map[(x - 1) + i][y + j] == 6)
                                {
                                    map[(x - 1) + i][y + j] = 16;
                                }
                                else if (map[(x - 1) + i][y + j] == 7)
                                {
                                    map[(x - 1) + i][y + j] = 17;
                                }
                                else if (map[(x - 1) + i][y + j] == 8)
                                {
                                    map[(x - 1) + i][y + j] = 18;
                                }
                            }
                        }
                    }
                    else if ((1 < x < 10) && (y == 10)) // <2-2> 오른쪽 끝에 사이 6번 탐색
                    {
                        for (i = 0; i < 3; i++)
                        {
                            for (j = 0; j < 2; j++)
                            {
                                if (map[(x - 1) + i][(y - 1) + j] == 0)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 10;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 1)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 11;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 2)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 12;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 3)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 13;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 4)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 14;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 5)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 15;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 6)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 16;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 7)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 17;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 8)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 18;
                                }
                            }
                        }
                    }
                    else if ((x == 1) && (1 < y < 10)) // <2-3> 위쪽 끝에 사이 6번 탐색
                    {
                        for (i = 0; i < 2; i++)
                        {
                            for (j = 0; j < 3; j++)
                            {
                                if (map[x + i][(y - 1) + j] == 0)
                                {
                                    map[x + i][(y - 1) + j] = 10;
                                }
                                else if (map[x + i][(y - 1) + j] == 1)
                                {
                                    map[x + i][(y - 1) + j] = 11;
                                }
                                else if (map[x + i][(y - 1) + j] == 2)
                                {
                                    map[x + i][(y - 1) + j] = 12;
                                }
                                else if (map[x + i][(y - 1) + j] == 3)
                                {
                                    map[x + i][(y - 1) + j] = 13;
                                }
                                else if (map[x + i][(y - 1) + j] == 4)
                                {
                                    map[x + i][(y - 1) + j] = 14;
                                }
                                else if (map[x + i][(y - 1) + j] == 5)
                                {
                                    map[x + i][(y - 1) + j] = 15;
                                }
                                else if (map[x + i][(y - 1) + j] == 6)
                                {
                                    map[x + i][(y - 1) + j] = 16;
                                }
                                else if (map[x + i][(y - 1) + j] == 7)
                                {
                                    map[x + i][(y - 1) + j] = 17;
                                }
                                else if (map[x + i][(y - 1) + j] == 8)
                                {
                                    map[x + i][(y - 1) + j] = 18;
                                }
                            }
                        }
                    }
                    else if ((x == 10) && (1 < y < 10)) // <2-4> 아래쪽 끝에 사이 6번 탐색
                    {
                        for (i = 0; i < 2; i++)
                        {
                            for (j = 0; j < 3; j++)
                            {
                                if (map[(x - 1) + i][(y - 1) + j] == 0)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 10;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 1)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 11;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 2)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 12;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 3)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 13;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 4)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 14;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 5)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 15;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 6)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 16;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 7)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 17;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 8)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 18;
                                }
                            }
                        }
                    }
                    else if ((1 < x < 10) && (1 < y < 10)) // <3-1> 나머지 9번 탐색
                    {
                        for (i = 0; i < 3; i++)
                        {
                            for (j = 0; j < 3; j++)
                            {
                                if (map[(x - 1) + i][(y - 1) + j] == 0)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 10;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 1)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 11;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 2)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 12;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 3)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 13;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 4)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 14;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 5)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 15;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 6)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 16;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 7)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 17;
                                }
                                else if (map[(x - 1) + i][(y - 1) + j] == 8)
                                {
                                    map[(x - 1) + i][(y - 1) + j] = 18;
                                }
                            }
                        }
                    }
                }
                else
                {
                    printf("잘못 입력 하셨습니다. 처음으로! \n");
                    usleep(1000000);
                    continue;
                }
            }
            else if (btn == 2)
            {
                printf("(이미 표시 한곳 다시 입력하면 원래대로 돌아감) \n");
                printf("지뢰가 있을 곳을 표시 하기 위한 좌표 입력 > ");
                scanf("%d %d", &x, &y);
                if (map[x][y] == 0)
                {
                    map[x][y] = 20;
                }
                else if (map[x][y] == 1)
                {
                    map[x][y] = 21;
                }
                else if (map[x][y] == 2)
                {
                    map[x][y] = 22;
                }
                else if (map[x][y] == 3)
                {
                    map[x][y] = 23;
                }
                else if (map[x][y] == 4)
                {
                    map[x][y] = 24;
                }
                else if (map[x][y] == 5)
                {
                    map[x][y] = 25;
                }
                else if (map[x][y] == 6)
                {
                    map[x][y] = 26;
                }
                else if (map[x][y] == 7)
                {
                    map[x][y] = 27;
                }
                else if (map[x][y] == 8)
                {
                    map[x][y] = 28;
                }
                else if (map[x][y] == 9)
                {
                    map[x][y] = 29;
                }
                else if (map[x][y] == 37)
                {
                    map[x][y] = 47;
                }
                else if (map[x][y] == 20)
                {
                    map[x][y] = 0;
                }
                else if (map[x][y] == 21)
                {
                    map[x][y] = 1;
                }
                else if (map[x][y] == 22)
                {
                    map[x][y] = 2;
                }
                else if (map[x][y] == 23)
                {
                    map[x][y] = 3;
                }
                else if (map[x][y] == 24)
                {
                    map[x][y] = 4;
                }
                else if (map[x][y] == 25)
                {
                    map[x][y] = 5;
                }
                else if (map[x][y] == 26)
                {
                    map[x][y] = 6;
                }
                else if (map[x][y] == 27)
                {
                    map[x][y] = 7;
                }
                else if (map[x][y] == 28)
                {
                    map[x][y] = 8;
                }
                else if (map[x][y] == 29)
                {
                    map[x][y] = 9;
                }
                else if (map[x][y] == 47)
                {
                    map[x][y] = 37;
                }
                else
                {
                    printf("잘못 입력 하셨습니다. 처음으로! \n");
                    usleep(1000000);
                    continue;
                }
            }
            else
            {
                printf("잘못 입력 하셨습니다. 처음으로! \n");
                usleep(1000000);
                continue;
            }
        }
        else
        {
            printf("   게임 오버! \n");
            *ad++;
            printf("\n");
            usleep(1000000);
            break;
        }
        usleep(1000000);
    }
    return victory;
}

int main(void)
{
    int adventure = 0;
    int victory = 0;

    MiniGame1(victory, &adventure);
    return 0;
}
