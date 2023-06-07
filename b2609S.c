#include <stdio.h>

int gcd(int a, int b)
{
    if(a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int main(void)
{
    int a, b, r;

    scanf("%d %d", &a, &b);
    r = gcd(a, b);
    printf("%d\n", r);
    printf("%d\n", (a / r) * b);
    return 0;
}