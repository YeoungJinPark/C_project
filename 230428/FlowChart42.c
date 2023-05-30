#include <stdio.h>

//에라토스테네스의 체
//소수를 찾는 알고리즘
//이 코드에서는 2~100까지 숫자에서 소수만 출력함

int main(void)
{
    int arr[100]={0, };
    int i;

    for(i=2; i<=9; i++)
    {
        if(arr[i]==0)
        {
            for(int j=i*2; j<=100; j+=i)
            arr[j]=1;
        }
    }
    for(i=2; i<=100; i++)
    {
        if(arr[i]==0)
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}