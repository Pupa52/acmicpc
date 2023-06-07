#include <stdio.h>

typedef struct _zerone{
    int zero;
    int one;
}zerone;

void fibonacci(int n, int pivot, zerone *arr)
{
    for(int i = pivot; i <= n; i++)
    {
        if(i == 0)
        {
            arr[i].zero = 1;
            arr[i].one = 0;
        }
        else if(i == 1)
        {
            arr[1].zero = 0;
            arr[1].one = 1;
        }
        else
        {
            arr[i].zero = arr[i - 1].zero + arr[i - 2].zero;
            arr[i].one = arr[i - 1].one + arr[i - 2].one;
        }
    }
    return;
}

int main(void)
{
    zerone arr[41] = {0};
    int t, n;
    int pivot = 0;

    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        if(arr[n].zero == 0 && arr[n].one == 0)
        {
            fibonacci(n, pivot, arr);
            pivot = n;
        }
        printf("%d %d\n", arr[n].zero, arr[n].one);
    }
}