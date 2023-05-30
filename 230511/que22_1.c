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
    struct person employee;
    
    printf("이름 입력: "); scanf("%s", employee.name);
    printf("주민번호 입력: "); scanf("%s", employee.rrn);
    printf("급여 입력: "); scanf("%d", &(employee.salary));

    printf("이름: %s\n", employee.name);
    printf("주민번호: %s\n", employee.rrn);
    printf("급여: %d\n", employee.salary);
    return 0;
}
