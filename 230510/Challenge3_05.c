#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)  //가위바위보 게임, 사용자가 질때까지 반복, 마지막에는 게임의 결과 출력
{
    int win=0, tie=0, lose=0, random, user;
    const char *str[4]={"", "바위", "가위", "보"};
    srand((unsigned int)time(NULL));

    while(lose==0)
    {
        printf("바위는 1, 가위는 2, 보는 3\n입력: ");
        scanf("%d", &user);
        random=rand()%3+1;
        if(user==random)
        {
            printf("당신은 %s선택, 컴퓨터는 %s선택, 비겼습니다!\n", str[user], str[random]);
            tie++;
        }
        switch(user)
        {
            case 1:
            switch(random)
            {
                case 2:
                printf("당신은 %s 선택, 컴퓨터는 %s 선택, 이겼습니다!\n", str[user], str[random]);
                win++;
                break;
                case 3:
                printf("당신은 %s 선택, 컴퓨터는 %s 선택, 졌습니다!\n", str[user], str[random]);
                lose++;
                break;
                default:
                break;
            }
            break;
            case 2:
            switch(random)
            {
                case 1:
                printf("당신은 %s 선택, 컴퓨터는 %s 선택, 졌습니다!\n", str[user], str[random]);
                lose++;
                break;
                case 3:
                printf("당신은 %s 선택, 컴퓨터는 %s 선택, 이겼습니다!\n", str[user], str[random]);
                win++;
                break;
                default:
                break;
            }
            break;
            case 3:
            switch(random)
            {
                case 1:
                printf("당신은 %s 선택, 컴퓨터는 %s 선택, 이겼습니다!\n", str[user], str[random]);
                win++;
                break;
                case 2:
                printf("당신은 %s 선택, 컴퓨터는 %s 선택, 졌습니다!\n", str[user], str[random]);
                lose++;
                break;
                default:
                break;
            }
            break;
            default:
            break;
        }
    }
    printf("게임의 결과 : %d승, %d무\n", win, tie);
    return 0;
}