#include <stdio.h>

int is_prime(int n)
{
    for(int i = 2; i <= n / i ; i++)
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
    if(m < 2)
        m = 2;
    for(int i = m; i <= n; i++)
    {
        if(is_prime(i) == 1)
            printf("%d\n", i);
    }
    return 0;
}