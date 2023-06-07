#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rec(int *arr, int *number, int n, int index, int currentDep, int maxDep)
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
    for(int i = 1; i <= n; i++)
    {
        if(number[i - 1] == 0)
        {
            number[i - 1] = 1;
            arr[currentDep] = i;
            rec(arr, number, n, i + 1, currentDep + 1, maxDep);
            number[i - 1] = 0;
        }
    }
}

int main(void)
{
    int n, m;
    int *arr;
    int *number;

    scanf("%d %d", &n, &m);
    arr = (int *)malloc(sizeof(int) * m);
    number = (int *)malloc(sizeof(int) * n);
    memset(arr, 0, sizeof(int) * n);

    rec(arr, number, n, 1, 0, m);
    return 0;
}
