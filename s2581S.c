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
    int m, n, min = 0, total = 0;

    scanf("%d %d", &m, &n);
    if(m < 2)
        m = 2;
    for(int i = m; i <= n; i++)
    {
        if(is_prime(i) == 1)
        {
            if(total == 0)
                min = i;
            total += i;
        }
    }
    if(total == 0)
    {
        printf("-1");
    }
    else
    {
        printf("%d\n", total);
        printf("%d\n", min);
    }
    return 0;
}