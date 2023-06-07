#include <stdio.h>

int fgcd(int a, int b)
{
    if(a % b == 0)
        return b;
    else
        return fgcd(b, a % b);
}

int main(void)
{
    int n, m, gcd;
    scanf("%d:%d", &n, &m);
    gcd = fgcd(n, m);
    printf("%d:%d", n / gcd, m / gcd);
    return 0;
}