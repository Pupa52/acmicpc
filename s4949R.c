#include <stdio.h>

int is_prime(int n)
{
    for(int i = 0; i < n / i; i++)
    {
        if(n % i == 0)
            return -1;
    }
    return 1;
}

int main(void)
{
    int m, n;

    scanf("%d %d", &m, &n);
    for(int i = m, i <= n; i++)
    {
        if(is_prime == 1)
            printf("%d\n", i);
    }
    return 0;
}