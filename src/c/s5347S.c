#include <stdio.h>

int gcd(int a, int b)
{
    if(a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int main(void)
{
    int n, a, b;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        scanf("%d", &b);
        
        printf("%lld\n", ((long long int)a * b) / gcd(a, b));
    }
    
    return 0;
}