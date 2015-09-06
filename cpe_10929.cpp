//============================================================
// 標頭檔
//============================================================
#include <stdio.h>
//============================================================
// 主程式
//============================================================
int main(void)
{
// 把數字當字串的字元陣列
char strNumber[30];
// 把數字當數字陣列的數組
int arriNumber[30];
// 分別紀錄奇數位和、偶數位和
int iNumberSumA;
int iNumberSumB;
// 紀錄奇位和、偶位和的差
int iNumberDifference;
int i;//Loop used

// 先把數字拿來
while (scanf_s("%s", strNumber, 30))
    {
    // 是零就結束
    if (strNumber[0] == '0')
       break;
    // 歸零一下
    iNumberSumA = 0;
    iNumberSumB = 0;
    // 遍歷字元陣列
    for (i = 0; i < sizeof(strNumber); i++)
        {
        // 變成ASCII並塞到另一個陣列
        arriNumber[i] = (int)strNumber[i];
        // 符合數字的範圍
        if (arriNumber[i] > 47 && arriNumber[i] < 58)
            {
            // 從ASCII調整到正確的數字
            arriNumber[i] -= 48;
            // 本數字大於零
            if (arriNumber[i] > 0)
                {
                // 加到奇、偶數位的和裡
                if (i % 2)
                    iNumberSumA += arriNumber[i];
                else
                    iNumberSumB += arriNumber[i];
                }
            }
        }
    // 取得奇、偶數和的差
    iNumberDifference = (iNumberSumA - iNumberSumB) * (iNumberSumA >= iNumberSumB ? 1 : -1);
    // 判斷是否為11的倍數
    if (iNumberDifference == 0 || iNumberDifference == 11)
        printf("%s is a multiple of 11.\n", strNumber);
    else
        printf("%s is not a multiple of 11.\n", strNumber);
    // 在下筆測資前，先歸零一下
    for (i = 0; i < sizeof(strNumber); i++)
        strNumber[i] = '0';
    }
return 0;
}

