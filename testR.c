#include <stdio.h>
#include <stdlib.h>

int check_p(char *p, int *rev_flag, int *front_d, int *end_d)
{
    int index = 0;

    while(p[index] != '\0')
    {
        if(p[index] == 'R')
        {
            if(*rev_flag == 0)
                *rev_flag = 1;
            else
                *rev_flag = 0;
        }
        else if(p[index] == 'D')
        {
            if(*rev_flag == 0)
                *front_d += 1;
            else
                *end_d -= 1;
        }
        index++;
    }
    if (*front_d > *end_d)
        return -1;
    else
        return 1;
}

void print_arr(char *arr, int n, int rev_flag, int front_d, int end_d)
{
    int *res_arr = (int *)malloc(sizeof(int) * n);
    int index = 0, jndex = 0;

    for(int i = 0; i < n; i++) res_arr[i] = 0;

    while(arr[index] != '\0')
    {
        if(arr[index] >= '0' && arr[index] <= '9')
        {
            while(arr[index] >= '0' && arr[index] <= '9')
            {
                res_arr[jndex] = res_arr[jndex] * 10 + (int)(arr[index] - '0');
                index++;
            }
            jndex++;
        }
        else
            index++;
    }
    if(rev_flag == 0)
    {
        printf("[");
        for(int i = front_d; i < end_d; i++)
        {
            printf("%d", res_arr[i]);
            if(i != end_d - 1)
                printf(",");
        }
        printf("]\n");
    }
    else
    {
        printf("[");
        for(int i = end_d - 1; i >= front_d; i--)
        {
            printf("%d", res_arr[i]);
            if(i != front_d)
                printf(",");
        }
        printf("]\n");
    }
    free(res_arr);
}

int main(void)
{
    int t, n;
    char *p;
    char *arr;

    int rev_flag, front_d, end_d;

    scanf("%d", &t);

    for(int i = 0; i < t; i++)
    {
        p = (char *)malloc(sizeof(char) * 100001);
        scanf("%s", p);

        scanf("%d", &n);

        arr = (char *)malloc(sizeof(char) * 300);
        scanf("%s", arr);

        rev_flag = 0;
        front_d = 0;
        end_d = n;

        if(check_p(p, &rev_flag, &front_d, &end_d) == -1)
        {
            printf("error\n");
            continue;
        }
        print_arr(arr, n, rev_flag, front_d, end_d);
    }
    free(arr);
    free(p);
    return 0;
}