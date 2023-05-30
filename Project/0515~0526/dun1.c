#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <time.h>

void meetm(void); // 여기함수에다가 몬스터 조우 넣을 예정
void meetb(void); // 여기함수에다가 보스 조우 넣을 예정
void dunp(void);
void dun1(int r, int **ptr);
int getch();

int main(void)
{
    dunp();
    return 0;
}

int getch()
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

void dun1(int r, int **ptr) // 15 ~ 18랜덤 배열 던전
{
    int i, j, x1, y1, b = 3, x, y, x2, y2;
    char in;
    int meet;
    int key;
    int map[r][r];
    int l = r - 2;

    srand((int)time(NULL));
    x = rand() % l + 1; // 배열에 맞는 랜덤 출현
    y = rand() % l + 1;
    x1 = rand() % l + 1;
    y1 = rand() % l + 1;
    x2 = rand() % l + 1;
    y2 = rand() % l + 1;

    for (i = 0; i < r; i++) // 움직일공간
    {
        for (j = 0; j < r; j++)
        {
            map[i][j] = 0;
        }
    }
    for (i = 0; i < r; i++) // 벽
    {
        map[0][i] = 1;
        map[i][0] = 1;
        map[r - 1][i] = 1;
        map[i][r - 1] = 1;
    }

    map[x][y] = 2;       // 플레이어 출력
    map[x1][y1] = **ptr; // 보스 출력
    map[x2][y2] = 8;     // 다음 입구 출현

    while (1)
    {
        system("clear");

        meet = rand() % 20;

        meet = rand() % 20;     // 몬스터와 만날확률
        for (i = 0; i < r; i++) // 사용자위치 찾기
        {
            for (j = 0; j < r; j++)
            {
                if (map[i][j] == 2)
                {
                    x = i;
                    y = j;
                }
            }
        }
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < r; j++)
            {
                if (map[i][j] == 1)
                {
                    printf("\x1b[41m");
                    printf("   ");
                    printf("\x1b[0m");
                }
                if (map[i][j] == 0)
                {
                    printf("   ");
                }
                if (map[i][j] == 3)
                {
                    printf(" 🐗");
                }
                if (map[i][j] == 4)
                {
                    printf(" 🦍");
                }
                if (map[i][j] == 5)
                {
                    printf(" 🐺");
                }
                if (map[i][j] == 6)
                {
                    printf(" 🦈");
                }
                if (map[i][j] == 7)
                {
                    printf(" 🐉");
                }
                if (map[i][j] == 8)
                {
                    printf(" 🪜 ");
                }
                if (map[i][j] == 2)
                {
                    printf(" 🛡 ");
                }
            }
            printf("\n");
        }
        key = getch(); // 보스방 진행방향 반대로 눌르거나 90도로 눌러야 탈출가능 진행방향 계속 누르면 탈출이 안됌

        if (meet == 0) // 몬스터 만날확률
        {
            meetm();
        }

        if (key == 'a') // a는 왼쪽방향
        {
            if (map[x][y - 1] != 1)
            {
                map[x][y] = 0;
                map[x][y - 1] = 2;
                if (map[x][y - 1] == map[x1][y1]) // 보스와 조우
                {
                    meetb();
                    map[x1][y1] = 0;
                    x1 = -2;
                    y1 = -2;
                }
                if (map[x][y - 1] == map[x2][y2])
                {
                    if (x1 == -2)
                    {
                        break;
                    }
                    else
                    {
                        map[x2][y2] = 8;
                    }
                }
            }
        }
        else if (key == 's') // s는 아래방향
        {
            if (map[x + 1][y] != 1)
            {

                map[x][y] = 0;
                map[x + 1][y] = 2;
                if (map[x + 1][y] == map[x1][y1]) // 보스와 조우
                {
                    meetb();
                    map[x1][y1] = 0;
                    x1 = -2;
                    y1 = -2;
                }
                if (map[x + 1][y] == map[x2][y2])
                {
                    if (x1 == -2)
                    {
                        break;
                    }
                    else
                    {
                        map[x2][y2] = 8;
                    }
                }
            }
        }
        else if (key == 'd') // d는 오른쪽방향
        {
            if (map[x][y + 1] != 1)
            {

                map[x][y] = 0;
                map[x][y + 1] = 2;
                if (map[x][y + 1] == map[x1][y1]) // 보스와 조우
                {
                    meetb();
                    map[x1][y1] = 0;
                    x1 = -2;
                    y1 = -2;
                }
                if (map[x][y + 1] == map[x2][y2])
                {
                    if (x1 == -2)
                    {
                        break;
                    }
                    else
                    {
                        map[x2][y2] = 8;
                    }
                }
            }
        }
        else if (key == 'w') // w는 위쪽방향
        {
            if (map[x - 1][y] != 1)
            {

                map[x][y] = 0;
                map[x - 1][y] = 2;
                if (map[x - 1][y] == map[x1][y1]) // 보스와 조우
                {
                    meetb();
                    map[x1][y1] = 0;
                    x1 = -2;
                    y1 = -2;
                }
                if (map[x - 1][y] == map[x2][y2])
                {
                    if (x1 == -2)
                    {
                        break;
                    }
                    else
                    {
                        map[x2][y2] = 8;
                    }
                }
            }
        }
    }
}

void meetm(void)
{
    int s;
    printf("여기는 일반 몬스터");
    scanf("%d", &s);
}

void dunp(void)
{
    int r, i;
    int *ptr;
    int *ptr1;
    int mon = 3;
    int boss = 0;
    ptr = &mon;
    // ptr1 = &boss;
    srand((int)time(NULL));
    for (i = 0; i < 5; i++)
    {
        r = rand() % 4 + 15;
        dun1(r, &ptr);
        mon++;
    }
}

void meetb(void)
{
    int a;
    printf("여기는 보스다:");
    scanf("%d", &a);
}