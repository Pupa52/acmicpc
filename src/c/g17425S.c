#include <stdio.h>

int main(void)
{
    int t, n;
    long long arr[1000001] = { 0, };

    for(int i = 1; i <= 1000001; i++)
    {
        for(int j = 1; j <= 1000001 / i; j++)
        {
            arr[i * j] += i;
        }
        arr[i] += arr[i - 1];
    }
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        printf("%lld\n", arr[n]);
    }
    return 0;
}
