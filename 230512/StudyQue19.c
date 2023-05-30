#include <stdio.h>

void Ramenbokki(void)
{
    printf("라면볶이!\n");
}

void Buldak(void)
{
    printf("불닭볶음면!!\n");
}

void Cheesebokki(void)
{
    printf("치즈볶이!\n");
}

int main(void)
{
    int select;
    void (*fptr)(void);

    while(1)
    {
        printf("1.라면볶이 2. 불닭볶음면 3.치즈볶이\n선택: ");
        scanf("%d", &select);
        switch(select)
        {
            case 1:
            fptr=Ramenbokki;
            break;
            case 2:
            fptr=Buldak;
            break;
            case 3:
            fptr=Cheesebokki;
            break;
            default:
            printf("1~3까지만 선택해주세요!\n");
            continue;
        }
        break;
    }
    fptr();
    return 0;
}