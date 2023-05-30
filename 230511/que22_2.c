#include <stdio.h>
#include <string.h>

struct person
{
    char name[20];
    char rrn[20];
    int salary;
};

int main(void)
{
    struct person arr[3];
    int i;
    
    for(i=0; i<3; i++)
    {
        printf("이름 입력: "); scanf("%s", arr[i].name);
        printf("주민번호 입력: "); scanf("%s", arr[i].rrn);
        printf("급여 입력: "); scanf("%d", arr[i].salary);
    }

    for(i=0; i<3; i++)
    {
        printf("이름 입력: "); scanf("%s", arr[i].name);
        printf("주민번호 입력: "); scanf("%s", arr[i].rrn);
        printf("급여 입력: "); scanf("%d", arr[i].salary);
    }
    return 0;
}