#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int com[3];
    int user[3];
    int strike=0, ball=0, i, j, cnt=0, check=10;

    srand((unsigned int)time(NULL));
    printf("Start Game!\n");

    for(i=0; i<3; i++)  //컴퓨터 랜덤 랜덤 숫자
    {
        com[i]=rand()%10;
        if(com[i]==check)
        {
            i--;
            continue;
        }
        check=com[i];
    }

    while(1)
    {
        check=0;
        printf("3개의 숫자 선택: ");
        scanf("%d %d %d", &user[0], &user[1], &user[2]);
        for(i=0; i<3; i++)
        {
            if(user[i]>9)
            {
                printf("0~9까지만 입력해주세요\n");
                i--;
                continue;
            }
            for(j=0; j<3; j++)
            {
                if(i==j)
                {
                    continue;
                }
                if(user[i]==user[j])
                check++;
            }
        }
        if(check>0)
        {
            printf("중복되지 않는 숫자로 입력해주세요.\n");
            continue;
        }
        for(i=0; i<3; i++)
        {
            if(user[i]==com[i])
            strike++;
            else
            {
                for(j=1; j<3; j++)
                {
                    if(user[i]==com[j])
                    ball++;
                }
            }
        }
        cnt++;
        printf("%d번째 도전 결과: %dstrike, %dball!!\n", cnt, strike, ball);
        if(strike>=3)
        {
            printf("Game Over!\n");
            break;
        }
        strike=0;
        ball=0;
    }
    return 0;
}