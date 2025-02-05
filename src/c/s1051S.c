#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char tmp[51];
    int n, m, window_size, itmp, max;
    int **arr;
    scanf("%d %d", &n, &m);
    arr = (int **)malloc(sizeof(int *) * n);
    for(int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * m);
        scanf("%s", &tmp);
        for(int j = 0; j < m; j++)
        {
            arr[i][j] = tmp[j] - '0';
        }
    }
    max = 1;
    window_size = n > m ? m : n;

    for(int i = window_size; window_size > 1; window_size--)
    {
        for(int j = 0; j < n - window_size + 1; j++)
        {
            for(int k = 0; k < m - window_size + 1; k++)
            {
                if(arr[j][k] == arr[j][k + window_size - 1] &&
                    arr[j][k] == arr[j + window_size - 1][k] &&
                    arr[j][k] == arr[j + window_size - 1][k + window_size - 1])
                {
                    itmp = window_size * window_size;
                    max = itmp > max ? itmp : max;
                }
            }
        }
    }
    printf("%d", max);
    free(arr);
    return 0;
}
