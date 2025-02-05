#include <stdio.h>
#include <stdlib.h>

void rec(int max_dep, int lenght, char *alpha, char *solution, int current_dep, int index)
{
    if(current_dep == max_dep)
    {
        int flag = 0;
        int cnt = 0;
        for(int i = 0; i < max_dep; i++)
        {
            if (!(solution[i] == 'a' || solution[i] == 'i'
            || solution[i] == 'o' || solution[i] == 'u' || solution[i] == 'e'))
            {
                cnt += 1;
            }
            else
            {
                flag = 1;
            }
            if (cnt > 1 && flag == 1)
                break ;
        }
        if (cnt > 1 && flag == 1)
        {
            for(int i = 0; i < max_dep; i++)
            {
                printf("%c", solution[i]);
            }
            printf("\n");
        }
        return ;
    }
    for(int i = index; i < lenght - (max_dep - current_dep) + 1; i++)
    {
        solution[current_dep] = alpha[i];
        rec(max_dep, lenght, alpha, solution, current_dep + 1, index + 1);
        index++;
    }
}

int main(void)
{
    int l, c;
    int i = 0;
    char *alpha;
    char *solution;
    char tmp;

    scanf("%d %d", &l, &c);
    solution = (char *)malloc(sizeof(char) * l);
    alpha = (char *)malloc(sizeof(char) * c);

    while(i < c)
    {
        scanf("%c", &alpha[i]);
        if (alpha[i] != ' ' && alpha[i] != '\n')
            i++;
    }

    for(i = 0; i < c; i++)
    {
        for(int j = 0; j < c - 1; j++)
        {
            if (alpha[j] > alpha[j + 1])
            {
                tmp = alpha[j];
                alpha[j] = alpha[j + 1];
                alpha[j + 1] = tmp;
            }
        }
    }

    rec(l, c, alpha, solution, 0, 0);
    free(alpha);
    free(solution);
    return 0;
}