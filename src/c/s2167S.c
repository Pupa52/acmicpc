#include <stdio.h>
#include <stdlib.h>

typedef struct _pos{
    int x;
    int y;
}pos;

int main(void)
{
    int n, m, k, cnt, tmp;
    pos ptr1, ptr2;
    int **arr;
    
    scanf("%d %d", &n, &m);
    arr = (int **)malloc(sizeof(int *) * n);
    for(int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * (m + 1));
        arr[i][0] = 0;
        for(int j = 1; j < m + 1; j++)
        {
            scanf("%d", &tmp);
            arr[i][j] = tmp + arr[i][j - 1];
        }
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++)
    {
        scanf("%d %d %d %d", &ptr1.x, &ptr1.y, &ptr2.x, &ptr2.y);
        tmp = 0;
        for(int i = ptr1.x - 1; i <= ptr2.x - 1; i++)
        {
            tmp = tmp + arr[i][ptr2.y] - arr[i][ptr1.y - 1];
        }
        printf("%d\n", tmp);
    }
    free(arr);
    return 0;
}
