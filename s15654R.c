#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* first, const void* second)
{
    if(*(int*)first > *(int*)second)
        return 1;
    else if(*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

void rec(int *num, int *arr, int *flag, int n,  int currentDep, int maxDep)
{
    if(currentDep == maxDep)
    {
        for(int i = 0; i < maxDep; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(flag[i] == 0)
        {
            flag[i] = 1;
            arr[currentDep] = num[i];
            rec(num, arr, flag, n, currentDep + 1, maxDep);
            flag[i] = 0;
        }
    }
}

int main(void)
{
    int n, m;
    int *num;
    int *flag;
    int *arr;

    scanf("%d %d", &n, &m);
    num = (int *)malloc(sizeof(int) * n);
    flag = (int *)malloc(sizeof(int) * n);
    arr = (int *)malloc(sizeof(int) * m);
    memset(flag, 0, sizeof(int) * n);
    memset(arr, 0, sizeof(int) * m);

    for(int i = 0; i < n; i++) scanf("%d",& num[i]);
    qsort(num, n, sizeof(int), compare);

    rec(num, arr, flag, n, 0, m);
    free(arr);
    return 0;
}
