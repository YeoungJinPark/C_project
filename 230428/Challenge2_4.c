#include <stdio.h>
#include <string.h>

void Palindrome(char* word)
{
    int len=0, i=0, j=0, check=0;

    len=strlen(word);
    j=len-1;

    for(i=0; i<len; i++)
    {
        if(word[i]!=word[j])
        check=1;
        j--;
    }

    if(check)
    printf("회문이 아닙니다.\n");
    else
    printf("회문입니다.\n");
}

int main(void)
{
    char str2[50];

    printf("회문을 판별할 영단어 입력: ");
    scanf("%s", str2);
    Palindrome(str2);
    return 0;
}