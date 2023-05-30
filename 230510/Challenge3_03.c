#include <stdio.h>
#include <stdlib.h>

int main(void)  //0이상 99이하의 난수를 5개 생성
{
    int i;

    for(i=0; i<5; i++)
    {
        printf("%d ", rand()%100);
    }
    printf("\n");
    return 0;
}