#include <stdio.h>

void fibonacci(int p, int q, long long *arr)
{
    for(int i = 1; i <= p; i++)
    {
        if(i == 0)
            arr[i] = 0;
        else if(i == 1)
            arr[i] = 1;
        else
            arr[i] = (arr[i - 1] % q + arr[i - 2] % q);
    }
    return;
}

int main(void)
{
    long long arr[10001] = { 0, };
    int t, p, q;

    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d %d", &p, &q);
        fibonacci(p, q, arr);
        printf("Case #%d: %lld\n", i + 1, arr[p] % q);
    }
}