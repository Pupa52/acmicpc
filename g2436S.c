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
    int gcd, lcm, mul, result = 0x7fffffff;
    int a, b, sol_a, sol_b;

    scanf("%d %d", &gcd, &lcm);
    mul = lcm / gcd;
    for(int i = 1; i * i <= mul; i++)
    {
        if(mul % i == 0)
        {
            a = i;
            b = mul / i;
        }
        if(fgcd(a, b) != 1)
            continue;
        if(a + b < result)
        {
            result = a + b;
            sol_a = a;
            sol_b = b;
        }
    }
    printf("%d %d", sol_a*gcd, sol_b*gcd);
    return 0;
}