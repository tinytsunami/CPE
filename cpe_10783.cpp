#include <stdio.h>

int main()
{
int iCountTest;
int iNumberA;
int iNumberB;
int iAnser;
int i;//Loop Used
int j;//Loop Used

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