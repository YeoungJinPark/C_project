#include <stdio.h>

int main(void)
{
    int grade[5][5];
    int j, i, total=0;

    printf("국어 영어 수학 국사의 순서로\n네 명의 성적 입력: ");
    for(j=0; j<4; j++)  //4x4 입력받기
    {
        for(i=0; i<4; i++)
        scanf("%d", &grade[j][i]);
    }

    for(j=0; j<4; j++)  //개인별 총점
    {
        total=0;
        for(i=0; i<4; i++)
        total+=grade[j][i];
        grade[j][4]=total;
    }
    
    for(j=0; j<5; j++)   //과목별 총점
    {
        total=0;
        for(i=0; i<4; i++)
        total+=grade[i][j];
        grade[4][j]=total;
    }

    for(j=0; j<5; j++)
    {
        for(i=0; i<5; i++)
        printf("%d ", grade[j][i]);

        printf("\n");
    }
}