#include <stdio.h>

int main(void)
{
    int t;
    int r;
    int j;
    char s[21];

    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d %s", &r, s);
        j = 0;
        while(s[j] != '\0')
        {
            for(int k = 0; k < r; k++)
            {
                printf("%c", s[j]);
            }
            j++;
        }
        printf("\n");
    }
}