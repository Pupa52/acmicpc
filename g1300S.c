#include <stdio.h>

long long int min(long long int a, long long int b)
{
    if(a > b)
        return b;
    else
        return a;
}

int main(void)
{
    long long int n, k, start, mid, end, cnt, res;

    scanf("%lld", &n);
    scanf("%lld", &k);
    start = 1;
    end = k;
    while(start <= end)
    {
        cnt = 0;
        mid = (start + end) / 2;
        for(int i = 1; i <= n; i++)
        {
            cnt += min(mid / i, n);
        }
        if(cnt >= k)
        {
            res = mid;
            end = mid - 1;
        }
        else if (cnt < k)
        {
            start = mid + 1;
        }
    }
    printf("%lld", res);
    return 0;
}