#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n, k, step = 2, index = 1, cnt = 0;
    int *arr;

    scanf("%d %d", &n, &k);
    arr = (int *)malloc(sizeof(int) * (n + 2));
    memset(arr, 0, sizeof(int) * (n + 2));

    while(1)
    {
        if(arr[step * index] == 0)
        {
            arr[step * index] = 1;
            cnt++;
            if(cnt == k)
            {
                printf("%d", step * index);
                break;
            }
        }
        if(step * (index + 1) > n)
        {
            step++;
            index = 1;
        }
        else
            index++;
    }
    free(arr);
    return 0;
}