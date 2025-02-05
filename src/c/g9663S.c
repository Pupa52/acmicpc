#include <stdio.h>
#include <stdlib.h>

int c_abs(int a, int b)
{
    if (a > b)
        return (a - b);
    else
        return (b - a);
}

void nqueen(int current_q, int last_q, int *solution, int *cnt)
{
    int flag = 0;

    if (current_q == last_q)
    {
        *cnt += 1;
        return;
    }
    for(int y = 0; y < last_q; y++)
    {
        flag = 0;
        for(int x = 0; x < current_q; x++)
        {
            if (solution[x] == y || c_abs(solution[x], y) == c_abs(current_q, x))
                flag = 1;
        }
        if (flag == 0)
        {
            solution[current_q] = y;
            nqueen(current_q + 1, last_q, solution, cnt);
        }
    }
}

int main(void)
{
    int nq;
    int *solution;
    int cnt = 0;

    scanf("%d", &nq);
    solution = (int *)malloc(sizeof(int) * nq);
    nqueen(0, nq, solution, &cnt);
    free(solution);
    printf("%d", cnt);
    return 0;
}