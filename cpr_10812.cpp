#include <stdio.h>

int main()
{
int iTestCase = 0;
int iSum = 0;
int iDifference = 0;
int iTeamScoresA = 0;
int iTeamScoresB = 0;
int i = 0;//Loop used;

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