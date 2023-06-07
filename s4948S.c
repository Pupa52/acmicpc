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

int main(void)
{
    int n = 1, cnt;

    while(1)
    {
        cnt = 0;
        scanf("%d", &n);
        if(n == 0)
            break;
        for(int i = n + 1; i <= 2 * n; i++)
        {
            if(is_prime(i))
                cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
