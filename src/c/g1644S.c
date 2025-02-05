#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int n, ptr1, ptr2, cnt;
    long long *prime;
    long long *arr;

    scanf("%d", &n);

    prime = (long long *)malloc(sizeof(long long) * (n + 1));
    arr = (long long *)malloc(sizeof(long long) * (n + 1));

    memset(prime, 0, sizeof(long long) * (n + 1));
    memset(arr, 0, sizeof(long long) * (n + 1));

    ptr1 = 2;
    for(int i = 2; i <= n; i++)
    {
        if(prime[i] == 0)
        {
            arr[ptr1] += arr[ptr1 - 1] + i;
            ptr1++;
            for(int j = 2; j <= n / i; j++)
            {
                prime[i * j] = 1;
            }
        }
    }

    cnt = 0;
    ptr1 = 1;
    ptr2 = 2;
    while(ptr1 <= n - 1 && ptr2 <= n)
    {
        if(arr[ptr2] - arr[ptr1] == n)
        {
            cnt++;
            ptr2++;
            ptr1++;
        }
        else if(arr[ptr2] - arr[ptr1] > n)
        {
            ptr1++;
        }
        else if(arr[ptr2] - arr[ptr1] < n)
        {
            ptr2++;
        }
    }
    printf("%d", cnt);
    free(arr);
    free(prime);
    return 0;
}
