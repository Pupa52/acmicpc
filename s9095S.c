#include <stdio.h>

void rec(int n, int *cnt, int *arr)
{
    if(n == 0)
    {
        *cnt += 1;
        return;
    }
    if(n - 3 >= 0)
    {
        if(arr[n - 3] != 0)
            *cnt += arr[n - 3];
        else
            rec(n - 3, cnt, arr);
    }
    if(n - 2 >= 0)
    {
        if(arr[n - 2] != 0)
            *cnt += arr[n - 2];
        else
            rec(n - 2, cnt, arr);
    }
    if(n - 1 >= 0)
    {
        if(arr[n - 1] != 0)
            *cnt += arr[n - 1];
        else
            rec(n - 1, cnt, arr);
    }
}
int main(void)
{
    int arr[12] = { 0, };
    int t, n, cnt;

    scanf("%d", &t);

    for(int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        for(int j = 1; j <= n; j++)
        {
            cnt = 0;
            rec(j, &cnt, arr);
            arr[j] = cnt;
        }
        printf("%d\n", arr[n]);
    }
    return 0;
}