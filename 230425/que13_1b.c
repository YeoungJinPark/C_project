#include <stdio.h>

int main(void)
{
    int arr[5]={1,2,3,4,5};
    int* ptr=arr;
    int i=0;

    for(i=1; i<=5; i++)
    {
        printf("%d\n", *ptr+2);
        ptr++;
    }
}