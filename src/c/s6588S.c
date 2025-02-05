#include <stdio.h>

int main(void)
{
    int n = 0;
    int ptr = 0;

    int arr[1000001] = { 0, };

    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i < 1000001 * 0.5; i++)
    {
        if(arr[i] == 0)
        {
            for(int j = 2; j <= 1000001 / i; j++)
            {
                arr[i * j] = 1;
            }
        }
    }

    do{
        scanf("%d", &n);
        ptr = 0;
        for(int i = 3; i <= n; i += 2)
        {
            if(arr[i] == 0 && arr[n - i] == 0 && (n - i) % 2 != 0)
            {
                ptr = i;
                break;
            }
        }
        if(n == 0)
            break;
        if(ptr == 0)
            printf("Goldbach's conjecture is wrong.\n");
        else
        {
            printf("%d = %d + %d\n", n, ptr, n - ptr);
        }
    }while(n != 0);

    return 0;
}
