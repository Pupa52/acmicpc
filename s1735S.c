#include <stdio.h>

int f_gcd(int a, int b)
{
    if(a % b == 0)
        return b;
    else
        return f_gcd(b, a % b);
}

int main(void)
{
    int a1, a2, b1, b2, gcd, lcm;
    int c1, c2;

    scanf("%d %d", &a1, &a2);
    scanf("%d %d", &b1, &b2);
    gcd = f_gcd(a2, b2);
    lcm = a2 * b2 / gcd;
    c2 = lcm;
    c1 = (lcm / a2 * a1) + (lcm / b2 * b1);
    do
    {
        gcd = f_gcd(c1, c2);
        c1 /= gcd;
        c2 /= gcd;
    } while (gcd != 1);
    
    printf("%d %d", c1, c2);
    return 0;
}
