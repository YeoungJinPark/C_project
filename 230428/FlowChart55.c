#include <stdio.h>

void Aliquot(int num)
{
    for(int i=1; i<=num; i++)
    {
        if(num%i==0)
        printf("%d ",i);
    }
}

int main(void)
{
    for(int i=1; i<=10; i++)
    {
        printf("%d의 약수:", i);
        Aliquot(i);
        printf("\n");
    }
    return 0;
}