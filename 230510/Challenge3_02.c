#include <stdio.h>  //입력받은 n x n 크기의 달팽이 배열 출력

int main(void)
{
    int arr[50][50]={};
    int size;
    int num=1, i, j, k=0;
    int put, l=2;
    
    printf("n x n 길이의 달팽이 배열을 출력한다.\nn값 입력: ");
    scanf("%d", &size);
    put=size;
    if(put<=2)
    l=0;

    for(i=0; i<put-l; i++)
    {
        for(j=k; j<size; j++)
        {
            arr[i][j]=num;
            num++;
        }
        
        for(j=k+1; j<size; j++)
        {
            arr[j][size-1]=num;
            num++;
        }
        for(j=size-1; j>k; j--)
        {
            arr[size-1][j-1]=num;
            num++;
        }
        for(j=size-2; j>k; j--)
        {
            arr[j][k]=num;
            num++;
        }
        size--;
        k++;
    }
    for(i=0; i<put; i++)
    {
        for(j=0; j<put; j++)
        printf("%d ", arr[i][j]);
        printf("\n");
    }
    return 0;
}