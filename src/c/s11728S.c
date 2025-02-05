#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m, ap, bp;
    int *a, *b, *res;

    scanf("%d %d", &n, &m);
    ap = 0;
    bp = 0;
    a = (int *)malloc(sizeof(int) * n);
    b = (int *)malloc(sizeof(int) * m);
    res = (int *)malloc(sizeof(int) * (n + m));

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    for(int i = 0; i < m + n; i++)
    {
        if(ap == n)
            res[i] = b[bp++];
        else if(bp == m)
            res[i] = a[ap++];
        else if(a[ap] <= b[bp])
        {
            res[i] = a[ap];
            ap++;
        }
        else
        {
            res[i] = b[bp];
            bp++;
        }
    }
    for(int i = 0; i < n + m; i++)
    {
        printf("%d ", res[i]);
    }
    return 0;
}