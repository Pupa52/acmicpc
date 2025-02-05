#include <stdio.h>

int main(void)
{
    int heru, ausar, auset;

    heru = 1;
    ausar = 1;
    auset = 1;
    while(1)
    {
        scanf("%d %d %d", &ausar, &auset, &heru);
        if(heru == 0 && ausar == 0 && auset == 0)
            break;
        heru *= heru;
        ausar *= ausar;
        auset *= auset;
        if(heru == (ausar + auset))
            printf("right\n");
        else if(ausar == (heru + auset))
            printf("right\n");
        else if(auset == (ausar + heru))
            printf("right\n");
        else
            printf("wrong\n");
    }
    return 0;
}