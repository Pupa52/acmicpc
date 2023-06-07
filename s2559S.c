#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, k, sum = 0, max = 0;
    int *arr;

    scanf("%d %d", &n, &k);
    arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    max = sum;
    for(int i = 0; i < n - k; i++)
    {
        sum -= arr[i];
        sum += arr[i + k];
        if(sum > max)
            max = sum;
    }
    printf("%d", max);
    return 0;
}