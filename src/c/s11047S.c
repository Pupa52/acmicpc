#include <stdio.h>

int main(void)
{
    int n, k;
    int coin[10];
    int cnt = 0;

    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &coin[i]);
    }
    for(int i = n - 1; i >= 0; i--)
    {
        if((k - coin[i]) == 0)
        {
            cnt += 1;
            break;
        }
        if((k - coin[i]) > 0)
        {
            cnt = cnt + (k / coin[i]);
            k %= coin[i];
        }
        if(k == 0)
            break;
    }
    printf("%d", cnt);
}