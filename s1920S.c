#include <stdio.h>
#include <stdlib.h>

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int m_search(int *arr, int size, int data)
{
    int left = 0;
    int right = size - 1;
    int mid = (left + right) / 2;
    for(int i = size; i >= 1; i /= 2)
    {
        if(arr[mid] == data)
            return 1;
        else if(arr[mid] > data)
        {
            right = mid;
            mid = (left + right) / 2;
        }
        else if(arr[mid] < data)
        {
            left = mid + 1;
            mid = (left + right) / 2;
        }
    }
    return 0;
}

int main(void)
{
    int n, m;
    int *nArr;
    int *mArr;

    scanf("%d", &n);
    nArr = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &nArr[i]);
    }
    qsort(nArr, n, sizeof(int), compare);

    scanf("%d", &m);
    mArr = (int *)malloc(sizeof(int) * m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &mArr[i]);
        printf("%d\n", m_search(nArr, n, mArr[i]));
    }
    free(nArr);
    free(mArr);
    return 0;
}
