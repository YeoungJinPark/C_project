#include <stdio.h>

int main(void)
{
    char str[50];
    int i=0, len=0;
    printf("영단어를 입력해주세요.\n");
    scanf("%s", str);
    
    while(str[i]!='\0')
    {
        i++;
        len++;
    }
    printf("단어의 길이: %d\n", len);
    return 0;
}