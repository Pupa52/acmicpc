#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int sum = 0;
    char *buffer;

    scanf("%d", &n);
    buffer = (char *)malloc(sizeof(char) * n + 1);
    scanf("%s", buffer);
    for(int i = 0; i < n; i++)
    {
        if (buffer[i] >= '0' && buffer[i] <= '9')
            sum += (buffer[i] - '0');
    }
    printf("%d", sum);
    return 0;
}