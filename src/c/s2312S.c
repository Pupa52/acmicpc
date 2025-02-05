#include <stdio.h>

int main(void)
{
    int t, n, tmp, cnt;

    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        for(int j = 2; n > 1; j++)
        {
            if(n % j == 0)
            {
                cnt = 0;
                for(int k = j; n % k == 0; cnt++)
                {
                    n /= j;
                }
                printf("%d %d\n", j, cnt);
            }
        }
    }
    return 0;
}
