#include <stdio.h>

int main(void)
{
    char str1[50];
    char str2[50];
    int i=0;

    printf("뒤집을 영단어 입력\n");
    scanf("%s", str1);

    while(str1[i]!='\0')
    i++;

    str2[i]=str1[i];
    i--;

    for(int j=0; i>=0; j++)
    {
        str2[j]=str1[i];
        i--;
    }
    printf("%s\n", str2);
    return 0;
}