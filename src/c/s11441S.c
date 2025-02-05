#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n, m, tmp, ai, aj;
    int *arr;

    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * (n + 1));
    memset(arr, 0, sizeof(int) * (n + 1));

    for(int i = 1; i < n + 1; i++)
    {
        scanf("%d", &tmp);
        arr[i] = tmp + arr[i - 1];
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &ai, &aj);
        tmp = arr[aj]- arr[ai - 1];
        printf("%d\n", tmp);
    }
    free(arr);
    return 0;
}
