#include <stdio.h>

int main(void)
{
    char buffer[16];
    char res[8] = {0, };
    int index = 0;

    fgets(buffer, 16, stdin);
    for(int i = 0; i < 16; i++)
    {
        if (buffer[i] == '\0')
            break;
        if (buffer[i] != ' ')
        {
            res[index] = buffer[i];
            index++;
        }
    }
    if (res[0] == '1')
    {
        for (int i = 0; i < 8; i++)
        {
            if (res[i] != (i + 1 + '0'))
            {
                printf("mixed");
                return 0;
            }
        }
        printf("ascending");
    }
    else if (buffer[0] == '8')
    {
        for (int i = 0; i < 8; i++)
        {
            if (res[i] != (8 - i + '0'))
            {
                printf("mixed");
                return 0;
            }
        }
        printf("descending");
    }
    else
        printf("mixed");
    return 0;
}
