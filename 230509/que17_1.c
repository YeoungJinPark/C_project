#include <stdio.h>

void MaxAndMin(int* arr, int** max, int** min)
{
    int i;
    int* arr_max=&arr[0];
    int* arr_min=&arr[0];

    for(i=1; i<5; i++)
    {
        if(arr[i]>*arr_max)
        arr_max=&arr[i];
        if(arr[i]<*arr_min)
        arr_min=&arr[i];
    }
    *max=arr_max;
    *min=arr_min;
}

int main(void)
{
    int arr[5]={1, 2, 3, 4, 5};
    int *maxPtr;
    int *minPtr;

    MaxAndMin(arr, &maxPtr, &minPtr);
    printf("maxPtr:%d minPtr:%d \n", *maxPtr, *minPtr);
    return 0;
}