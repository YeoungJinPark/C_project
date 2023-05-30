#include <stdio.h>

int main(void)
{
    int arr[3][2]={
        {1, 2},
        {3, 4},
        {5, 6}
    };
    //arr[i]==*(arr+i)
    printf("%d %d \n", arr[1][0], arr[0][1]);           //배열요소 1열의 0행 , 0열의 1행
    printf("%d %d \n", *(arr[2]+1), *(arr[1]+1));       //인덱스 기준 2열의 1행, 1열의 1행
    printf("%d %d \n", (*(arr+2))[0], (*(arr+0))[1]);   //2열의 0행, 0열의 1행
    printf("%d %d \n", **arr, *(*(arr+0)+0));           //0열의 0행, 0열의 0행
    /*출력 결과는
    3, 2
    6, 4
    5, 2
    1, 1*/
    return 0;
}