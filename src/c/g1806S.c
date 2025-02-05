#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, s, ptr1, ptr2, tmp, length;
    long long *arr;

    scanf("%d %d", &n, &s);
    arr = (long long *)malloc(sizeof(long long) * (n + 1));

    arr[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
        arr[i] += arr[i - 1];
    }
    ptr1 = 0;
    ptr2 = 1;
    length = 0x7fffffff;
    while(ptr1 <= n - 1 && ptr2 <= n)
    {
        tmp = arr[ptr2] - arr[ptr1];
        if(tmp >= s && length > ptr2 - ptr1)
            length = ptr2 - ptr1;
        tmp >= s ? ptr1++ : ptr2++;
    }
    if(length == 0x7fffffff)
        printf("0");
    else
        printf("%d", length);
    return 0;
}
