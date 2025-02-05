#include <stdio.h>
#include <stdlib.h>

void insert(int *heap, int *size, int data)
{
    int tmp;
    *size += 1;
    heap[*size] = data;

    for (int i = *size; i > 1; i /= 2)
    {
        if (heap[i / 2] > heap[i])
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
    int tmp, data = heap[1];
    heap[1] = heap[*size];
    heap[*size] = 0x7fffffff;
    *size -= 1;

    for (int i = 1; i * 2 <= *size;)
    {
        if (heap[i] < heap[i * 2] && heap[i] < heap[i * 2 + 1])
            break;
        else
        {
            if (heap[i * 2] <= heap[i * 2 + 1])
            {
                tmp = heap[i * 2];
                heap[i * 2] = heap[i];
                heap[i] = tmp;
                i = i * 2;
            }
            else
            {
                tmp = heap[i * 2 + 1];
                heap[i * 2 + 1] = heap[i];
                heap[i] = tmp;
                i = i * 2 + 1;
            }
        }
    }
    return data;
}

int main(void)
{
    int n, data, heap_size = 0;
    int *min_heap;

    scanf("%d", &n);
    min_heap = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n; i++)
    {
        min_heap[i] = 0x7fffffff;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        if (data == 0)
            if(heap_size == 0)
                printf("0\n");
            else
                printf("%d\n", delete(min_heap, &heap_size));
        else
            insert(min_heap, &heap_size, data);
    }
}