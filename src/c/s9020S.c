#include <stdio.h>

int is_prime(int n)
{
    if(n == 2)
        return 1;
    for(int i = 2; i <= n / i; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int abs(int a)
{
    if(a < 0)
        return -1 * a;
    else
        return a;
}

int main(void)
{
    int t, n, p1, p2, min;

    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        min = 0x7fffffff;
        scanf("%d", &n);
        for(int j = 2; j <= n - 2; j++)
        {
            if((is_prime(j) && is_prime(n - j)) && abs(n - 2 * j) < min)
            {
                p1 = j;
                p2 = n - p1;
                min = abs(n - 2 * j);
            }
        }
        printf("%d %d\n", p1, p2);
    }
    return 0;
}
