//============================================================
// 標頭檔
//============================================================
#include <stdio.h>
//============================================================
// 主程式
//============================================================
int main()
{
//字串S
char strCodeS[99];
//字串T
char strCodeT[99];
//暫存字串T的位置
int iCodeTPosition;
//偵測空白字元的旗標
bool bFlag = false;
//搜尋用的位置變數
int iIndex;
int i;//Loop Used

//所有資料先由字串S先接收
while (gets_s(strCodeS))
    {
    // 資料歸零
    bFlag = false;
    iCodeTPosition = 0;
    iIndex = 0;

    //遍歷字串S，整段會將字串S空白後的內容丟入字串T
    for (i = 0; i < sizeof(strCodeS); i++)
        {
        //將字元轉程ASCII
        strCodeS[i] = (int)strCodeS[i];
        //偵測到空白字元？
        if (strCodeS[i] == 32)
            bFlag = true;
        else
            strCodeT[i] = 0;
        //偵測到空白字元後，開始將字串T從字串S中取出
        if (bFlag)
            {
            //判斷不合理的ASCII碼
            if (strCodeS[i] < 64 || strCodeS[i] > 123)
                strCodeS[i] = 0;
            //將字串S的字元丟入字串T（沒有push語法很討厭）
            strCodeT[iCodeTPosition - 1] = strCodeS[i];
            //將字串S的位置資料清掉
            strCodeS[i] = 0;
            //字串T的位置移置下一個
            iCodeTPosition += 1;
            }
        }
    //再利用一下這個旗標，做最終結果的判斷（歸零）
    bFlag = false;
    //搜尋字串T
    for (i = 0; i < sizeof(strCodeT); i++)
        {
        //如果字串T找到字跟字串S一致
        if (strCodeS[iIndex] == strCodeT[i])
            iIndex += 1;
        //而且還把字串S跑完，就代表字串S在字串T中
        if (strCodeS[iIndex] == 0)
            bFlag = true;
        }
    //輸出結果
    if (bFlag)
        printf("Yes\n");
    else
        printf("No\n");
    }
return 0;
}