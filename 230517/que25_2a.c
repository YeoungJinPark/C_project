#include <stdio.h>
#include <stdlib.h>

void ClearBuffer(void)
{
    while(getchar()!='\n');
}

int main(void)
{
    char* str;
    int len;
    int i, buff;

    printf("입력할 문자열의 길이: ");
    scanf("%d", &len);
    ClearBuffer();

    str = (char*)malloc(sizeof(char)*len+1);
    printf("문자열 입력: ");
    gets(str);

    if(str[i]==' ')
    {
        printf(" ");
    }
    printf("\n");
    return 0;
}