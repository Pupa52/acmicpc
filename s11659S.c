#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m, i, j, index;
    int *arr;

    scanf("%d %d", &n, &m);
    arr = (int *)malloc(sizeof(int) * n + 1);
    for(index = 0; index < n + 1; index++)
    {
        arr[index] = 0;
    }
    for(index = 1; index < n + 1; index++)
    {
        scanf("%d", &arr[index]);
        arr[index] += arr[index - 1];
    }
    for(index = 0; index < m; index++)
    {
        scanf("%d %d", &i, &j);
        printf("%d\n", arr[j] - arr[i - 1]);
    }
    free(arr);
    return 0;
}