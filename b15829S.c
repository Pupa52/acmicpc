#include <stdio.h>
#include <stdlib.h>

#define PRIME 1234567891
#define R 31

int main(void)
{
    unsigned long res = 0;
    unsigned long pow = 1;
    int tmp;
    int l;
    char *str;

    scanf("%d", &l);
    str = (char *)malloc(sizeof(char) * l + 1);
    scanf("%s", str);

    for(int i = 0; i < l; i++)
    {
        tmp = str[i] - 'a' + 1;
        res = res + (tmp * pow);
        pow = (pow * R) % PRIME;
    }
    printf("%ld", res % PRIME);
    return 0;
}