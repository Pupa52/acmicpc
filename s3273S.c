#include <stdio.h>
#include <stdlib.h>

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main(void)
{
    int n, x, cnt, tmp;
    int left, right;
    int *arr;

    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &x);
    qsort(arr, n, sizeof(int), compare);

    left = 0;
    right = n - 1;
    cnt = 0;
    while(left < right)
    {
        tmp = arr[left] + arr[right];
        if(tmp == x) cnt++;
        tmp > x ? right-- : left++;
    }
    printf("%d", cnt);
    free(arr);
    return 0;
}
