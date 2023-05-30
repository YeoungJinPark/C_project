#include <stdio.h>

int main(void)
{
    int arr[5]={1,2,3,4,5};
    int* ptr=arr;
    int i=0;
    
    printf("증가 전\n");
    for(i=0; i<5; i++)
    printf("%d\n", arr[i]);
    printf("증가 후\n");
    for(i=0; i<5; i++)
    {
        *ptr+=2;
        ptr++;
        printf("%d\n", arr[i]);
    }
    return 0;
}