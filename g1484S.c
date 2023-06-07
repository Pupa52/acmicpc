#include <stdio.h>

int main(void)
{
    int g, tmp, cnt;

    scanf("%d", &g);
    cnt = 0;
    for(int i = 1; i <= g; i++)
    {
        if(i >= g / i && g % i == 0)
        {
            tmp = g / i + i;
            if(tmp % 2 == 0 && i - (tmp / 2) > 0)
            {
                printf("%d\n", tmp / 2);
                cnt++;
            }
        }
    }
    if(cnt == 0)
        printf("-1");
    return 0;
}
