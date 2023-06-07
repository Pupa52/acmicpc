#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int n)
{
    int tmp;

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    int n, res;
    int *A_arr;
    int *B_arr;
    
    scanf("%d", &n);
    A_arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &A_arr[i]);
    }
    B_arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &B_arr[i]);
    }
    
    sort(A_arr, n);
    sort(B_arr, n);
    
    res = 0;
    for(int i = 0; i < n; i++)
    {
        res = res + (A_arr[i] * B_arr[n - i - 1]);
    }
    printf("%d", res);
    free(A_arr);
    free(B_arr);
    return 0;
}