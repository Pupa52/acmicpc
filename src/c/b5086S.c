#include <stdio.h>

int main(void)
{
    int n = 1, m = 1;

    while(1)
    {
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0)
            break;
        if(n < m)
        {
            if(m % n == 0)
                printf("factor\n");
            else
                printf("neither\n");
        }
        else
        {
            if(n % m == 0)
                printf("multiple\n");
            else
                printf("neither\n");
        }
    }
    return 0;
}