#include <stdio.h>

int main(void)
{
    char arr[9] = {'G', 'o', 'o','d',' ','t', 'i', 'm', 'e'};

    for(int i=0; i<9; i++)
    {
        printf("%c",arr[i]);
    }
    printf("\n");
    return 0;
}