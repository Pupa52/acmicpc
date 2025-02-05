#include <stdio.h>

int is_prime(int number)
{
    if(number < 2)
        return 0;
    for(int i = 2; i <= number / i; i++)
    {
        if(number % i == 0)
            return 0;
    }
    return 1;
}

void rec(int startNum, int endNum, int step, int n, int *flag)
{
    if(n == 0)
    {
        *flag = 1;
        return;
    }
    for(int i = 0; i < 10; i++)
    {
        if(is_prime(startNum / step))
            rec(startNum, endNum, step / 10, n - 1, flag);
        if(*flag == 1)
        {
            printf("%d\n", startNum);
            *flag = 0;
        }
        startNum += step;
    }
}

int main(void)
{
    int n, step, startNum, endNum, flag = 0;

    scanf("%d", &n);
    startNum = 1;
    for(int i = 0; i < n - 1; i++)
    {
        startNum = startNum * 10;
    }
    endNum = 1;
    for(int i = 0; i < n; i++)
    {
        endNum = endNum * 10;
    }
    step = startNum;
    rec(startNum, endNum, step, n, &flag);
    return 0;
}
