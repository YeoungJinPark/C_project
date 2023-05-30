#include <stdio.h>

int main(void)
{
    int arr[10];
    int i, j=9, temp=0;

    for(i=0; i<=j; i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i]%2==0)
        {
            arr[j]=arr[i];
            j--;
            i--;
        }
    }

    for(i=0; i<10; i++)
    printf("%d ", arr[i]);

    printf("\n");
    return 0;
}