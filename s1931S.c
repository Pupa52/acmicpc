#include <stdio.h>
#include <stdlib.h>

typedef struct _meeting
{
    int start;
    int end;
}Meeting;

int compare(const void *first, const void *second)
{
    if(((Meeting *)first)->end > ((Meeting *)second)->end)
        return 1;
    else if(((Meeting *)first)->end < ((Meeting *)second)->end)
        return -1;
    else
    {
        if(((Meeting *)first)->start > ((Meeting *)second)->start)
            return 1;
        else if(((Meeting *)first)->start < ((Meeting *)second)->start)
            return -1;
        else
            return 0;
    }
}

int main(void)
{
    int n, i, j, cnt;
    Meeting *arr;
    Meeting tmp;

    scanf("%d", &n);
    arr = (Meeting *)malloc(sizeof(Meeting) * n);
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }
    qsort(arr, n, sizeof(Meeting), compare);
    j = 0;
    cnt = 0;
    for(i = 0; i < n; i++)
    {

        if(arr[i].start >= j)
        {
            cnt += 1;
            j = arr[i].end;
        }
    }
    printf("%d", cnt);
    free(arr);
    return 0;
}