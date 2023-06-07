#include <stdio.h>

void is_prime(int n, int *cnt)
{
    if(n < 2)
        return;
    if(n == 2)
        *cnt += 1;
    else
    {
        for(int i = 2; i <= n / i; i++)
        {
            if(n % i == 0)
                return;
        }
        *cnt += 1;
    }
}

int main(void)
{
    int t, n, cnt = 0;

    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        is_prime(n, &cnt);
    }
    printf("%d", cnt);
}