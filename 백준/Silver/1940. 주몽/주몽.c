#include <stdio.h>
#include <stdlib.h>

int compare (const void* first, const void* second)
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
    int n, m, tmp, cnt, left, right;
    int *arr;

    scanf("%d", &n);
    scanf("%d", &m);
    arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);

    cnt = 0;
    left = 0;
    right = n - 1;
    while(left < right)
    {
        tmp = arr[left] + arr[right];
        if(tmp == m)
            cnt++;
        tmp > m ? right-- : left++;
    }
    printf("%d", cnt);
    free(arr);
    return 0;
}