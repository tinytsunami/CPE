//============================================================
// 標頭檔
//============================================================
#include <stdio.h>
//============================================================
// 比對計算當行字數
// Input  word    : 字母
// Input  page[]  : 字串（行）
// Output iCount  : 字母在字串中出現的次數
//============================================================
int wordCount(char word, char page[])
{
int iCount;
int i;//Loop Used

for (i = 0; i < 99; i++)
    if (page[i] == word || page[i] == (char)((int)word+32))
        iCount += 1;
return iCount;
}
//============================================================
// 主程式
//============================================================
int main(void)
{
int iLineCount;             //總行數
int iWordCount[26];         //字母的總數
int strSaveString[26][2];   //整理後的字母陣列（[0]=>ASCII、[1]=>計數）
int iMaxNumber;             //用來儲存最大數量的字母個數
char strPage[30][99];       //用來暫存題目的每一行文字
int i;                      //Loop Used
int j;                      //Loop Used

//由於測資易發生雜訊，故將陣列規零
for (i = 0; i < 26; i++)
    iWordCount[i] = 0;
//輸入行數
scanf_s("%d", &iLineCount);
//將每一行資料導入
for (i = 0; i <= iLineCount; i++)
    gets_s(strPage[i]);
//檢查每一個字母
for (i = 0; i < 26; i++)
    {
    //檢查每一行內容
    for (j = 0; j <= iLineCount; j++)
        iWordCount[i] += wordCount((char)(65 + i), strPage[j]);
    //確認本字母有出現
    if (iWordCount[i] > 0)
        {
        //在字母陣列中存字母本身的ASCII
        strSaveString[i][0] = (65 + i);
        //在字母陣列中存字母總數
        strSaveString[i][1] = iWordCount[i];
        //如果出現數量最大，則記錄
        if (iWordCount[i] > iMaxNumber)
            iMaxNumber = iWordCount[i];
        }
    }
//由最大出的字母開始遞減，由大到小顯示
for (i = iMaxNumber; i > 0; i--)
    for (j = 0; j < 26; j++)
        if (strSaveString[j][1] == i)
            printf("%c %d\n", (char)strSaveString[j][0], (char)strSaveString[j][1]);
return 0;
}