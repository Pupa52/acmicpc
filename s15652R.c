#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rec(int *arr, int n, int index, int currentDep, int maxDep)
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
    for(int i = index; i <= n; i++)
    {
        arr[currentDep] = i;
        rec(arr, n, i, currentDep + 1, maxDep);
    }
}

int main(void)
{
    int n, m;
    int *arr;

    scanf("%d %d", &n, &m);
    arr = (int *)malloc(sizeof(int) * m);
    memset(arr, 0, sizeof(int) * m);

    rec(arr, n, 1, 0, m);
    free(arr);
    return 0;
}
