//============================================================
// 標頭檔
//============================================================
#include <stdio.h>
//============================================================
// 主程式
//============================================================
int main()
{
//測資數
int iTestCase;
//和
int iSum;
//差
int iDifference;
//分數A
int iTeamScoresA;
//分數B
int iTeamScoresB;
int i;//Loop used;

//數入測資數
scanf_s("%d", &iTestCase);
//跑測資
for (i = 0; i < iTestCase; i++)
    {
    //輸入分數和、分數差
    scanf_s("%d %d", &iSum, &iDifference);
    //差大於和，不存在
    if (iDifference > iSum)
        {
        //檯面上覆蓋答案
        printf("impossible\n");
        //直接去下筆測資
        continue;
        }
    // 推導來的算法
    // S = Sum
    // D = Difference
    // ========================
    //    A + B   = S
    // +) A - B   = D
    // -------------------
    //   2A       = S + D
    // ========================
    //    A + B   = S
    // -) A - B   = D
    // -------------------
    //       2B   = S - D
    // ========================
    iTeamScoresA = (iSum + iDifference) / 2;
    iTeamScoresB = (iSum - iDifference) / 2;
    // 驗算，並輸出
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