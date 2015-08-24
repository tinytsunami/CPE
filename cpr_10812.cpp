#include <stdio.h>

int main()
{
int iTestCase;
int iSum;
int iDifference;
int iTeamScoresA;
int iTeamScoresB;
int i;//Loop used;

scanf_s("%d", &iTestCase);
for (i = 0; i < iTestCase; i++)
    {
    scanf_s("%d %d", &iSum, &iDifference);
    if (iDifference > iSum)
        {
        printf("impossible\n");
        continue;
        }
    iTeamScoresA = (iSum + iDifference) / 2;
    iTeamScoresB = (iSum - iDifference) / 2;
    if (iTeamScoresA + iTeamScoresB == iSum)
        if (iTeamScoresA - iTeamScoresB == iDifference)
            printf("%d %d\n", iTeamScoresA, iTeamScoresB);
        else
            printf("impossible\n");
    else
        printf("impossible\n");
    }
return 0;
}