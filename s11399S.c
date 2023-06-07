#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int *p;
    int tmp = 0;
    int cnt;
    int res = 0;

    scanf("%d", &n);
    cnt = n;
    p = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            if(p[j] > p[j + 1])
            {
                tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        res = res + (cnt * p[i]);
        cnt--;
    }
    printf("%d", res);
    free(p);
    return 0;
}