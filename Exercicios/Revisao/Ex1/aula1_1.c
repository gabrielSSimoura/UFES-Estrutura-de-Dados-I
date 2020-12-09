#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var1, var2, var3, var4;
    int *pt1, *pt2, *pt3, *pt4;

    pt1 = &var1;
    pt2 = &var2;
    pt3 = &var3;
    pt4 = &var4;

    printf("Digite 4 numeros: ");
    scanf("%d %d %d %d", &var1, &var2, &var3, &var4);

    *pt1 += 10;
    *pt2 = *pt1 + 10;
    *pt3 = *pt2 + *pt1;
    *pt4 = *pt3 + *pt2;

    printf("\n%d %d %d %d\n", var1, var2, var3, var4);

    return 0;
}