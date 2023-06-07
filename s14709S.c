#include <stdio.h>

int main(void)
{
    int n, f1, f2;
    int solution[3] = { 0, };

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &f1, &f2);
        if((f1 == 1 && f2 == 3) || (f1 == 3 && f2 == 1))
            solution[0] = 1;
        else if((f1 == 1 && f2 == 4) || (f1 == 4 && f2 == 1))
            solution[1] = 1;
        else if((f1 == 4 && f2 == 3) || (f1 == 3 && f2 == 4))
            solution[2] = 1;
        else
        {
            solution[0] = -1;
            break;
        }
    }
    if(solution[0] == 1 && solution[1] == 1 && solution[2] == 1)
        printf("Wa-pa-pa-pa-pa-pa-pow!");
    else
        printf("Woof-meow-tweet-squeek");
    return 0;
}