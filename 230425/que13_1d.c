#include <stdio.h>

int main(void)
{
    int arr[6]={1, 2, 3, 4, 5, 6};
    int* ptr1=&arr[0];
    int* ptr2=&arr[5];
    int i=0, change;

    for(i=1; i<=3; i++)
    {
        change=*ptr1;
        *ptr1=*ptr2;
        *ptr2=change;
        ptr1+=1;
        ptr2-=1;
    }
    for(i=0; i<=5; i++)
    printf("%d\n", arr[i]);
    return 0;
}