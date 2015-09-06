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
int iCountTest;
//數字A（Min）
int iNumberA;
//數字B（Max）
int iNumberB;
//最終結果
int iAnser;
int i;//Loop Used
int j;//Loop Used

//輸入測資數
scanf_s("%d",&iCountTest);
//跑每個測資
for (i = 0; i < iCountTest; i++)
    {
    //先歸零才安全
    iAnser = 0;
    //輸入數字A、B
    scanf_s("%d", &iNumberA);
    scanf_s("%d", &iNumberB);
    //從數字A到數字B
    for (j = iNumberA;j<= iNumberB; j++)
        {
        //奇數則加
        if (j % 2)
            iAnser += j;
        }
    //輸出測資答案
    printf("Case %d: %d\n", (i+1), iAnser);
    }
return 0;
}