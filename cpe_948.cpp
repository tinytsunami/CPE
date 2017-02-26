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
int iCase;        //測資數量
int iDECBase;     //十進位數
int iFIBMax;      //費波那契數列的最大位
int iFIBMaxPre;   //計算費波那契數列用
int iTemp;        //暫存用

cin >> iCase;
while (iCase > 0)
    {
    cin >> iDECBase;

    //find max of FIB_BASE
    iFIBMax = iFIBMaxPre = 1;
    while ((iFIBMax + iFIBMaxPre) <= iDECBase)
        {
        iTemp = iFIBMax;
        iFIBMax = iFIBMax + iFIBMaxPre;
        iFIBMaxPre = iTemp;
        }

    //output
    cout << iDECBase << " = ";
    while (iDECBase > 0 || iFIBMaxPre > 0)
        {
        if (iDECBase >= iFIBMax)
            {
            cout << 1;
            iDECBase -= iFIBMax;
            }
        else
            cout << 0;
        iTemp = iFIBMaxPre;
        iFIBMaxPre = iFIBMax - iFIBMaxPre;
        iFIBMax = iTemp;
        }

    cout << " (fib)" << endl;
    iCase--;
    }
return 0;
}