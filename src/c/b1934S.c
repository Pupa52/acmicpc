#include <stdio.h>

int lsm(int a, int b)
{
    if(a % b == 0)
        return b;
    else
        return lsm(b, a % b);
}

int main(void)
{
    int t, a, b, r;

    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d %d", &a, &b);
        r = lsm(a, b);
        printf("%d\n", (a / r) * b);
    }
    return 0;
}