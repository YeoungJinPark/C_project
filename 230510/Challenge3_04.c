#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)  //두개의 주사위를 던졌을 때의 결과 출력
{
    int i;

    srand((unsigned int)time(NULL));

    for(i=1; i<=2; i++)
    {
        printf("주사위%d의 결과%d ", i, rand()%6+1);
        printf("\n");
    }
    return 0;
}