#include <stdio.h>

void DesSort(int ary[], int len)
{
    int i, j;
    int temp;

    for(i=0; i<len-1; i++)
    {
        for(j=0; j< (len-i)-1; j++)
        {
            if(ary[j]<ary[j+1]);
            {
                temp=ary[j+1];
                ary[j+1]=ary[j];
                ary[j]=temp;
            }
        }
    }
}

int main(void)
{
    int arr[7];
    int i;

    printf("내림차순으로 정렬할 7개의 정수 입력\n");
    
    for(i=0; i<7; i++)
    {
        scanf("%d", &arr[i]);
        printf("입력: ");
    }

    DesSort(arr, 7);

    for(int i=0; i<7; i++)
    printf("%d ", arr[i]);
    printf("\n");
    return 0;
}