#include <stdio.h>

int main()
    {
    int iCountTest = 0;
    int iNumberA = 0;
    int iNumberB = 0;
    int iAnser = 0;
    int i = 0;//Loop Used
    int j = 0;//Loop Used
    scanf_s("%d",&iCountTest);
    for (i = 0; i < iCountTest; i++)
        {
        iAnser = 0;
        scanf_s("%d", &iNumberA);
        scanf_s("%d", &iNumberB);
        for (j = iNumberA;j<= iNumberB; j++)
            {
            if (j % 2)
                iAnser += j;
            }
        printf("Case %d: %d\n", (i+1), iAnser);
        }
    return 0;
    }