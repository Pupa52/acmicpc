#include <stdio.h>

int main(void)
{
    int n, five = 0, two = 0, ans;

    scanf("%d", &n);
    for(int i = n; i > 0; i--)
    {
        for(int j = i; j % 5 == 0 && j > 1; j /= 5) five++;
        for(int j = i; j % 2 == 0 && j > 1; j /= 2) two++;
    }
    ans = five < two ? five : two;
    printf("%d", ans);
    return 0;
}
