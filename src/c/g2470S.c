#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *fisrt, const void *second)
{
    if(*(int *)fisrt > *(int *)second)
        return 1;
    else if(*(int *)fisrt < *(int *)second)
        return -1;
    else
        return 0;
}

int f_abs(int n)
{
    if(n < 0)
        return - 1 * n;
    else
        return n;
}

int main(void)
{
    int n, left, right, sLeft, sRight, tmp, min;
    int *arr;

    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);

    left = 0;
    right = n - 1;
    sLeft = 0;
    sRight = 0;
    min = 0x7fffffff;
    while(left < right)
    {
        tmp = arr[left] + arr[right];
        if(f_abs(tmp) <= min)
        {
            sLeft = left;
            sRight = right;
            min = f_abs(tmp);
        }
        tmp < 0 ? left++ : right--;
    }
    printf("%d %d", arr[sLeft], arr[sRight]);
    free(arr);
    return 0;
}