#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m, tmp, pos_X1, pos_X2, pos_y1, pos_Y2;
    int **arr;

    scanf("%d %d", &n, &m);
    arr = (int **)malloc(sizeof(int *) * n);
    for(int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * (n + 1));
        arr[i][0] = 0;
        for(int j = 1; j < n + 1; j++)
        {
            scanf("%d", &tmp);
            arr[i][j] = tmp + arr[i][j - 1];
        }
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d %d", &pos_X1, &pos_y1, &pos_X2, &pos_Y2);
        tmp = 0;
        for(int j = pos_X1 - 1; j <= pos_X2 - 1; j++)
        {
            tmp = tmp + arr[j][pos_Y2] - arr[j][pos_y1 - 1];
        }
        printf("%d\n", tmp);
    }
    free(arr);
    return 0;
}
