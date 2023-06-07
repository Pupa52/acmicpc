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
    int t, n, cnt;
    
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        cnt = 0;
        scanf("%d", &n);
        for(int j = 1; j <= n / j; j++)
        {
            if(n % j == 0 && gcd(j, n / j) == 1)
                cnt++;
        }
        printf("%d\n", cnt);
    }
    
    return 0;
}