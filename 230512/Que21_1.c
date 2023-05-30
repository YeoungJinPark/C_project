#include <stdio.h>
#include <string.h>

int main(void)
{
    int get;

    while(1)
    {
        printf("a~Z까지의 알파벳 대소문자를 입력해주세요.\n");
        get=getchar();
        getchar();
        
        if(get>='A'&&get<='Z')
        get+=32;
        else if(get>='a'&&get<='z')
        get-=32;
        else
        {
            printf("a~Z까지의 알파벳 대소문자만 입력해주세요\n");
            continue;
        }
        putchar(get);
        printf("\n");
        break;
    }
    return 0;
}