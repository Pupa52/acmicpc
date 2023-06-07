#include <stdio.h>
#include <stdlib.h>

void insert(int *heap, int *size, int data)
{
    int tmp;
    *size += 1;
    heap[*size] = data;

    for (int i = *size; i > 1; i /= 2)
    {
        if (heap[i / 2] < heap[i])
        {
            tmp = heap[i / 2];
            heap[i / 2] = heap[i];
            heap[i] = tmp;
        }
        else
            break;
    }
}

int delete(int *heap, int *size)
{
    int tmp, result = heap[1];
    heap[1] = heap[*size];
    heap[*size] = -1;
    *size -= 1;

    for (int i = 1; i * 2 <= *size;)
    {
        if (heap[i] > heap[i * 2] && heap[i] > heap[i * 2 + 1])
            break;
        else if (heap[i * 2] > heap[i * 2 + 1])
        {
            tmp = heap[i];
            heap[i] = heap[i * 2];
            heap[i * 2] = tmp;
            i = i * 2;
        }
        else
        {
            tmp = heap[i];
            heap[i] = heap[i * 2 + 1];
            heap[i * 2 + 1] = tmp;
            i = i * 2 + 1;
        }
    }
    return result;
}

int main(void)
{
    int n, data, heap_size = 0;
    int *nn;

    scanf("%d", &n);
    nn = (int *)malloc(sizeof(int) * ((n * n) + 1));
    for(int i = 1; i < n*n + 1; i++)
    {
        scanf("%d", &data);
        insert(nn, &heap_size, data);
    }
    for(int i = 0; i < n; i++)
    {
        data = delete(nn, &heap_size);
    }
    printf("%d", data);
    free(nn);
    return 0;
}