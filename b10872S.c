#include <stdio.h>

int rec(int nb)
{
    if (nb == 0)
        return 1;
    return nb * rec(nb - 1);
}

int main(void)
{
    int nb;

    scanf("%d", &nb);
    printf("%d", rec(nb));
}