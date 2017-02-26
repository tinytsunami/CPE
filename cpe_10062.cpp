//============================================================
// 標頭檔
//============================================================
#include <iostream>
#include <string>
//============================================================
// 命名空間
//============================================================
using namespace std;
//============================================================
// 記錄字數的結構
//============================================================
struct Item
    {
    char cASCII = '\0';       //字
    short int siCount = 0;    //數量
    };
//============================================================
// 交換兩個字
// input : 兩個單位
// output: 不回傳
//============================================================
void vSwapItem (Item &itemA, Item &itemB)
{
Item itemTemp;
itemTemp = itemA;
itemA = itemB;
itemB = itemTemp;
}
//============================================================
// 主程式
//============================================================
int main()
{
string strText;     //輸入字串
Item siASCII[128];  //所有字元的數的列表
Item itemTemp;      //做暫存用的
short int siIndex;  //迴圈用的
bool bRepeat;       //重複標示
bool bStart;        //用於結尾的換行

bStart = true;
while (getline(cin, strText))
    {
    //next line
    if (bStart == false)
        cout << endl;
    
    //initialize
    for (Item &item : siASCII)
        item = Item();

    //calc
    siIndex = 0;
    for (char &c : strText)
        {
        bRepeat = false;
        //repeat?
        for (Item &item : siASCII)
            if (item.cASCII == c)
                {
                item.siCount++;
                bRepeat = true;
                }
        //no repeat
        if (bRepeat == false)
            {
            siASCII[siIndex].cASCII = c;
            siASCII[siIndex].siCount++;
            siIndex++;
            }
        }

    //sort
    for (Item &i : siASCII)
        for (Item &j : siASCII)
            if (i.siCount < j.siCount)
                vSwapItem(i, j);
            else
                if (i.siCount == j.siCount)
                    if (i.cASCII > j.cASCII)
                        vSwapItem (i, j);

    //result
    for (siIndex = 0; siIndex < 128; siIndex++)
        if (siASCII[siIndex].siCount > 0)
            cout << (int)siASCII[siIndex].cASCII << " " << siASCII[siIndex].siCount << endl;

    bStart = false;
    }
return 0;
}