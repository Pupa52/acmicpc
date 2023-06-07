#include <stdio.h>

int main(void)
{
    char s[101] = { 0, };
    char tmp;
    char alpha[26];
    int index = 0;

    scanf("%s", s);
    for(int i = 0; i < 26; i++)
    {
        alpha[i] = 30;
    }
    while(s[index] != '\0')
    {
        tmp = s[index] - 'a';
        if(alpha[tmp] == 30)
            alpha[tmp] = index;
        index++;
    }
    for(int i = 0; i < 26; i++)
    {
        if(alpha[i] == 30)
            alpha[i] = -1;
        printf("%d ", alpha[i]);
    }
    return 0;
}