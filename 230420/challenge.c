#include <stdio.h>

int ToThePower(int n)   //거듭제곱을 하기위한 함수
{
    int result=2;   //2의 k승을 구해 비교하는 문제

    for(int i=1; i<=n; i++) //k만큼 반복
    {
        result*=2;
    }
    return result;  //2의 k승 값 반환
}

void Challenge1(void)   // 10진수 -> 16진수
{
    int num1, num2;

    printf("입력한 두 10진수를 16진수로 출력합니다.\n입력: ");
    scanf("%d %d", &num1, &num2);
    printf("%x %x\n", num1, num2);
}

void Challenge2(void)   //입력값 사이의 구구단 출력 단, 입력 순서는 자유롭게
{
    int dan1, dan2;

    printf("입력한 두 단 사이의 구구단을 출력합니다.\n입력: ");
    scanf("%d %d", &dan1, &dan2);
    if(dan1>dan2)
    {
        for(int i=dan2; i<=dan1; i++)
        {
            for(int j=1; j<=9; j++)
            printf("%dx%d=%d\n", i, j, i*j);
        }
    }
    else if(dan1<=dan2)
    {
        for(int i=dan1; i<=dan2; i++)
        {
            for(int j=1; j<=9; j++)
            printf("%dx%d=%d\n", i, j, i*j);
        }
    }
    else
    printf("ERROR_");
}

void Challenge3(void)
{
    int num1, num2, max;

    printf("최대 공약수를 구할 두 정수 입력: ");
    scanf("%d %d", &num1, &num2);
    
    if(num1<num2)
    {
        for(int i=1; i<=num2; i++)
        {
            if(num1%i==0&&num2%i==0)
            max=i;
        }
        printf("%d과(와) %d의 최대 공약수: %d\n", num1, num2, max);
    }
    else
    {
        for(int j=1; j<=num1; j++)
        {
            if(num1%j==0&&num2%j==0)
            max=j;
        }
        printf("%d과(와) %d의 최대 공약수: %d\n", num1, num2, max);
    }
}

void Challenge4(void)   //군것질 선택
{
    int select;
    printf("1.크림빵 1개, 새우깡2개, 콜 라 4개\n");
    printf("2.크림빵 2개, 새우깡3개, 콜 라 1개\n");
    printf("3.크림빵 4개, 새우깡1개, 콜 라 2개\n");
    printf("소유 금액: 3500\n선택: ");
    scanf("%d", &select);
    switch(select)
    {
        case 1:
        printf("크림빵 1개, 새우깡2개, 콜 라 4개 구매!\n");
        break;
        case 2:
        printf("크림빵 2개, 새우깡3개, 콜 라 1개 구매!\n");
        break;
        case 3:
        printf("크림빵 4개, 새우깡1개, 콜 라 2개 구매!\n");
        break;
        default:
        return;
    }

    /*int bread=500, snack=700, coke=400, menu=1, cycle=1, next=1, sum;

    while(1)
    {
        switch(menu)
        {
            case 1:
            bread+=500;
            break;
            case 2:
            snack+=700;
            break;
            case 3:
            coke+=400;
            break;
        }
        sum=bread+snack+coke;
        if(sum>3500&&menu==1)
        {
            bread-=500;
            menu=2;
            if(next==2)
            cycle++;
        }
        else if(sum>3500&&menu==2)
        {
            snack-=700;
            menu=3;
            if(next==3)
            cycle++;
        }
        else if(sum>3500&&menu==3)
        {
            coke-=400;
            if(next==1)
            cycle++;
            
        }

        if(sum==3500)
        {
            printf("크림빵 %d개 새우깡 %d개 콜 라 %d개", bread, snack, coke);
            bread=500, snack=700, coke=400, next++;
            menu=next;
            cycle=1;
        }
    }*/
}

void Challenge5(void)
{
    int chk=1, cnt=0;
    for(int i=2; i<=50; i++)
    {
        chk=1;
        for(int j=2; j<=i-1; j++)
        {
            if(i%j==0)
            {
                chk=0;
                break;
            }
        }
        if(chk==1)
        {
            printf("%d ", i);
            cnt++;
            if(cnt>=10)
            {
                printf("\n");
                return;
            }
        }
    }
}

void Challenge6(void)
{
    int sec, hour, minute;

    printf("변환할 초를 입력: ");
    scanf("%d", &sec);
    hour=sec/3600;
    sec%=3600;
    minute=sec/60;
    sec%=60;
    printf("시:%d 분:%d 초:%d\n", hour, minute, sec);
}

void Challenge7(void)
{
    int i=1, n, power, result=0;

    printf("n값 입력: ");
    scanf("%d", &n);
    while(i++)  //k의 최댓값을 구하기 위해 n보다 커질때까지 반복
    {
        power=ToThePower(i);    //power에는 2의 k승 값이 들어감
        result=i;
        if(power>n) //2의 k승값이 n보다 커지면 멈춤
        break;
    }
    printf("공식을 만족하는 k의 최댓값: %d\n", result);
}

int Challenge8(int num) //재귀함수
{
    if(num==0)
    return 1;
    else
    return 2*Challenge8(num-1); //num이 2일때 2*Challenge8(2-1) -> 2*Challenge8(1-1) = 2*Challenge8(0)은 2*1 ->  2*Challenge8(1)은 2*2 ...
}

int main(void)
{
    int select, result;

    printf("1.10진수->16진수 2.구구단 3.최대 공약수 4.군것질 5.10개의 소수 6.초->시, 분, 초 7.2^k<=n k최댓값 8.2의n승 재귀함수\n");
    scanf("%d", &select);

    switch(select)
    {
    case 1:
        Challenge1();
        break;
    case 2:
        Challenge2();
        break;
    case 3:
        Challenge3();
        break;
    case 4:
        Challenge4();
        break;
    case 5:
        Challenge5();
        break;
    case 6:
        Challenge6();
        break;
    case 7:
        Challenge7();
        break;
    case 8:
        printf("정수 입력: ");
        scanf("%d", &select);
        result=Challenge8(select);
        printf("2의 %d승은 %d\n", select, result);
        break;
    default:
        return 0;
    }
    return 0;
}