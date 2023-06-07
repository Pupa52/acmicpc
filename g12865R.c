#include <stdio.h>
#include <stdlib.h>

typedef struct _object{
    int weight;
    int value;
}Object;

typedef struct _state{
    int current_weight;
    int current_dep;
}State;

int rec(int max_dep, int max_weight, Object *arr, State *state)
{
    if(state->current_dep == max_dep && state->current_weight)

    rec()
}

int main(void)
{
    int n, k;
    Object *arr;
    State state = { 0, 0 };

    scanf("%d %d", &n, &k);
    arr = (Object *)malloc(sizeof(Object) * k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].weight, &arr[i].value);
    }
    rec(n, k, arr, state);
    free(arr);
    return 0;
}