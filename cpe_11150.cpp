//============================================================
// 標頭檔
//============================================================
#include <stdio.h>
//============================================================
// GET_BORROW
// 這個巨集函數可以取得應該貸入的量
// 取得往上加，接近的 3 的倍數
// 但是除起來餘數為零，則代表本身即 3 的倍數，應傳回 0
//============================================================
// 例子：假設有 7 個空瓶
// Step.1 : 7 % 3 = 1
// Step.2 : 3 - 1 = 2
// Step.3 : 貸入 2 個空瓶
//------------------------------------------------------------
// 例子：假設有 9 個空瓶
// Step.1 : 9 % 3 = 0
// Step.2 : 3 - 0 = 3
// Step.3 : 答案不符所需
// Step.4 : 貸入 0 個空瓶
//============================================================
#define GET_BORROW(x) (3 - (x) % 3) == 3 ? 0 : (3 - (x) % 3)
//============================================================
// 主程式
//============================================================
int main()
{
int iBottleTemp;   // 每輪空瓶數
int iColaTemp;     // 每輪可樂數
int iBorrowTemp;   // 每輪借貸數
int iColaCount;    // 總可樂數

while(scanf_s("%d",&iColaCount) != EOF)
    {
    // 初始化
    iColaTemp = 0;
    iBorrowTemp = 0;
    // 有的直接喝
    iBottleTemp  = iColaCount;

    // 兩個的話，借一個是可以還清的。
    while(iBottleTemp >= 2)
        {
        // 有借有還
        iBottleTemp -= iBorrowTemp;
        // 還完再借
        iBorrowTemp = GET_BORROW(iBottleTemp);
        // 禁止超貸
        if (iBottleTemp < iBorrowTemp)
            break;
        // 貸入瓶數
        iBottleTemp += iBorrowTemp;
        // 空瓶兌換
        iBottleTemp /= 3;
        // 統計數量
        iColaTemp = iBottleTemp;
        // 喝完空瓶
        iColaCount += iColaTemp;
        }
    // 顯示結果
    printf("%d\n", iColaCount);
    }
return 0;
}