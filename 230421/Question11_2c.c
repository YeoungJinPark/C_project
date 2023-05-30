#include <stdio.h>

int main(void)
{
    char str[50];
    char max=0;
    int i=0;

    printf("영단어 입력\n");
    scanf("%s", str);

    while(str[i]!='\0')
    {
        if(max<str[i])
        max=str[i];
        i++;
    }
    printf("아스키 코드 값이 가장 큰 문자: %c\n", max);
    return 0;
}