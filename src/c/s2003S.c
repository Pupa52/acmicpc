#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n = 0, m = 0, cnt = 0;
    int leftPtr, rightPtr;
    long long tmp = 0;
    long long *arr = NULL;

    scanf("%d %d", &n, &m);
    arr = (long long *)malloc(sizeof(long long) * (n + 1));
    memset(arr, 0, sizeof(long long) * (n + 1));

    for(int i = 1; i < n + 1; i++)
    {
        scanf("%lld", &tmp);
        arr[i] = tmp + arr[i - 1];
    }
    tmp = 0;
    leftPtr = 0;
    rightPtr = 1;
    while(leftPtr < n && rightPtr < n + 1)
    {
        tmp = arr[rightPtr] - arr[leftPtr];
        if(tmp == m) cnt++;
        tmp >= m ? leftPtr++ : rightPtr++;
    }
    printf("%d", cnt);
    free(arr);
    return 0;
}
