#include <stdio.h>

int main(void)      //10진수를 입력받아 2진수로 변환해 출력
{
    int dec, i=0;
    int remainder[50]={0, };

    printf("2진수로 변환할 10진수 정수 입력: ");
    scanf("%d", &dec);
    while(1)
    {
        remainder[i] = dec % 2;
        dec /= 2;
        i++;

        if(dec ==0)
        break;
    }
    for(i= i-1; i>=0; i--)
    {
        printf("%d", remainder[i]);
    }
    printf("\n");
}