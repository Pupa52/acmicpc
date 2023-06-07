#include <stdio.h>

int main(void)
{
    int a, b, cnt;

    scanf("%d %d", &a, &b);
    cnt = 1;
    
    while(1)
    {
        if(b == a)
            break;
        else if(b % 10 == 1)
        {
            b /= 10;
            cnt++;
        }
        else if(b % 2 == 0 && b > 0)
        {
            b /= 2;
            cnt++;
        }
        else
        {
            cnt = -1;
            break;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
