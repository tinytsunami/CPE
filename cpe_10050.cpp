//============================================================
// 標頭檔
//============================================================
#include <iostream>
//============================================================
// 命名空間
//============================================================
using namespace std;
//============================================================
// 主程式
//============================================================
int main()
{
int iCase;            //測資數
int iDay;             //天數
int iPartyCount;      //政黨數量
int *ipParty;         //儲存政黨開會表
short int siWeek;     //迴圈使用（紀錄星期）
int i, j;             //迴圈使用
int iCount;           //紀錄答案

cin >> iCase;
while (iCase > 0)
    {
    //initialize
    iCount = 0;
    cin >> iDay;
    cin >> iPartyCount;

    ipParty = new int[iPartyCount];
    for (i = 0; i < iPartyCount; i++)
        cin >> ipParty[i];

    //process
    for (i = 1; i < (iDay + 1); i++)
        {
        siWeek = i % 7;
        if (siWeek != 6 && siWeek != 0)
            {
            for (j = 0; j < iPartyCount; j ++)
                {
                if (i % ipParty[j] == 0)
                    {
                    iCount++;
                    break;
                    }
                }
            }
        }

    cout << iCount << endl;
    iCase--;
    }
return 0;
}